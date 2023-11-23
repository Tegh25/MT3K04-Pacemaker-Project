# All Exceptions Needed
class PasswordError(Exception):
    def __str__(self) -> str:
        return "The password you input doesn't match our record, please try again."
class UserExistError(Exception):
    def __str__(self) -> str:
        return "The username you input already exist, whould you like to login?"
class NoUserError(Exception):
    def __str__(self) -> str:
        return "The username you input doesn't exist, whould you like to creat one?"
class NoDatabaseError(Exception):
    def __str__(self) -> str:
        return "The password database doens't exist, please contact your administrator."
class PasswdMatchError(Exception):
    def __str__(self) -> str:
        return "The passwords you entered doesn't match, please try again."
class InputNotValidError(Exception):
    def __str__(self) -> str:
        return "Please enter valid characters."

import hashlib
def hash(data):
    if isinstance(data, str):
        data = data.encode()
    sha256_hash = hashlib.sha256(data).hexdigest()
    return sha256_hash

def center(win):
    """
    centers a tkinter window
    :param win: the main window or Toplevel window to center
    """
    win.update_idletasks()
    width = win.winfo_width()
    frm_width = win.winfo_rootx() - win.winfo_x()
    win_width = width + 2 * frm_width
    height = win.winfo_height()
    titlebar_height = win.winfo_rooty() - win.winfo_y()
    win_height = height + titlebar_height + frm_width
    x = win.winfo_screenwidth() // 2 - win_width // 2
    y = win.winfo_screenheight() // 2 - win_height // 2
    win.geometry('{}x{}+{}+{}'.format(width, height, x, y))
    win.deiconify()

import serial.tools.list_ports
def serial_ports():
    return serial.tools.list_ports.comports()

import tkinter as tk
import tkinter.ttk as ttk
from platform import system as sys
class VerticalScrolledFrame(ttk.Frame):

    def _configure_interior(self, event):
            size = (self.interior.winfo_reqwidth(), self.interior.winfo_reqheight())
            self.canvas.config(scrollregion="0 0 %s %s" % size)
            if self.interior.winfo_reqwidth() != self.canvas.winfo_width():
                self.canvas.config(width=self.interior.winfo_reqwidth())

    def _configure_canvas(self, event):
        if self.interior.winfo_reqwidth() != self.canvas.winfo_width():
            self.canvas.itemconfigure(self.interior_id, width=self.canvas.winfo_width())

    def _on_mousewheel(self, event, scroll=None):
        os = sys()
        if os == 'Windows':
            self.canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        elif os == 'Darwin':
            self.canvas.yview_scroll(int(-1 * event.delta), "units")
        else:
            self.canvas.yview_scroll(int(scroll), "units")

    def _bind_to_mousewheel(self, event):
        os = sys()
        if os == 'Windows':
            self.canvas.bind_all("<MouseWheel>", lambda event : self._on_mousewheel(event))
        elif os == 'Darwin':
            self.canvas.bind_all("<MouseWheel>", lambda event : self._on_mousewheel(event))
        else:
            self.canvas.bind_all("<Button-4>", lambda event : self._on_mousewheel(event, scroll=-1))
            self.canvas.bind_all("<Button-5>", lambda event : self._on_mousewheel(event, scroll=1))

    def _unbind_from_mousewheel(self, event):
        os = sys()
        if os == 'Windows':
            self.canvas.unbind_all("<MouseWheel>")
        elif os == 'Darwin':
            self.canvas.unbind_all("<MouseWheel>")
        else:
            self.canvas.unbind_all("<Button-4>")
            self.canvas.unbind_all("<Button-5>")

    def enable_scrl(self):
        self.interior.bind('<Configure>', self._configure_interior)
        self.canvas.bind('<Configure>', self._configure_canvas)
        self.canvas.bind('<Enter>', self._bind_to_mousewheel)
        self.canvas.bind('<Leave>', self._unbind_from_mousewheel)
        self.vscrollbar.pack(fill=tk.Y, side=tk.RIGHT, expand=tk.FALSE)
    
    def disable_scrl(self):
        self.interior.unbind("<Configure>")
        self.canvas.unbind("<Configure>")
        self.canvas.unbind("<Enter>")
        self.canvas.unbind("<Leave>")
        self.canvas.unbind("<MouseWheel>")
        self.canvas.unbind("<Button-4>")
        self.canvas.unbind("<Button-5>")
        # self._unbind_from_mousewheel()
        self.vscrollbar.pack_forget()

    def __init__(self, parent, *args, **kw):
        ttk.Frame.__init__(self, parent, *args, **kw)

        self.vscrollbar = ttk.Scrollbar(self, orient=tk.VERTICAL, bootstyle=("round"))

        canvas = tk.Canvas(self, bd=0, highlightthickness=0,
                           yscrollcommand=self.vscrollbar.set)
        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.TRUE)
        self.vscrollbar.config(command=canvas.yview)

        canvas.xview_moveto(0)
        canvas.yview_moveto(0)

        self.interior = interior = ttk.Frame(canvas)
        self.canvas = canvas
        self.interior_id = canvas.create_window(0, 0, window=interior,
                                           anchor=tk.NW)



