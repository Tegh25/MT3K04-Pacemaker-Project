import React, { useState } from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function DashboardPage({ displayHomePage, displayLoginPage }) {

  const [LRL, setLRL] = useState('');
  const [URL, setURL] = useState('');
  const [AA, setAA] = useState('');
  const [VA, setVA] = useState('')
  const [VPW, setVPW] = useState('')
  const [VRP, setVRP] = useState('')
  const [ARP, setARP] = useState('')

  return (

    <div className='form-div'>
      <div className='form-header-div'>
        <h1 className='form-header-text'>Dashboard</h1>
        <SvgHeart id="heart-image" />
      </div>
      <div id='form-inputs-div'>
        <label>Lower Rate Limit: </label><input type='number' id='LRL' onChange={event => setLRL(event.target.value)}></input><br></br>
        <label>Upper Rate Limit: </label><input type='number' id='URL' onChange={event => setURL(event.target.value)}></input><br></br>
        <label>Atrial Amplitude: </label><input type='number' id='AA' onChange={event => setAA(event.target.value)}></input><br></br>
        <label>Ventricular Amplitude: </label><input type='number' id='VA' onChange={event => setVA(event.target.value)}></input><br></br>
        <label>Ventricular Pulse Width: </label><input type='number' id='VPW' onChange={event => setVPW(event.target.value)}></input><br></br>
        <label>VRP: </label><input type='number' id='VRP' onChange={event => setVRP(event.target.value)}></input><br></br>
        <label>ARP: </label><input type='number' id='ARP' onChange={event => setARP(event.target.value)}></input><br></br>
      </div>
      <button className='decorative-button'>Update PaceMaker</button>
      <button 
      className='small-button' 
      onClick={ () => { displayLoginPage()}}>
        Log Out</button>
    </div>
  )
}

export default DashboardPage