import tkinter as tk
from tkinter import messagebox
from ttkbootstrap import *
import ttkbootstrap as tb
import pickle
from funclib import *
import copy

import login
from paraslib import *
import langpack

from platform import system as sys
_os = sys()
if _os == "Windows":
    zoomfactor = 1.8
    from ctypes import windll
    windll.shcore.SetProcessDpiAwareness(1)
else:
    zoomfactor = 1

class mainpage:
    lang = langpack.EN
    lang_var_str = "EN"
    serial_status = False
    pacing_mode = ""
    rootw = int(800*zoomfactor)
    rooth = int(560*zoomfactor)
    presets = {}
    showing_egram = False
    t: LoadSerialEgram_debug
    quit_code = 0
    mode = "MAIN"
    serial_port = ""

    def init_self_pref(self):
        try:
            with open('userpref.pkl', 'rb') as obj:
                userpref = pickle.load(obj)
                self.loginname = userpref[self.userid]["loginname"]
                self.lang_var_str = userpref[self.userid]["lang_var_str"]
                match self.lang_var_str:
                    case "ZH_HK":
                        self.lang = langpack.CN
                    case "EN":
                        self.lang = langpack.EN
                self.presets = userpref[self.userid]["presets"]
        except FileNotFoundError:
            with open('userpref.pkl', 'wb') as obj:
                userpref = {self.userid: {
                    "loginname": self.loginname,
                    "lang_var_str": "EN",
                    "lang": "langpack.EN",
                    "presets": {}
                }}
                pickle.dump(userpref, obj, pickle.HIGHEST_PROTOCOL)
        except KeyError:
            with open('userpref.pkl', 'rb') as obj:
                userpref = pickle.load(obj)
            userpref[self.userid] = {
                    "loginname": self.loginname,
                    "lang_var_str": "EN",
                    "lang": "langpack.EN",
                    "presets": {}
                }
            with open('userpref.pkl', 'wb') as obj:
                pickle.dump(userpref, obj, pickle.HIGHEST_PROTOCOL)

    def sync_self_pref(self):
        with open('userpref.pkl', 'rb') as obj:
            pref = pickle.load(obj)
        with open('userpref.pkl', 'wb') as obj:
            match self.lang_var_str:
                    case "ZH_HK":
                        lang = "langpack.CN"
                    case "EN":
                        lang = "langpack.EN"
            pref[self.userid] = {
                "loginname": self.loginname,
                "lang_var_str": self.lang_var_str,
                "lang": lang,
                "presets": self.presets
            }
            pickle.dump(pref, obj, pickle.HIGHEST_PROTOCOL)

    class AskString:
        return_val = None
        def __init__(chd, par, title, prompt, btn1_text, btn2_text):
            chd.par = par
            chd.root = tk.Toplevel(par.root)
            # chd.root.config(bg="#323232")
            center(chd.root)
            chd.root.title(title)
            chd.root.minsize(int(320*zoomfactor), int(140*zoomfactor))
            chd.root.maxsize(int(320*zoomfactor), int(140*zoomfactor))
            prompt_label = Label(chd.root, text=prompt, font="Helvetica 20")
            chd.str_entry = Entry(chd.root)
            btns_frame = Frame(chd.root)
            yes_btn = Button(btns_frame, text=btn1_text, command=lambda : chd.yes())
            no_btn = Button(btns_frame, text=btn2_text, command=lambda : chd.no())
            prompt_label.pack(side="top", fill="x", expand=True, padx=20, pady=5)
            chd.str_entry.pack(side="top", fill="x", expand=True, padx=25, pady=5)
            btns_frame.pack(side="top", fill="x", expand=True, padx=10, pady=5)
            yes_btn.pack(side="left", fill="x", expand=True, padx=10, pady=5)
            no_btn.pack(side="right", fill="x", expand=True, padx=10, pady=5)
            chd.root.bind_all("<Return>", lambda _ : chd.yes())
            chd.str_entry.focus_set()
        def yes(chd):
            entry_get = chd.str_entry.get()
            if entry_get == "" or entry_get == "_temp":
                messagebox.showwarning(chd.par.lang["NoValInTtl"], chd.par.lang["NoValInMsg"])
            else:
                chd.return_val = entry_get
                chd.root.destroy()
        def no(chd):
            chd.return_val = None
            chd.root.destroy()
        def get(chd):
            chd.root.wait_window()
            return chd.return_val

    def initroot(self):
        style = Style()
        style = Style(theme="pulse")
        self.root = style.master
        for widget in self.root.winfo_children():
            widget.destroy()
        self.root.unbind("<Return>")
        # self.root.iconbitmap("Heart.ico")
        self.root.minsize(self.rootw, self.rooth)
        center(self.root)
        # self.root.eval('tk::PlaceWindow . center')
    
    def quit(self, mode="EXIT"):
        if mode == "EXIT":
            self.quit_code = 0
            self.root.quit()
        elif mode == "PWD":
            self.quit_code = self.username
            self.root.quit()
        else:
            self.quit_code = 1
            self.root.quit()

    def __new__(self, userid, loginname, root: tk.Tk = None):
        if root == None:
            self.initroot(self)
        else:
            self.root = root
            bg = ttk.Style().lookup('TFrame', 'background')
            self.root.config(bg=bg)
            for widget in self.root.winfo_children():
                widget.destroy()
        self.root.unbind("<Return>")
        self.userid = userid
        self.loginname = loginname
        self.username = loginname
        self.init_self_pref(self)
        self.root.title(self.lang["RootTitle<"] + self.loginname + self.lang["RootTitle>"])
        
        self.root.protocol("WM_DELETE_WINDOW", lambda : self.quit(self))
        self.toolbar = Frame(self.root)
        self.toolbar.pack(fill=X, pady=15)
        self.toolbar_frame(self)
        Separator(self.root).pack(fill=X, padx=20)
        self.main_interact_f = Frame(self.root)
        self.stng_interact_f = Frame(self.root)
        self.egram_frame = Frame(self.root, height=100)
        self.pacemaker_configure_frame(self)
        print(self.presets)
        self.root.mainloop()
        print("mainloop done")
        if self.pacing_mode != "" and self.mode == "MAIN":
            self.presets["_temp"] = [self.pacing_mode]
            self.presets["_temp"] += self.get_curr_paras(self)
        self.sync_self_pref(self)
        try:
            self.t.stop()
        except:
            pass
        for widget in self.root.winfo_children():
                widget.destroy()
        return self.quit_code

    def toolbar_frame(self, stat="Main"):
        toolbar = self.toolbar
        for widget in toolbar.winfo_children():
            widget.destroy()

        if stat == "Main":
            def serial_sel_onsel(event):
                self.serial_port = event.widget.get()
            self.mode = "MAIN"
            acco_logout_btn = Button(toolbar, text=self.lang["Logout"], bootstyle="danger",
                                 command=lambda : self.quit(self, mode="LOGOUT"))
            acco_logout_btn.pack(side=RIGHT, padx=20)
            serial_sel_fram = Frame(toolbar)
            serial_sel_fram.pack(side=LEFT, padx=10)
            serial_sel_labl = Label(serial_sel_fram, text=self.lang["SelPort"])
            serial_sel_labl.pack(side=LEFT, padx=10)
            serial_selector = Combobox(serial_sel_fram, values=serial_ports())
            serial_selector.pack(side=LEFT, padx=10)
            serial_selector.bind('<<ComboboxSelected>>', serial_sel_onsel)
            serial_stat_lbl = Label(serial_sel_fram,
                                    text=self.lang["SerialConn"] if self.serial_status else self.lang["SerlDiscon"])
            serial_stat_lbl.pack(side=LEFT, padx=10)
            serial_push_btn = Button(serial_sel_fram,
                                     text=self.lang["PushPara"],
                                     command=lambda : sendSerial.sendSerial(self.serial_port,
                                                                            [self.pacing_mode, *self.get_curr_paras(self)]))
            serial_push_btn.pack(side=LEFT, padx=10)
            sftw_stings_btn = Button(toolbar, text=self.lang["Settings"], bootstyle="secondary",
                                 command=lambda : self.setting_frame(self))
            sftw_stings_btn.pack(side=RIGHT, padx=0)
            self.show_egram_btn = Button(toolbar, text=self.lang["ShowEgram"], bootstyle="success",
                                         command=lambda : self.show_egram(self))
            self.show_egram_btn.pack(side=RIGHT, padx=20)
        if stat == "Settings":
            self.mode = "SET"
            changepwd_btn = Button(toolbar, text=self.lang["ChangePwd"], bootstyle="warning",
                                 command=lambda : self.quit(self, mode="PWD"))
            changepwd_btn.pack(side=RIGHT, padx=20)
            setting_label = Label(toolbar, text=self.lang["Settings"], font="Helvetica 20")
            setting_label.pack(side=LEFT, padx=20)
            sftw_stings_btn = Button(toolbar, text=self.lang["Back"], bootstyle="success",
                                 command=lambda : self.pacemaker_configure_frame(self))
            sftw_stings_btn.pack(side=RIGHT, padx=0)

    def pacemaker_configure_frame(self):
        self.toolbar_frame(self, "Main")
        self.stng_interact_f.pack_forget()
        self.main_interact_f.pack(side=TOP, fill="both", expand=True, padx=5, pady=10)
        frame = self.main_interact_f
        # for widget in frame.winfo_children():
        #     widget.destroy()

        presets_frame = Labelframe(frame, text=self.lang["Presets"])
        # presets_frame.pack(side=LEFT, fill="both", expand=True, padx=5, pady=10)
        presets_frame.place(relx=0.01, rely=0.01, relheight=0.99, relwidth=0.365)
        preset_title = Frame(presets_frame, height=0.08*self.rooth)
        preset_title.pack(side=TOP, fill=X)
        add_preset_btn = Button(preset_title, text="+", bootstyle=("info", "outline"),
                                command=lambda : self.add_preset(self))
        add_preset_btn.place(relx=0.98, y=0.04*self.rooth, anchor="e")
        preset_lable = Label(preset_title, text=self.lang["SelPreset"])
        preset_lable.place(relx=0.02, y=0.04*self.rooth, anchor="w")
        self.preset_frame = VerticalScrolledFrame(presets_frame)
        self.preset_frame.enable_scrl()
        self.preset_frame.pack(side=BOTTOM, fill=BOTH, expand=True, pady=10, padx=5)

        # if self.pacing_mode == "":
        self.parameter_frame = Labelframe(frame, text=self.lang["PacePara"])
        # parameter_frame.pack(side=RIGHT, fill="both", expand=True, padx=5, pady=10)
        self.parameter_title = Frame(self.parameter_frame, height=0.08*self.rooth)
        self.parameter_title.pack(side=TOP, fill=X)
        self.sel_pace_mod_label = Label(self.parameter_title, text=self.lang["SelPaceMod"])
        self.pacing_modes = ["", "AOO", "VOO", "AAI", "VVI", "AOOR", "VOOR", "AAIR", "VVIR"]
        self.pacing_mode_var = StringVar()
        self.pacing_mode_var.set(self.lang["SelPaceMod"])
        self.pacing_mode_sel = OptionMenu(self.parameter_title, self.pacing_mode_var, *(self.pacing_modes),
                                        bootstyle="warning",
                                        command=lambda _ : self.update_pacing_para_frame(self))
        self.pacing_paras_fram = VerticalScrolledFrame(self.parameter_frame)
        # self.pacing_paras_fram = Frame(self.parameter_frame)

        if "_temp" in self.presets:
            self.load_preset(self, "_temp", if_ask=False)
            del self.presets["_temp"]
            self.sync_self_pref(self)
        self.update_preset_frame(self)

        self.sel_pace_mod_label.place(relwidth=0.7, relx=0.02, y=0.04*self.rooth, anchor="w")
        self.parameter_title.pack(side=TOP, fill=X)
        self.parameter_frame.place(relx=0.99, rely=0.01, relheight=0.99, relwidth=0.605, anchor="ne")
        self.pacing_mode_sel.place(relwidth=0.3, relx=0.98, y=0.04*self.rooth, anchor="e")
        self.pacing_paras_fram.pack(side=BOTTOM, fill=BOTH, expand=True, pady=10, padx=5)

    def _spinbox_sel_clr(self, event, spinbox):
        spinbox.selection_clear()

    def update_pacing_para_frame(self, load_preset=""):
        self.pacing_mode = self.pacing_mode_var.get()
        print(self.pacing_mode)
        mode = self.pacing_mode
        for widget in self.pacing_paras_fram.interior.winfo_children():
            widget.destroy()
        match mode:
            case "VOO":
                paras = [LowRateLim, UppRateLim, VAmplitude, VPulseWidth]
            case "AOO":
                paras = [LowRateLim, UppRateLim, AAmplitude, APulseWidth]
            case "AAI":
                paras = [LowRateLim, UppRateLim, AAmplitude, APulseWidth, ASensitivity, ARefractPrid, PVARP, RateSmooth]
            case "VVI":
                paras = [LowRateLim, UppRateLim, VAmplitude, VPulseWidth, VSensitivity, VRefractPrid, RateSmooth]
            case "VOOR":
                paras = [LowRateLim, UppRateLim, MaxSensRt, VAmplitude, VPulseWidth, ActivThold, ReactTime, RespFactor, RecovTime]
            case "AOOR":
                paras = [LowRateLim, UppRateLim, MaxSensRt, AAmplitude, APulseWidth, ActivThold, ReactTime, RespFactor, RecovTime]
            case "AAIR":
                paras = [LowRateLim, UppRateLim, MaxSensRt, AAmplitude, APulseWidth, ASensitivity, ARefractPrid, PVARP, RateSmooth, ActivThold, ReactTime, RespFactor, RecovTime]
            case "VVIR":
                paras = [LowRateLim, UppRateLim, MaxSensRt, VAmplitude, VPulseWidth, VSensitivity, VRefractPrid, RateSmooth, ActivThold, ReactTime, RespFactor, RecovTime]
        
        i = 1
        for index, para in enumerate(paras):
            col = index % 2 + 1
            row = index // 2 + 1
            title = self.lang[para.name]
            # print(para)
            options = [self.lang[_] for _ in para.options()]
            default = self.lang[para.default()]
            title_box = Labelframe(self.pacing_paras_fram.interior, text=title, width=int(20*zoomfactor))
            title_box.grid(row=row, column=col, padx=5, pady=5)
            temp_spinbox = tb.Spinbox(title_box, values=options, state='readonly', width=int(20*zoomfactor))
            temp_spinbox.set(default)
            temp_spinbox.bind("<<Increment>>", lambda _: temp_spinbox.selection_clear)
            temp_spinbox.bind("<<Decrement>>", lambda _: temp_spinbox.selection_clear)
            if load_preset != "":
                temp_spinbox.set(self.lang[self.presets[load_preset][i]])
                i += 1
            temp_spinbox.pack(fill=X)


        # if self.pacing_paras_fram.interior.winfo_reqheight() > 50:
            # self.pacing_paras_fram.vscrollbar.pack_forget()
        first_box = self.pacing_paras_fram.interior.winfo_children()[0].winfo_children()[0]
        first_box.focus_set()

    def get_curr_paras(self):
        paras = []
        for ttlbox in self.pacing_paras_fram.interior.winfo_children():
            temp_spinbox = ttlbox.winfo_children()[0]
            temp_para = temp_spinbox.get()
            para_internal_name = self.lang["rev"+temp_para]
            paras.append(para_internal_name)
        return paras

    def add_preset(self):
        paras = self.get_curr_paras(self)
        count = len(paras)
        if count == 0:
            messagebox.showwarning(self.lang["NoModeSel"], self.lang["NoModMsg"])
            return
        preset_name = self.AskString(self,
                                self.lang["NewPreset"], self.lang["AskPrsetNm"],
                                self.lang["Save"], self.lang["Cancel"]).get()
        if preset_name in self.presets:
            messagebox.showwarning(self.lang["PsetExist"], self.lang["PsExstMsg"])
            return
        if preset_name == None:
            return

        print(preset_name)
        self.presets[preset_name] = [copy.copy(self.pacing_mode), *paras]
        self.sync_self_pref(self)
        self.update_preset_frame(self)
        print(self.presets)

    def del_preset(self, preset_name):
        if_del = messagebox.askokcancel(self.lang["DelCfrmTtl"], self.lang["DelCfrmTxt"],
                                        icon=messagebox.WARNING)
        if if_del:
            del self.presets[preset_name]
            self.update_preset_frame(self)
            self.sync_self_pref(self)
        else:
            return

    def update_preset_frame(self):
        for widget in self.preset_frame.interior.winfo_children():
            widget.destroy()
        for preset_name in self.presets:
            print(preset_name)
            temp_preset_frame = Frame(self.preset_frame.interior)
            temp_preset_button = Button(temp_preset_frame, text=preset_name,
                                        # command=lambda : self.load_preset(self, preset_name=preset_name),
                                        bootstyle="info")
            exec(f"temp_preset_button.config(command=lambda : self.load_preset(self, preset_name={preset_name}))",
                 {"self": self, "temp_preset_button": temp_preset_button, preset_name: preset_name})
            temp_preset_del = Button(temp_preset_frame, text="X",
                                    #  command=lambda : self.del_preset(self, preset_name={preset_name}),
                                     bootstyle=("dark", TOOLBUTTON))
            exec(f"temp_preset_del.config(command=lambda : self.del_preset(self, preset_name={preset_name}))",
                 {"self": self, "temp_preset_del": temp_preset_del, preset_name: preset_name})
            temp_preset_button.pack(side=LEFT, fill=BOTH, expand=True, padx=5, pady=10)
            temp_preset_del.pack(side=RIGHT, fill=Y, padx=5, pady=10)
            temp_preset_frame.pack(fill=X, padx=5)

    def load_preset(self, preset_name, if_ask=True):
        if if_ask:
            if_load = messagebox.askokcancel(self.lang["LdCnfrmTtl"], self.lang["LdCnfrmTxt"],
                                             icon=messagebox.WARNING)
        else:
            if_load = True
        if if_load:
            preset = self.presets[preset_name]
            self.pacing_mode_var.set(preset[0])
            self.pacing_mode = preset[0]
            self.update_pacing_para_frame(self, load_preset=preset_name)
        else:
            return

    def show_egram(self):
        if self.showing_egram is False:
            self.egram_frame.pack(side=BOTTOM, fill="both", expand=True, padx=5)
            Separator(self.egram_frame).pack(fill=X, padx=20, pady=20)
            self.t = LoadSerialEgram_debug()
            self.t.start()
            self.draw_egram = DrawEgram(master=self.egram_frame, t=self.t, lang=self.lang)
            self.show_egram_btn.configure(text=self.lang["HideEgram"])
            current_x = self.root.winfo_width()
            current_y = self.root.winfo_height()
            self.root.geometry(f"{current_x}x{current_y+int(100*zoomfactor)}")
            center(self.root)
            self.showing_egram = True
            self.pacing_paras_fram.enable_scrl()
        else:
            self.hide_egram(self)
            self.pacing_paras_fram.disable_scrl()
            self.show_egram_btn.configure(text=self.lang["ShowEgram"])
            

    def hide_egram(self):
        self.t.stop()
        self.draw_egram.canvas.get_tk_widget().destroy()
        current_x = self.root.winfo_width()
        current_y = self.root.winfo_height()
        self.root.geometry(f"{current_x}x{current_y-int(100*zoomfactor)}")
        self.egram_frame.pack_forget()
        for widget in self.egram_frame.winfo_children():
            widget.destroy()
        self.showing_egram = False

    def setting_frame(self, from_language=False):
        
        if self.pacing_mode != "" and not from_language:
            self.presets["_temp"] = [self.pacing_mode]
            self.presets["_temp"] += self.get_curr_paras(self)

        self.toolbar_frame(self, "Settings")
        self.main_interact_f.pack_forget()
        self.stng_interact_f.pack(side=BOTTOM, fill="both", expand=True, padx=5)
        if self.showing_egram:
            self.hide_egram(self)

        frame = self.stng_interact_f
        frame.pack(side=BOTTOM, fill="both", expand=True, padx=5)
        for widget in frame.winfo_children():
            widget.destroy()
        self.lang_var = StringVar()
        self.lang_var.set(self.lang_var_str)
        langs = ["", "ZH_HK", "EN"]
        sel_lang_list = OptionMenu(frame, self.lang_var, *(langs), command=lambda _ : self.set_lang(self))
        sel_lang_list.pack(side=BOTTOM)
        display_name_var = StringVar()
        change_display_name = Entry(frame, textvariable=display_name_var)
        change_display_name.insert(0, self.loginname)
        display_name_var.trace("w", lambda _, __, ___, display_name_var=display_name_var :
                               self.change_display_name(self, display_name_var))
        change_display_name.pack(side=BOTTOM)
    
    def change_display_name(self, display_name_var):
        print("name changed")
        self.loginname = display_name_var.get()
        self.root.title(self.lang["RootTitle<"] + self.loginname + self.lang["RootTitle>"])
        self.sync_self_pref(self)

    def set_lang(self):
        self.lang_var_str = self.lang_var.get()
        match self.lang_var_str:
            case "ZH_HK":
                self.lang = langpack.CN
            case "EN":
                self.lang = langpack.EN
        self.sync_self_pref(self)
        self.root.title(self.lang["RootTitle<"] + self.loginname + self.lang["RootTitle>"])
        self.toolbar_frame(self, "Settings")
        self.setting_frame(self, from_language="True")

def main():
    root, logged, userid, loginname = login.login(relogin=False, debug=False)
    while 1:
        print(logged)
        if not logged or userid == -1:
            return
        quit_code = mainpage(userid, loginname, root=root)
        if quit_code == 0:
            return
        root, logged, userid, loginname = login.login(relogin=True, debug=False, quit_code=quit_code)

if __name__ == "__main__":
    main()