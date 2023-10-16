import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";
import { ipcRenderer } from 'electron';

function LogInForm({displayPulseModePage, displayHomePage}) {
    // Description: Functional component representing the login form of a web application.

    // Props:
    //   - displayPulseModePage: Function passed as a prop to navigate to the pulse mode page upon successful login.
    //   - displayHomePage: Function passed as a prop to navigate back to the home page.
    
    // State Variables:
    //   - loginText: State variable to dynamically change the login button text based on login status.
    //   - username: State variable to store the input value for the username.
    //   - password: State variable to store the input value for the password.
    
    // Functionality:
    //   - Allows users to input a username and password.
    //   - Sends a request to the main process to validate the login credentials using IPC.
    //   - Displays different messages on the login button based on login status:
    //     - "Login": Initial state before attempting login.
    //     - "Thanks for logging in... Redirecting": After successful login, before redirecting to pulse mode page.
    //     - "Invalid credentials": If login credentials are incorrect, resets to "Login" after a brief delay.
    
    // UI Elements and Logic:
    //   - Displays a form with input fields for username and password.
    //   - Dynamically changes the login button text based on login status.
    //   - Provides a "Login" button to trigger the login attempt.
    //   - Provides a "Home" button to navigate back to the home page.

    const [loginText, setLoginText] = useState('Login');
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');

    function CheckLogin (username, password) {
        ipcRenderer.send('login-data', {username, password});
        ipcRenderer.on('login-data', (event, data) => {
            const { isValidLogin } = data;
            if (isValidLogin){
                setLoginText('Thanks for logging in... Redirecting');
                setTimeout(() => {
                    displayPulseModePage();
                }, 1500);
            }
            else{
                setLoginText('Ivalid credentials');
                setTimeout(() => {
                    setLoginText('Login')
                }, 1500)
            }
        });
    }

    return (
        <div className='form-div'>
            <div className='form-header-div'>
                <h1 className='form-header-text'>Log In</h1>
                <SvgHeart id="heart-image"/>
            </div>
                <div id='form-inputs-div'>
                    <input 
                    type="text" 
                    id="username" 
                    name="username" 
                    placeholder='Username' 
                    className='form-text-input'
                    onChange={event => setUsername(event.target.value)}
                    />
                    <input 
                    type="text" 
                    id="password" 
                    name="password" 
                    placeholder='Password' 
                    className='form-text-input'
                    onChange={event => setPassword(event.target.value)}
                    />
                    <button 
                    className='decorative-button' 
                    onClick={() => {CheckLogin(username, password)}}>
                        {loginText}
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

export default LogInForm