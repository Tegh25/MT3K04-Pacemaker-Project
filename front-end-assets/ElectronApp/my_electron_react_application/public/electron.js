const electron = require("electron");
const path = require("path");
const settings = require("electron-settings");

const app = electron.app;
const BrowserWindow = electron.BrowserWindow;
const ipcMain = electron.ipcMain;

let mainWindow;

function createWindow() {
  // Create the browser window.
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: { nodeIntegration: true, contextIsolation: false },
  });
  // and load the index.html of the app.
  console.log(__dirname);
  mainWindow.loadFile(path.join(__dirname, "../build/index.html"));
  mainWindow.openDevTools();

  //let sign = new BrowserWindow({parent:mainWindow});
  //mainWindow.loadFile('sign')
}

ipcMain.on('signup-data', (even, data) => {
  const{username, password} = data;
  settings.configure({
    fileName: 'user.json',
    prettify: true
  });
  settings.set(username, password);
  console.log(settings.file());
});



// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on("ready", createWindow);

// Our App code goes here
