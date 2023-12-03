from tkinter import *
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import ttkbootstrap as ttkb
import pickle
from PIL import Image, ImageTk
from pickle import UnpicklingError

from Shadow import Shadow
from GradientFrame import GradientFrame
from funclib import *
# from BorderImageData import focusBorderImageData, borderImageData

style = ttkb.Style()
style = ttkb.Style(theme="pulse")

def error_handeler(window, err, username, parent):
    try:
        raise err
    except NoUserError:
        new_user = messagebox.askyesno("User Doesn't Exist", err)
        if new_user:
            register(window, username, parent)
    except UserExistError:
        goto_login = messagebox.askyesno("User Already Exist", err)
        if goto_login:
            login(window, parent, username)
    except PasswdMatchError:
        messagebox.showwarning("Password Doesn't Match", err)
    except PasswordError:
        messagebox.showwarning("Wrong Password", err)
    except (NoDatabaseError, UnpicklingError):
        messagebox.showerror("Fatal Error", err)
    except InputNotValidError:
        messagebox.showwarning("Not a Valid Input", err)

def register(window, username, parent):
    # print("register function not implemented, received username:", username)
    for widget in window.winfo_children():
        widget.destroy()
    # window.title("Register")
    title = tk.Label(window, text="Register", font="* 48", pady=0)
    title.grid(row=0, column=1, columnspan=2, sticky="n")
    title_ = tk.Label(window, text=" ", font="* 16", pady=0)
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
    login_button = ttkb.Button(window, text="Register", command=lambda : create_user(window, username_entry, password_entry, re_password_entry, parent))
    login_button.grid(row=5, column=1, columnspan=2, padx=10, pady=10)
    register_text = Label(window, text="Already a user? Login Here.")
    register_text.grid(row=6, column=1, columnspan=2, padx=10, pady=10)
    register_text.config(foreground="#55e")
    register_text.bind("<Button-1>", lambda _: login(window, parent, username_entry.get()))
    parent.bind("<Return>", lambda _ : create_user(window, username_entry, password_entry, re_password_entry, parent))

def login(window, parent, username=""):
    for widget in window.winfo_children():
        widget.destroy()
    # window.title("Login")
    title = tk.Label(window, text="Login", font="* 48", pady=0)
    title.grid(row=0, column=1, columnspan=2, sticky="n")
    title_ = tk.Label(window, text=" ", font="* 16", pady=0)
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
    login_button = ttkb.Button(window, text="Login", command=lambda : validate_login(window, username_entry, password_entry, parent))
    login_button.grid(row=4, column=1, columnspan=2, padx=10, pady=10)
    register_text = tk.Label(window, text="Not a user? Register Here.")
    register_text.grid(row=5, column=1, columnspan=2, padx=10, pady=10)
    register_text.config(foreground="#55e")
    register_text.bind("<Button-1>", lambda _: register(window, username_entry.get(), parent))
    parent.bind("<Return>", lambda _ : validate_login(window, username_entry, password_entry, parent))

def create_user(window, user_e, passwd_e, re_passwd_e, parent):
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
            login(window, parent, username)
    except (PasswdMatchError, UserExistError, NoDatabaseError) as err:
        error_handeler(window, err, username, parent)
    return register_success

def validate_login(window, user_e, passwd_e, parent):
    global login_success
    global userid
    username = user_e.get()
    passwd = passwd_e.get()
    login_success = False
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
            login_success = True
            userid = hash(username)
            parent.destroy()    
        if hashs[username] != pwdhash:
            raise PasswordError
    except (NoUserError, PasswordError, NoDatabaseError, InputNotValidError) as err:
        error_handeler(window, err, username, parent)

def login_main():
    global login_success
    login_success = False
    root = style.master
    # root=tk.Tk()
    rootw = 1024
    rooth = 768
    root.minsize(rootw, rooth)
    root.maxsize(rootw, rooth)
    center(root)
    root.config(bg="#b5cdc4")
    root.title("Welcome")
    # gf = GradientFrame(root, colors = ("#f0e0d6", "#d7efec"), width = rootw, height = rooth)
    # gf.config(direction = gf.top2bottom)
    # gf.place(x=0, y=0)
    logo_file = Image.open("Logo.png")
    logo_file = logo_file.resize((177, 202))
    logo = ImageTk.PhotoImage(logo_file)
    logo_canvas = tk.Label(root, image=logo)
    logo_canvas.place(relx=0.06, rely=0.06, anchor="nw")
    logo_canvas.config(bg="#b5cdc4")
    interact_frame = tk.Frame(root, padx=20, pady=30)
    interact_frame.place(relx=0.5, y=0.3*rooth, relwidth=0.4, anchor="n")
    interact_frame.grid_rowconfigure(0, weight=1)
    interact_frame.grid_columnconfigure(0, weight=1)
    interact_frame.grid_rowconfigure(9999, weight=1)
    interact_frame.grid_columnconfigure(9999, weight=1)
    login(interact_frame, root)
    root.mainloop()
    del root
    try:
        return login_success, userid
    except NameError:
        return login_success, -1


if __name__ == "__main__":
    login_main()