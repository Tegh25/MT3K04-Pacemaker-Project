from dataclasses import dataclass
from typing import *
from numpy import arange as range

@dataclass
class PacePara:
    name: tuple[str]
    range: list[tuple[int | float]]
    incre: list[int | float]
    nominal: int | float
    def _get_name_for_active_threshold(self):
        return ["_V-Low", "_Low", "_Med-Low", "_Med", "_Med-High", "_High", "_V-High"]
    def _get_nominal_for_active_threshold(self):
        return "_Med"
    def options(self):
        if self.name == "ActivThold":
            return self._get_name_for_active_threshold()
        result = []
        for i, lim in enumerate(self.range):
            result += ["_OFF" if round(_, 2)==0
                       else (str(int(_)) if int(self.incre[i])==self.incre[i]
                             else str(round(_, 2)))
                       for _ in range(lim[0], lim[1]+0.1, self.incre[i])]
        return result
    def default(self):
        if self.name == "ActivThold":
            return self._get_nominal_for_active_threshold()
        return "_OFF" if round(self.nominal, 2)==0 else self.nominal

LowRateLim =   PacePara("LowRtLim",
                        [(30,50), (51,89), (90,175)],
                        [5, 1, 5],
                        60)
UppRateLim =   PacePara("UppRtLim",
                        [(50,175)],
                        [5],
                        120)
VAmplitude =    PacePara("VAmp",
                        [(0,0), (0.5,3.2), (3.5,7)],
                        [0.5, 0.1, 0.5],
                        3.5)
AAmplitude =    PacePara("AAmp",
                        [(0,0), (0.5,3.2), (3.5,7)],
                        [0.5, 0.1, 0.5],
                        3.5)
VPulseWidth =   PacePara("VPulseWid",
                        [(0.05,0.05), (0.1,1.9)],
                        [0.05, 0.1],
                        0.4)
APulseWidth =   PacePara("APulseWid",
                        [(0.05,0.05), (0.1,1.9)],
                        [0.05, 0.1],
                        0.4)
ASensitivity = PacePara("ASensi",
                        [(0.25,0.75), (1,10)],
                        [0.25, 0.5],
                        0.75)
VSensitivity = PacePara("VSensi",
                        [(0.25,0.75), (1,10)],
                        [0.25, 0.5],
                        2.5)
ARefractPrid = PacePara("ARefrctPrd",
                        [(150,500)],
                        [10],
                        250)
VRefractPrid = PacePara("VRefrctPrd",
                        [(150,500)],
                        [10],
                        320)
PVARP =        PacePara("PVARP",
                        [(150,500)],
                        [10],
                        250)
Hysteresis =   PacePara("Hysteresis",
                        [(0,0), (30,50), (51,89), (90,175)],
                        [30, 5, 1, 5],
                        0)
RateSmooth =   PacePara("RateSmooth",
                        [(0,21), (25, 25)],
                        [3, 4],
                        0)
ActivThold =   PacePara("ActivThold",
                        [(0,6)],
                        [1],
                        4)
ReactTime =    PacePara("ReactTime",
                        [(10,50)],
                        [10],
                        30)
RespFactor =   PacePara("RespFactor",
                        [(1,16)],
                        [1],
                        8)
RecovTime =    PacePara("RecovTime",
                        [(2,16)],
                        [1],
                        5)

if __name__ == "__main__":
    import tkinter.ttk as ttk
    import tkinter as tk
    root = tk.Tk()
    para = ReactTime
    spinbox = ttk.Spinbox(root, values=para.options())
    spinbox.set(para.default())
    spinbox.pack()
    root.mainloop()