import React, { Component, useState } from 'react'
import { ipcRenderer } from 'electron'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

class EgramData extends Component{
  constructor(props){
    //constructor code goes here
  }

  //class methods and variables go here
}

function requestUsername() {
  // Description: Initiates a request for a username using inter-process communication (IPC).
  // Sends a signal to the main process to request a username.
  // Listens for a response event ('provide-username') from the main process.
  // If the response is received, extracts the username from the event data and logs "there" to the console.

  ipcRenderer.send('request-username');
  ipcRenderer.on('provide-username', (event, data) => {
    const { username } = data;
    console.log("there");
  });
}


function DashboardPage({ displayLoginPage}) {

//   Description: Functional component representing the dashboard page of a web application.
// Props:
//   - displayLoginPage: A function passed as a prop for logging out and displaying the login page.

// State Variables:
//   - LRL, URL, AA, VA, VPW, VRP, ARP: State variables to store input values for various parameters.

// UI Elements and Logic:
//   - Renders a form with input fields for configuring pacemaker parameters.
//   - Allows users to input values for Lower Rate Limit (LRL), Upper Rate Limit (URL),
//     Atrial Amplitude (AA), Ventricular Amplitude (VA), Ventricular Pulse Width (VPW),
//     VRP (Ventricular Refractory Period), and ARP (Atrial Refractory Period).
//   - Updates corresponding state variables when input values change.
//   - Provides a button to update the pacemaker settings, but the logic for updating is not implemented in this code.
//   - Provides a "Log Out" button that triggers the displayLoginPage function passed as a prop.

// Note: Certain parts of the code are commented out and not active (like the requestUsername function and StoreParameters function).
// These parts might be placeholders or incomplete implementations.


  // requestUsername();

  //console.log("i swaer to god");


  const [LRL, setLRL] = useState('');
  const [URL, setURL] = useState('');
  const [AA, setAA] = useState('');
  const [VA, setVA] = useState('')
  const [VPW, setVPW] = useState('')
  const [VRP, setVRP] = useState('')
  const [ARP, setARP] = useState('')

  // function StoreParameters() {
  //   ipcRenderer.send('')
  // }

  return (

    <div className='form-div'>
      <div className='form-header-div'>
        <h1 className='form-header-text'>Dashboard</h1>
        <SvgHeart id="heart-image" />
      </div>
      <div className='parameter-entry-div'>
        <label>Lower Rate Limit: </label><input type='number' id='LRL' onChange={event => setLRL(event.target.value)}></input><br></br>
        <label>Upper Rate Limit: </label><input type='number' id='URL' onChange={event => setURL(event.target.value)}></input><br></br>
        <label>Atrial Amplitude: </label><input type='number' id='AA' onChange={event => setAA(event.target.value)}></input><br></br>
        <label>Ventricular Amplitude: </label><input type='number' id='VA' onChange={event => setVA(event.target.value)}></input><br></br>
        <label>Ventricular Pulse Width: </label><input type='number' id='VPW' onChange={event => setVPW(event.target.value)}></input><br></br>
        <label>VRP: </label><input type='number' id='VRP' onChange={event => setVRP(event.target.value)}></input><br></br>
        <label>ARP: </label><input type='number' id='ARP' onChange={event => setARP(event.target.value)}></input><br></br>
      </div>
      <button className='decorative-button' >Update PaceMaker</button>
      <button 
      className='small-button' 
      onClick={ () => { displayLoginPage()}}>
        Log Out</button>
    </div>
  )
}

export default DashboardPage