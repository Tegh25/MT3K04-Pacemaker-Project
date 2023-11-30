from tkinter import *
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from ttkbootstrap import *
import pickle
from PIL import Image, ImageTk
from pickle import UnpicklingError

from funclib import *

from platform import system as sys
_os = sys()
if _os == "Windows":
    zoomfactor = 1.5
    from ctypes import windll
    windll.shcore.SetProcessDpiAwareness(1)
else:
    zoomfactor = 1

class login:
    userid = -1
    login_success = False
    loginname = ""
    def __new__(self, relogin=False, debug=False, quit_code=1):
        if not relogin:
            self.style = Style()
            self.style = Style(theme="pulse")
            self.root = self.style.master
        self.login_success=False
        rootw = int(1024*zoomfactor)
        rooth = int(768*zoomfactor)
        self.root.minsize(rootw, rooth)
        # self.root.maxsize(rootw, rooth)
        center(self.root)
        self.root.config(bg="#b5cdc4")
        self.root.title("Welcome")
        logo_file = Image.open("Logo.png")
        logo_file = logo_file.resize((177, 202))
        logo = ImageTk.PhotoImage(logo_file)
        self.root.protocol("WM_DELETE_WINDOW", lambda : self.root.destroy())
        logo_canvas = tk.Label(self.root, image=logo)
        logo_canvas.place(relx=0.06, rely=0.06, anchor="nw")
        logo_canvas.config(bg="#b5cdc4")
        self.interact_frame = tk.Frame(self.root, padx=20, pady=30)
        self.interact_frame.place(relx=0.5, rely=0.3, relwidth=0.4, anchor="n")
        self.interact_frame.grid_rowconfigure(0, weight=1)
        self.interact_frame.grid_columnconfigure(0, weight=1)
        self.interact_frame.grid_rowconfigure(9999, weight=1)
        self.interact_frame.grid_columnconfigure(9999, weight=1)
        if quit_code == 1:
            self.login(self)
        if isinstance(quit_code, str):
            self.change_password(self, quit_code)
        if not debug:
            self.root.mainloop()
            return self.root, self.login_success, self.userid, self.loginname
        if debug:
            return self.root, True, "db49b86420995fd50561e44ca97f9cff0f67798f182119c42984fd1002155a57", "forbesii"

    def error_handeler(self, err, username):
        try:
            raise err
        except NoUserError:
            new_user = messagebox.askyesno("User Doesn't Exist", err)
            if new_user:
                self.register(self, username)
        except UserExistError:
            goto_login = messagebox.askyesno("User Already Exist", err)
            if goto_login:
                self.login(self, username)
        except PasswdMatchError:
            messagebox.showwarning("Password Doesn't Match", err)
        except PasswordError:
            messagebox.showwarning("Wrong Password", err)
        except (NoDatabaseError, UnpicklingError):
            messagebox.showerror("Fatal Error", err)
        except InputNotValidError:
            messagebox.showwarning("Not a Valid Input", err)

    def register(self, username):
        window = self.interact_frame
        for widget in window.winfo_children():
            widget.destroy()
        self.root.title("Register")
        title = tk.Label(window, text="Register", font="Helvetica 48", pady=0)
        title.grid(row=0, column=1, columnspan=2, sticky="n")
        title_ = tk.Label(window, text=" ", font="Helvetica 16", pady=0)
        title_.grid(row=1, column=1, columnspan=2, sticky="n")
        username_label = Label(window, text="Username : ")
        username_label.grid(row=2, column=1, padx=10, pady=10, sticky="e")
        username_entry = Entry(window)
        username_entry.insert(END, username)
        username_entry.grid(row=2, column=2, padx=10, pady=10, sticky="w")
        username_entry.focus_set()
        password_label = Label(window, text="Password : ")
        password_label.grid(row=3, column=1, padx=10, pady=10, sticky="e")
        password_entry = Entry(window, show='*')
        password_entry.grid(row=3, column=2, padx=10, pady=10, sticky="w")
        re_password_label = Label(window, text="Repeat Password : ")
        re_password_label.grid(row=4, column=1, padx=10, pady=10, sticky="e")
        re_password_entry = Entry(window, show='*')
        re_password_entry.grid(row=4, column=2, padx=10, pady=10, sticky="w")
        login_button = Button(window, text="Register", command=lambda : self.create_user(self, username_entry, password_entry, re_password_entry))
        login_button.grid(row=5, column=1, columnspan=2, padx=10, pady=10)
        register_text = Label(window, text="Already a user? Login Here.")
        register_text.grid(row=6, column=1, columnspan=2, padx=10, pady=10)
        register_text.config(foreground="#55e")
        register_text.bind("<Button-1>", lambda _: self.login(self, username_entry.get()))
        self.root.bind("<Return>", lambda _ : self.create_user(self, username_entry, password_entry, re_password_entry))

    def change_password(self, username):
        window = self.interact_frame
        for widget in window.winfo_children():
            widget.destroy()
        self.root.title("Change Password for " + username)
        title = tk.Label(window, text="Change Password", font="Helvetica 36", pady=0)
        title.grid(row=0, column=1, columnspan=2, sticky="n")
        title_ = tk.Label(window, text="Username: " + username, font="Helvetica 16", pady=10)
        title_.grid(row=1, column=1, columnspan=2, sticky="n")
        oldpass_label = Label(window, text="Current Password : ")
        oldpass_label.grid(row=2, column=1, padx=10, pady=10, sticky="e")
        oldpass_entry = Entry(window, show='*')
        oldpass_entry.grid(row=2, column=2, padx=10, pady=10, sticky="w")
        oldpass_entry.focus_set()
        password_label = Label(window, text="New Password : ")
        password_label.grid(row=3, column=1, padx=10, pady=10, sticky="e")
        password_entry = Entry(window, show='*')
        password_entry.grid(row=3, column=2, padx=10, pady=10, sticky="w")
        re_password_label = Label(window, text="Repeat Password : ")
        re_password_label.grid(row=4, column=1, padx=10, pady=10, sticky="e")
        re_password_entry = Entry(window, show='*')
        re_password_entry.grid(row=4, column=2, padx=10, pady=10, sticky="w")
        ctrl_btn_frame = Frame(window)
        ctrl_btn_frame.grid(row=5, column=1, columnspan=2, padx=10, pady=10)
        save_button = Button(ctrl_btn_frame, text="Save", command=lambda : self.validate_newpass(self, username, oldpass_entry, password_entry, re_password_entry))
        save_button.pack(side="left", padx=10)
        cancel_button = Button(ctrl_btn_frame, text="Cancel", command=lambda : self.validate_newpass(self, username, oldpass_entry, password_entry, re_password_entry, cancel=True))
        cancel_button.pack(side="right", padx=10)
        self.root.bind("<Return>", lambda _ : self.validate_newpass(self, username, oldpass_entry, password_entry, re_password_entry))

    def login(self, username=""):
        window = self.interact_frame
        for widget in window.winfo_children():
            widget.destroy()
        self.root.title("Login")
        title = tk.Label(window, text="Login", font="Helvetica 48", pady=0)
        title.grid(row=0, column=1, columnspan=2, sticky="n")
        title_ = tk.Label(window, text=" ", font="Helvetica 16", pady=0)
        title_.grid(row=1, column=1, columnspan=2, sticky="n")
        username_label = tk.Label(window, text="Username : ")
        username_label.grid(row=2, column=1, padx=10, pady=10, sticky="e")
        username_entry = tk.Entry(window)
        username_entry.insert(END, username)
        username_entry.grid(row=2, column=2, padx=10, pady=10, sticky="w")
        username_entry.focus_set()
        password_label = tk.Label(window, text="Password : ")
        password_label.grid(row=3, column=1, padx=10, pady=10, sticky="e")
        password_entry = tk.Entry(window, show='*')
        password_entry.grid(row=3, column=2, padx=10, pady=10, sticky="w")
        login_button = Button(window, text="Login", command=lambda : self.validate_login(self, username_entry, password_entry))
        login_button.grid(row=4, column=1, columnspan=2, padx=10, pady=10)
        register_text = tk.Label(window, text="Not a user? Register Here.")
        register_text.grid(row=5, column=1, columnspan=2, padx=10, pady=10)
        register_text.config(foreground="#55e")
        register_text.bind("<Button-1>", lambda _: self.register(self, username_entry.get()))
        self.root.bind("<Return>", lambda _ : self.validate_login(self, username_entry, password_entry))

    def validate_newpass(self, username, old_e, passwd_e, re_passwd_e, cancel=False):
        if cancel:
            self.login_success = True
            self.userid = hash(username)
            self.loginname = username
            self.root.quit()
            return
        try:
            try:
                with open('usercred.pkl', 'rb') as obj:
                    hashs = pickle.load(obj)
            except FileNotFoundError:
                raise NoDatabaseError
            except UnpicklingError:
                raise NoDatabaseError
            old_passwd = old_e.get()
            passwd = passwd_e.get()
            re_passwd = re_passwd_e.get()
            if hash(old_passwd) != hashs[username]:
                raise PasswordError
            if len(passwd) <= 3:
                raise InputNotValidError
            if re_passwd != passwd:
                raise PasswdMatchError
            pwdhash = hash(passwd)
            hashs[username] = pwdhash
            with open('usercred.pkl', "wb") as obj:
                pickle.dump(hashs, obj, pickle.HIGHEST_PROTOCOL)
            goto_login = messagebox.showinfo("Password Changed!", "Password changed, please re-login.")
            if goto_login:
                self.login(self, username)
        except (PasswdMatchError, PasswordError, NoDatabaseError, InputNotValidError) as err:
            self.error_handeler(self, err, username)

    def create_user(self, user_e, passwd_e, re_passwd_e):
        username = user_e.get()
        passwd = passwd_e.get()
        re_passwd = re_passwd_e.get()
        register_success = False
        try:
            if len(username) <= 3:
                raise InputNotValidError
            if re_passwd != passwd:
                raise PasswdMatchError
            try:
                with open('usercred.pkl', 'rb') as obj:
                    hashs = pickle.load(obj)
            except FileNotFoundError:
                raise NoDatabaseError
            except UnpicklingError:
                raise NoDatabaseError
            pwdhash = hash(passwd)
            if username in hashs:
                raise UserExistError
            if len(passwd) <= 3:
                raise InputNotValidError
            hashs[username] = pwdhash
            with open('usercred.pkl', "wb") as obj:
                pickle.dump(hashs, obj, pickle.HIGHEST_PROTOCOL)
            register_success = True
            goto_login = messagebox.askyesno("Success!", "User created. Want to login?")
            if goto_login:
                self.login(self, username)
        except (PasswdMatchError, UserExistError, NoDatabaseError, InputNotValidError) as err:
            self.error_handeler(self, err, username)
        return register_success

    def validate_login(self, user_e, passwd_e):
        username = user_e.get()
        passwd = passwd_e.get()
        try:
            if len(username) <= 3:
                raise InputNotValidError
            try:
                with open('usercred.pkl', 'rb') as obj:
                    hashs = pickle.load(obj)
            except FileNotFoundError:
                raise NoDatabaseError
            except UnpicklingError:
                raise NoDatabaseError
            pwdhash = hash(passwd)
            if username not in hashs:
                raise NoUserError
            if hashs[username] == pwdhash:
                self.login_success = True
                self.userid = hash(username)
                self.loginname = username
                self.root.quit()
            if hashs[username] != pwdhash:
                raise PasswordError
        except (NoUserError, PasswordError, NoDatabaseError, InputNotValidError) as err:
            self.error_handeler(self, err, username)

if __name__ == "__main__":
    a = login(quit_code="forbesii")
    print(a)