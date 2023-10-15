import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";



function SignUpForm({displayDashboardPage}) {
    
    const [signupText, setSignupText] = useState("Sign Up!")
        
    function WriteSignIn (username, password) {
        setSignupText("Thanks for signing up... Redirecting");
        setTimeout(() => {
            displayDashboardPage();
        }, 1500);
    }

  return (
    <div className='form-div'>
        <div className='form-header-div'>
            <h1 className='form-header-text'>Sign Up</h1>
            <SvgHeart id="heart-image"/>
        </div>
            <div id='form-inputs-div'>
                <input type="text" id="username" name="username" placeholder='Username' className='form-text-input'/>
                <input type="text" id="password" name="password" placeholder='Password' className='form-text-input'/>
                <button className='decorative-button' onClick={()=>{WriteSignIn()}}>{signupText}</button>
            </div>
    </div>
  )
}
export default SignUpForm