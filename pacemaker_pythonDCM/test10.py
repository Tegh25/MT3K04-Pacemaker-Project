import langpack

lang = langpack.CN

paras = ["LowRtLim", "UppRtLim", ("Vent", "Amp"), ("Vent", "PulseWidth")]

def send_paras(para: str | tuple):
    if isinstance(para, str):
        return para
    

for para in paras:
    print(isinstance(para, tuple))
    print(*(para) if isinstance(para, tuple) else para)