import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function HomePage({displaySignUpPage, displayLoginPage}) {
  return (
    <div className='form-div'>
      <div className='form-header-div'>
        <h1 className='form-header-text'>Welcome to your<br></br> PaceMaker</h1>
        <SvgHeart id="heart-image"/>
      </div>
      <div>
        <button className='decorative-button' onClick={() => {displaySignUpPage()}}>Sign Up</button>
        <button className='negative-decorative-button' onClick={() => {displayLoginPage()}}>Login</button>
      </div>    
    </div>
  )
}
export default HomePage