import threading
import time
class LoadSerialEgram(threading.Thread):
    def run(self, *args, **kwargs):
        while True:
            if self.stopped():
                return
            # Read data from serial, add data to self.egram_data: list
            time.sleep(0.01)

    def __init__(self, serial, *args, **kwargs):
        self.serial_name = serial
        # Send a command to board to start sending egram data
        super(LoadSerialEgram, self).__init__(*args, **kwargs)
        self._stop_event = threading.Event()

    def stop(self):
        # Send a command to board to stop sending egram data
        self._stop_event.set()

    def stopped(self):
        return self._stop_event.is_set()
    
import math
class LoadSerialEgram_debug(threading.Thread):
    def run(self, *args, **kwargs):
        i = 0
        while True:
            if self.stopped():
                print("Egram stopped")
                return
            freq = 100
            self.egram_data_x.append(i*1000/freq)
            self.egram_data_y1.append(math.cos(i*math.pi/50))
            self.egram_data_y2.append(math.sin(i*math.pi/50))
            if len(self.egram_data_x) >= 500:
                self.egram_data_x.pop(0)
            if len(self.egram_data_y1) >= 500:
                self.egram_data_y1.pop(0)
            if len(self.egram_data_y2) >= 500:
                self.egram_data_y2.pop(0)
            time.sleep(1/freq)
            i += 1

    def __init__(self, serial=None, *args, **kwargs):
        self.serial_name = serial
        # Send a command to board to start sending egram data
        self.egram_data_x = []
        self.egram_data_y1 = []
        self.egram_data_y2 = []
        super(LoadSerialEgram_debug, self).__init__(*args, **kwargs)
        self._stop_event = threading.Event()

    def stop(self):
        # Send a command to board to stop sending egram data
        self._stop_event.set()

    def stopped(self):
        return self._stop_event.is_set()

def reverse_bool(_: bool):
    return False if _ else True

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.pyplot import figure
import ttkbootstrap as tb
class DrawEgram():
    plot1 = True
    plot2 = True
    def animation(self, j):
        plt.cla()
        if self.plot1:
            plt.plot(self.t.egram_data_x, self.t.egram_data_y1, 'r')
        if self.plot2:
            plt.plot(self.t.egram_data_x, self.t.egram_data_y2, 'b')
    def show_hide_graph(self, plot):
        match plot:
            case 1:
                if self.plot1:
                    self.plot1 = False
                    self.btn1.config(bootstyle=("outline", "danger"))
                else:
                    self.plot1 = True
                    self.btn1.config(bootstyle=("solid", "danger"))
            case 2:
                if self.plot2:
                    self.plot2 = False
                    self.btn2.config(bootstyle=("outline", "info"))
                else:
                    self.plot2 = True
                    self.btn2.config(bootstyle=("solid", "info"))
    def __init__(self, master, t, lang) -> None:
        plt.style.use('bmh')
        self.master = master
        self.t = t
        figure(figsize=(3, 2), dpi=80)
        self.control_frame = tb.Frame(master=self.master, padding=0)
        self.drawing_frame = tb.Frame(master=self.master, height=100, padding=0)
        self.control_frame.pack(side='top')
        self.drawing_frame.pack(side='bottom', fill="both", expand=True)
        self.btn1 = tb.Button(self.control_frame, text=lang["Vent"],
                          command=lambda: self.show_hide_graph(1),
                          bootstyle="danger")
        self.btn2 = tb.Button(self.control_frame, text=lang["Atr"],
                          command=lambda: self.show_hide_graph(2),
                          bootstyle="info")
        self.btn1.pack(side="left", padx=5)
        self.btn2.pack(side="right", padx=5)
        self.canvas = FigureCanvasTkAgg(plt.gcf(), master=self.drawing_frame)
        self.canvas.get_tk_widget().place(relx=0.504, rely=0.48, relheight=1.13, relwidth=1.22, anchor="center")
        # self.canvas.get_tk_widget().pack(fill="x", expand=True)
        self.animation = FuncAnimation(plt.gcf(), self.animation, interval=250, blit=False, save_count=10)
