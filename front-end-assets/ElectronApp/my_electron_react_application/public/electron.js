const electron = require("electron");
const path = require("path");
const settings = require("electron-settings");

const app = electron.app;
const BrowserWindow = electron.BrowserWindow;
const ipcMain = electron.ipcMain;

let mainWindow;

settings.configure({
  fileName: 'user.json',
  prettify: true
});

function createWindow() {
  // Create the browser window.
  mainWindow = new BrowserWindow({
    width: 1200,
    height: 800,
    webPreferences: { nodeIntegration: true, contextIsolation: false },
  });
  // and load the index.html of the app.
  console.log(__dirname);
  mainWindow.loadFile(path.join(__dirname, "../build/index.html"));
  mainWindow.openDevTools();

  //let sign = new BrowserWindow({parent:mainWindow});
  //mainWindow.loadFile('sign')
}

ipcMain.on('signup-data', async(event, data) => {
  // signUpValidationEnum -> VALID: 1, USERNAMETAKEN: 2, TOOMANYUSERNAMES: 3
  const{username, password, signUpValidationEnum} = data;
  if(Object.keys(await settings.get()).length < 10) {
    if(await settings.get(username)) {
      isValidLogin = signUpValidationEnum.USERNAMETAKEN
    }
    else{
      isValidSignUp = signUpValidationEnum.VALID
      settings.set(username,{password: password});
    }
  }
  else{
    isValidSignUp = signUpValidationEnum.TOOMANYUSERNAMES
  }
  event.reply('signup-data', { isValidSignUp })
});

ipcMain.on('login-data', async(event, data) => {
  const{username, password} = data;
  let isValidLogin = false;
  const userData = await settings.get(username)
  if (userData.password == password) {
    isValidLogin = true;
  } else {
    isValidLogin = false;
  }
  event.reply('login-data', { isValidLogin });
});


// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on("ready", createWindow);

// Our App code goes here
