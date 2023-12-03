import serial
import struct
from paraslib import *

def convert(para, data):
    if para == ActivThold:
        thold_map = {
            "_V-Low": 1,
            "_Low": 2,
            "_Med-Low": 3,
            "_Med": 4,
            "_Med-High": 5,
            "_High": 6,
            "_V-High": 7
            }
        data = thold_map[data]
        return data
    if data == "_OFF":
        return 0
    if para in [VAmplitude, AAmplitude, VPulseWidth, APulseWidth, ASensitivity, VSensitivity]:
        return float(data)
    else:
        return int(float(data))

def sendSerial(port, paras_data_list):
    # Function_Call = 0 BY DEFAULT

    st = struct.Struct('<BBBBddddddBBBBBBBBB')

    mode = paras_data_list[0]

    mode_map = {
        'AOO': 1,
        'VOO': 2,
        'AAI': 3,
        'VVI': 4,
        'AOOR': 5,
        'VOOR': 6,
        'AAIR': 7,
        'VVIR': 8,
    }

    match mode:
        case "VOO":
            paras = [LowRateLim, UppRateLim, VAmplitude, VPulseWidth]
        case "AOO":
            paras = [LowRateLim, UppRateLim, AAmplitude, APulseWidth]
        case "AAI":
            paras = [LowRateLim, UppRateLim, AAmplitude, APulseWidth,
                        ASensitivity, ARefractPrid, PVARP, RateSmooth]
        case "VVI":
            paras = [LowRateLim, UppRateLim, VAmplitude, VPulseWidth,
                        VSensitivity, VRefractPrid, RateSmooth]
        case "VOOR":
            paras = [LowRateLim, UppRateLim, MaxSensRt, VAmplitude, VPulseWidth,
                        ActivThold, ReactTime, RespFactor, RecovTime]
        case "AOOR":
            paras = [LowRateLim, UppRateLim, MaxSensRt, AAmplitude, APulseWidth,
                        ActivThold, ReactTime, RespFactor, RecovTime]
        case "AAIR":
            paras = [LowRateLim, UppRateLim, MaxSensRt, AAmplitude, APulseWidth,
                        ASensitivity, ARefractPrid, PVARP, RateSmooth,
                        ActivThold, ReactTime, RespFactor, RecovTime]
        case "VVIR":
            paras = [LowRateLim, UppRateLim, MaxSensRt, VAmplitude, VPulseWidth,
                        VSensitivity, VRefractPrid, RateSmooth, ActivThold,
                        ReactTime, RespFactor, RecovTime]

    mode = mode_map[mode]
    data_map = {
        "LowRtLim" : 1,
        "UppRtLim" : 1,
        "MaxSensRt": 1,
        "AAmp" : 1.,
        "VAmp" : 1.,
        "APulseWid" : 1.,
        "VPulseWid" : 1.,
        "ASensi" : 1.,
        "VSensi" : 1.,
        "VRefrctPrd" : 1,
        "ARefrctPrd" : 1,
        "PVARP" : 1,
        "RateSmooth" : 1,
        "ActivThold" : 1,
        "ReactTime" : 1,
        "RespFactor" : 1,
        "RecovTime" : 1,
        "veri" : 0
        }
    print([*data_map.values()])
    print(mode)
    for para_name, para_data in zip(paras, paras_data_list[1:]):
        print(para_name.name, para_data)
        para_data = convert(para_name, para_data)
        data_map[para_name.name] = para_data
    print([*data_map.values()])
    serial_com = st.pack(mode, *data_map.values())

    print(serial_com)
    print(len(serial_com))
    unpacked = st.unpack(serial_com)
    print(unpacked)
    try:
        uC = serial.Serial(port, baudrate=9600)
        uC.write(serial_com)
        uC.close()
    except:
        pass
    return serial_com

if __name__ == "__main__":
    # LowRateLim, UppRateLim, AAmplitude, APulseWidth, ASensitivity, ARefractPrid, PVARP, RateSmooth, ActivThold, ReactTime, RespFactor, RecovTime
    paras = ['VOOR', '60', '120', '120', '3.5', '0.4', '_Med', '30', '8', '5']
    serial_com = sendSerial("", paras)
    print(len(serial_com))
    st = struct.Struct('<BBBBddddddBBBBBBBBB')
    unpacked = st.unpack(serial_com)
    print(unpacked)