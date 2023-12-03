from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
import tkinter as Tk
from matplotlib.figure import Figure
import random
from itertools import count
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
# from pandas import DataFrame
import math

from funclib import *



class DrawEgram():
    plot1 = True
    plot2 = True
    def animation(self, j):
        plt.cla()
        print("animation")
        if self.plot1:
            plt.plot(self.t.egram_data_x, self.t.egram_data_y1, 'r')
        if self.plot2:
            plt.plot(self.t.egram_data_x, self.t.egram_data_y2, 'b')
    def __init__(self, master, t) -> None:
        plt.style.use('bmh')
        self.master = master
        self.t = t
        self.control_frame = ttk.Frame(master=self.master)
        self.drawing_frame = ttk.Frame(master=self.master)
        self.control_frame.pack(side='top')
        self.drawing_frame.pack(side='top')
        btn1 = ttk.Button(self.control_frame, text="plot1",
                          command=lambda: exec("self.plot1=reverse_bool(plot1)"))
        btn2 = ttk.Button(self.control_frame, text="plot2",
                          command=lambda: exec("self.plot2=reverse_bool(plot2)"))
        btn1.pack(side="left")
        btn2.pack(side="left")
        self.canvas = FigureCanvasTkAgg(plt.gcf(), master=self.drawing_frame)
        self.canvas.get_tk_widget().pack(side='bottom', expand=True, fill='x')
        self.animation = FuncAnimation(plt.gcf(), self.animation, interval=10, blit=False)

root = Tk.Tk()
t = LoadSerialEgram_debug()
t.start()
_ = DrawEgram(root, t)
Tk.mainloop()
t.stop()
