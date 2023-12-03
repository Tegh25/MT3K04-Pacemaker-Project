#Import the tkinter library
from tkinter import *

#Create an instance of tkinter frame
tk = Tk()
tk.geometry("700x300")

#Create the option and Check Button Event
def OptionMenu_CheckButton(event):
   print(var.get())
   pass

#Create the variables
var = StringVar()
var.set("Hello")
options = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
OptionMenu(tk, var, *(options), command=OptionMenu_CheckButton).pack()
tk.mainloop()