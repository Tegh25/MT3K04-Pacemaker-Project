#Import Tkinter library
from tkinter import *
from tkinter import ttk
#Create an instance of Tkinter frame or window
win= Tk()
#Set the geometry of tkinter frame
win.geometry("750x250")
#Set the default value for SpinBox
my_var= StringVar(win)
my_var.set("1.0")
#Create a spinbox
spinbox= ttk.Spinbox(win, from_=0.5, to=10.0, increment=0.01, textvariable=my_var)
spinbox.pack(ipadx=20, pady=20)
print(spinbox.get())
win.mainloop()