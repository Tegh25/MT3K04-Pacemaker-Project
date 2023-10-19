import React, { useState } from 'react';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";


function PulseModePage({ displayLoginPage, displayDashboardPage}) {

//     Description: Functional component representing the pulse mode selection page of a pacemaker configuration application.

// Props:
//   - displayLoginPage: Function passed as a prop to navigate to the login page.
//   - displayDashboardPage: Function passed as a prop to navigate to the dashboard page with selected pulse mode.

// State Variables:
//   - mode: Variable used to store the selected pulse mode (AOO, VOO, AAI, VVI).

// Functionality:
//   - Allows users to select a pulse mode (AOO, VOO, AAI, VVI) by clicking corresponding buttons.
//   - Sets the 'mode' variable based on the selected pulse mode.
//   - Provides buttons to choose different pulse modes and a "Log out" button to navigate back to the login page.

// UI Elements and Logic:
//   - Displays a form with buttons for selecting different pulse modes.
//   - Clicking a mode button updates the 'mode' variable and triggers the displayDashboardPage function passed as a prop.
//   - Provides a "Log out" button to navigate back to the login page.

    let mode = "";

    function modeAOO(){
        mode = "AOO";
        displayDashboardPage()
    }
    function modeVOO(){
        mode = "VOO";
        displayDashboardPage()
    }
    function modeAAI(){
        mode = "AAI";
        displayDashboardPage()
    }
    function modeVVI(){
        mode = "VVI";
        displayDashboardPage()
    }

    return (
        <div className='form-div'>
            <div className='form-header-div'>
                <h1 className='form-header-text'>Please Choose Pulse Mode</h1>
                <SvgHeart id="heart-image" />
            </div>
            <div id='form-inputs-div'>
                <button className='decorative-button' onClick={()=>modeAOO()}>AOO</button>
                <button className='decorative-button' onClick={()=>modeAAI()}>VOO</button>
                <button className='decorative-button' onClick={()=>modeVOO()}>AAI</button>
                <button className='decorative-button' onClick={()=>modeVVI()}>VVI</button>
            </div>
            <button className='small-button' onClick={() => {displayLoginPage()}}>Log out</button>
        </div>
    )
}

export default PulseModePage;