# MT3K04-Pacemaker-Project
Running the DCM on your Local Device: This document assumes you have on your device VSCode along with NodeJS, HTML, CSS, and JavaScript If you do not contain any of the following please 
follow any process online to ensure all are donwloaded on your device.

Step 1: Download electron on your local device. Electron is a framework which was used in the design of the DCM on this device. It allows us to use React and other web Develpment software to create
a desktop application which is cross platform freindly. This is mainly due to the reason that we need to create desktop application and not a web application. To download electron you could run 
"npm install electron --save-dev" on your terminal or follow the guide on "https://www.electronjs.org/docs/latest/tutorial/installation". The link goes through a more extensive download of electron all of 
which might not be needed to run this application but should ensure that the application will run. 

Step 2: Download craco which stands for "Create React App Configuration Override". To download this follow the instructions on "https://www.npmjs.com/package/@craco/craco".

Step 3: Once all the above are downloaded peform a git pull command from this repositery to get all files on your local computer. 

Step 4: Make your way to the "my-electron-react-application" folder and perfrom the "npm run build" command followed by the "npm run start" command. This should open a desktop window on your device displaying the DCM. 

NOTE: If any issues are encountered during this process YOU SHOULD UTILIZE online resources to solve them. Issues such as not being able to download all the corresponding software needed to run the DCM.
