#Import the tkinter library
from tkinter import *

#Create an instance of tkinter frame
win = Tk()

#Set the geometry
win.geometry("650x250")

def handler(e):
   print(e)
   label= Label(win, text= "You Pressed Enter")
   label.pack()

#Create a Label
Label(win, text= "Press Enter on the Keyboard", font= ('Helvetica bold', 14)).pack(pady=20)

#Bind the Enter Key to Call an event
win.bind('<Return>', lambda _ : handler("hello"))

win.mainloop()