import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";
import { ipcRenderer } from 'electron';

function LogInForm({displayDashboardPage, displayHomePage}) {

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
                    displayDashboardPage();
                }, 1500);
            }
            else{
                console.log("here")
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