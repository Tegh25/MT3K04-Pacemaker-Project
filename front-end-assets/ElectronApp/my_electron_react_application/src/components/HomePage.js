import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function HomePage({displaySignUpPage, displayLoginPage}) {

//   Description: Functional component representing the home page of a web application.

// Props:
//   - displaySignUpPage: Function passed as a prop to navigate to the sign-up page.
//   - displayLoginPage: Function passed as a prop to navigate to the login page.

// UI Elements and Logic:
//   - Displays a form with a header and a heart-shaped image representing the home page of the application.
//   - Contains "Sign Up" and "Login" buttons allowing users to navigate to the sign-up and login pages respectively.
//   - When the "Sign Up" button is clicked, it triggers the displaySignUpPage function passed as a prop.
//   - When the "Login" button is clicked, it triggers the displayLoginPage function passed as a prop.


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