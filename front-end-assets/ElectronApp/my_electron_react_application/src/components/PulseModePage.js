import React, { useState } from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";


function PulseModePage({ displayLogInPage, displayDashboardPage }) {
    

    return (
        <div className='form-div'>
            <div className='form-header-div'>
                <h1 className='form-header-text'>Please Choose Pulse Mode</h1>
                <SvgHeart id="heart-image" />
            </div>
            <div id='form-inputs-div'>
                <button className='decorative-button' >AOO</button>
                <button className='decorative-button' >VOO</button>
                <button className='decorative-button' >AAI</button>
                <button className='decorative-button' >VVI</button>
            </div>
            <button
                className='small-button'
                onClick={() => { displayLogInPage() }}>
                Log Out
            </button>
        </div>
    )
}

export default PulseModePage;