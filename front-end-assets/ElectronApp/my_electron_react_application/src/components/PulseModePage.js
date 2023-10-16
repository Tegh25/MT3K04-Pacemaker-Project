import React, { useState } from 'react';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";


function PulseModePage({ displayLoginPage, displayDashboardPage}) {

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
                <button className='decorative-button' >VOO</button>
                <button className='decorative-button' >AAI</button>
                <button className='decorative-button' >VVI</button>
            </div>
            <button className='small-button' onClick={() => {displayLoginPage()}}>Log out</button>
        </div>
    )
}

export default PulseModePage;