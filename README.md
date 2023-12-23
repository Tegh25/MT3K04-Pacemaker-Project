# MT3K04-Pacemaker-Project

This repository preserves and displays all our coursework from our third-year Software Development course, in which we developed a fully functional Pacemaker using Simulink and Python.

Eight pacing control modes (AOO, VOO, AAI, VVI, AOOR, VOOR, AAIR, VVIR) were developed using Simulink and tested using hardware that simulated a pacemaker and heart.

The pacemaker is controlled by the device control module (DCM), which is a graphical user interface that selects the mode and user parameters using the UART serial communication protocol to communicate with the pacemaker. The DCM was created in Python, with another version of the DCM created using React with limited functionality.

The design process, decisions, safety assurance cases, and testing are all included in the documentation file included in this repository.

<img src="https://github.com/Tegh25/MT3K04-Pacemaker-Project/assets/48258080/2227dc68-365d-4cdd-90ee-328be8e22126" width="700" height="550" />

---

## Python Device Control Module

Python 3.11 is required to run the Python DCM locally.

### Required Packages

- Serialtools
- Ttkbootstrap
- Matplotlib

```
pip install serialtools
pip install ttkbootstrap
pip install matplotlib
```

The following packages are also used in this project, they may not be required to be downloaded using pip.
- Tkinter
- Pickle
- VerticalScrolledFrame https://gist.github.com/novel-yet-trivial/3eddfce704db3082e38c84664fc1fdf8
- Hashlib
- Threading
- Struct
- NumPy
- Dataclasses

To run the DCM locally, open the `pacemaker_pythonDCM` folder in a VSCode window and simply run the `mainpage.py` file.


## React Device Control Module

Node.js v16.19 is required to run the React DCM locally.

### Electron.js Download

[Electron official installation guide.](https://www.electronjs.org/docs/latest/tutorial/installation)

This application uses the Electron.js framework, the package can be downloaded simply by using the following command:

`npm install electron --save-dev`

### Craco Download

[Create React App Configuration Override official installation guide.](https://www.npmjs.com/package/@craco/craco)

Navigate to the `front-end-assets/ElectronApp/my_electron_react_application` directory and perform the following commands to run the React DCM locally.

```
npm run start
npm run build
```

All Simulink models were created using MATLAB/Simulink R2023b and are located in the `Simulink` folder. The `allModesSerial.slx` file implements all pacing control modes and is the final version of the project.

The hardware kit provided by McMaster University is required for building and flashing the model. Please note that the following packages are required to open the Simulink models.

![image](https://github.com/Tegh25/MT3K04-Pacemaker-Project/assets/48258080/31651267-ae96-49bc-8d24-ba2db9dcd240)

The final version of the Simulink model:
![image](https://github.com/Tegh25/MT3K04-Pacemaker-Project/assets/48258080/a74c8ee0-068d-43d8-ae87-003574730920)

