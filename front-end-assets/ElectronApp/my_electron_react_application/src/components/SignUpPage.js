import React, {useState} from 'react';
import { ipcRenderer } from 'electron';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function SignUpForm({displayDashboardPage, displayHomePage}) {
    
    const [signupText, setSignupText] = useState('Sign Up!');
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
        
    function WriteSignIn (username, password) {
        ipcRenderer.send('signup-data', {username, password});
        // console.log(settings.file())
        setSignupText('Thanks for signing up... Redirecting');
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
                <input 
                    type="text" 
                    id="username" 
                    placeholder='Username' 
                    className='form-text-input'
                    onChange={event => setUsername(event.target.value)}
                />
                <input 
                    type="text" 
                    id="password" 
                    placeholder='Password' 
                    className='form-text-input'
                    onChange={event => setPassword(event.target.value)}
                />
                <button 
                className='decorative-button' 
                onClick={() => {WriteSignIn(username, password)}}>
                    {signupText}
                </button>
            </div>
            <button 
            className='small-button'
            onClick={() => {displayHomePage()}}>
                Home
            </button>
    </div>
  )
}
export default SignUpForm