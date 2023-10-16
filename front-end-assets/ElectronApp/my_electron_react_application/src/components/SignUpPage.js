import React, {useState} from 'react';
import { ipcRenderer } from 'electron';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function SignUpForm({displayPulseModePage, displayHomePage}) {

    const signUpValidationEnum = {
        VALID: 1,
        USERNAMETAKEN: 2,
        TOOMANYUSERNAMES: 3
    }
    
    const [signupText, setSignupText] = useState('Sign Up');
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
        
    function StoreSignIn (username, password) {
        if(username && password){
            ipcRenderer.send('signup-data', {username, password, signUpValidationEnum});
            ipcRenderer.on('signup-data', (event, data) => {
                const { isValidSignUp } = data;
                if(isValidSignUp == signUpValidationEnum.VALID) {
                    setSignupText('Thanks for signing up... Redirecting');
                    setTimeout(() => {
                        displayPulseModePage();
                    }, 1500);
                }
                else if(isValidSignUp == signUpValidationEnum.USERNAMETAKEN){
                    setSignupText('Username taken... Try again');
                    setTimeout(() => {
                        setSignupText('Sign up')
                    }, 1500);
                }
                else if(isValidSignUp == signUpValidationEnum.TOOMANYUSERNAMES){
                    setSignupText('Too many users... Redirecting');
                    setTimeout(() => {
                        displayHomePage();
                    }, 1500);
                }
            });
        }
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
                onClick={() => {StoreSignIn(username, password)}}>
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