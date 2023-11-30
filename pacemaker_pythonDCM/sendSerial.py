import serial
import struct


def sendSerial(mode, LRL, URL, Max_Sensor_Rate, AV_Delay, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, A_Sensitivity, V_Sensitivity, VRP, ARP, PVARP, Rate_Smoothing, Activity_Threshold, Reaction_Time, Response_Factor, Recovery_Time, Function_Call, port):
    # Function_Call = 0 BY DEFAULT

    st = struct.Struct('<BBBBBddBBddHHBBdBBBB')

    mode_map = {
        'AOO': 1,
        'VOO': 2,
        'AAI': 3,
        'VVI': 4,
        'DOO': 5,
        'AOOR': 6,
        'VOOR': 7,
        'AAIR': 8,
        'VVIR': 9,
        'DOOR': 10
    }

    mode = mode_map[mode]
    LRL = int(LRL)
    URL = int(URL)
    Max_Sensor_Rate = int(Max_Sensor_Rate)
    AV_Delay = int(AV_Delay)
    A_Pulse_Width = int(A_Pulse_Width)
    V_Pulse_Width = int(V_Pulse_Width)
    PVARP = int(PVARP)
    Rate_Smoothing = int(Rate_Smoothing)
    Reaction_Time = int(Reaction_Time)
    Response_Factor = int(Response_Factor)
    Recovery_Time = int(Recovery_Time)
    Function_Call = int(Function_Call)

    serial_com = st.pack(mode, LRL, URL, Max_Sensor_Rate, AV_Delay, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, A_Sensitivity,
                         V_Sensitivity, VRP, ARP, PVARP, Rate_Smoothing, Activity_Threshold, Reaction_Time, Response_Factor, Recovery_Time, Function_Call)

    print(serial_com)
    print(len(serial_com))
    uC = serial.Serial(port, baudrate=115200)
    uC.write(serial_com)
    # unpacked = st.unpack(serial_com)
    # print(unpacked)
    uC.close()


# sendSerial(1, 100, 110, 0, 10, 5.0, 5.0, 10, 20, 0.0, 4.0, 200, 0, 0, 0, 1.0, 1, 0, 0, 0, 'COM7')