import React, {useState} from 'react';
import { ipcRenderer } from 'electron';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

function SignUpForm({displayPulseModePage, displayHomePage}) {

//     Description: Functional component representing the sign-up form of a web application.

// Props:
//   - displayPulseModePage: Function passed as a prop to navigate to the pulse mode page upon successful sign-up.
//   - displayHomePage: Function passed as a prop to navigate back to the home page.

// State Variables:
//   - signUpValidationEnum: Enum object defining validation states for sign-up.
//   - signupText: State variable to dynamically change the sign-up button text based on sign-up status.
//   - username: State variable to store the input value for the username during sign-up.
//   - password: State variable to store the input value for the password during sign-up.

// Functionality:
//   - Allows users to input a username and password for sign-up.
//   - Sends a request to the main process to validate the sign-up credentials using IPC.
//   - Displays different messages on the sign-up button based on sign-up status:
//     - "Sign Up": Initial state before attempting sign-up.
//     - "Thanks for signing up... Redirecting": After successful sign-up, before redirecting to pulse mode page.
//     - "Username taken... Try again": If the chosen username is already in use, resets to "Sign Up" after a brief delay.
//     - "Too many users... Redirecting": If the system has too many users, redirects to the home page after a brief delay.

// UI Elements and Logic:
//   - Displays a form with input fields for username and password.
//   - Dynamically changes the sign-up button text based on sign-up status.
//   - Provides a "Sign Up" button to trigger the sign-up attempt.
//   - Provides a "Home" button to navigate back to the home page.

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