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

// Configure settings with the following options:
// - fileName: 'user.json' - The name of the JSON file where settings are stored.
// - prettify: true - Enables pretty-printing (formatting) of the JSON data for human readability.
settings.configure({
  fileName: 'user.json',
  prettify: true
});

/**
 * Handles sign-up requests, checks available space for new users, and validates username availability.
 * Replies with the sign-up validity status using the specified enumeration.
 *
 * @param {Electron.IpcMainEvent} event - The event object used for replying to the renderer process.
 * @param {object} data - The data object containing username, password, and the sign-up validation enumeration.
 * @param {string} data.username - The username to be registered.
 * @param {string} data.password - The password associated with the username.
 * @param {object} data.signUpValidationEnum - An enumeration object containing status codes.
 * @param {number} data.signUpValidationEnum.VALID - Status code indicating a successful sign-up.
 * @param {number} data.signUpValidationEnum.USERNAMETAKEN - Status code indicating that the username is already in use.
 * @param {number} data.signUpValidationEnum.TOOMANYUSERNAMES - Status code indicating that the maximum user limit has been reached.
 * @returns {void} Replies with the sign-up validity status.
 */
ipcMain.on('signup-data', async (event, data) => {
  const { username, password, signUpValidationEnum } = data;

  // Check if there is space for new users
  if (Object.keys(await settings.get()).length < 10) {
    if (await settings.get(username)) {
      // User already exists, set the response status accordingly
      isValidSignUp = signUpValidationEnum.USERNAMETAKEN;
    } else {
      // Valid sign-up, set the response status and store the user data
      isValidSignUp = signUpValidationEnum.VALID;
      settings.set(username, { password });
    }
  } else {
    // Too many usernames, set the response status accordingly
    isValidSignUp = signUpValidationEnum.TOOMANYUSERNAMES;
  }

  // Reply with the sign-up validity status
  event.reply('signup-data', { isValidSignUp });
});

/**
 * Handles login requests, validates user credentials, and replies with the login status.
 *
 * @param {Electron.IpcMainEvent} event - The event object used for replying to the renderer process.
 * @param {object} data - The data object containing username and password for login.
 * @param {string} data.username - The username provided for login.
 * @param {string} data.password - The password provided for login.
 * @returns {void} Replies with the login status.
 */
ipcMain.on('login-data', (event, data) => {
  const { username, password } = data;
  let isValidLogin = false;
  const userData = settings.getSync(username);

  // Check if the provided password matches the stored password
  if (userData.password === password) {
    isValidLogin = true;
  }

  // Reply with the login status
  event.reply('login-data', { isValidLogin });

    // Provides the dashboard page with the username
  event.reply('provide-username', { username });
});


ipcMain.on('request-parameters', (event) => {
  
});


// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on("ready", createWindow);

// Our App code goes here
