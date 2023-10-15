import React, {useState} from 'react'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";



// function WriteLogin (username, password) {
//     fs.writeFile('../assets/users.json', JSON.stringify(username), 'utf8', (err) => {
//         if (err) {
//             console.error(err);
//             return;
//         }
// }

function LogInForm({displayDashboard}) {
  return (
    <>
        <div className='form-header-div'>
            <h1 className='form-header-text'>Log In</h1>
            <SvgHeart id="heart-image"/>
        </div>
        <form>
            <div id='form-inputs-div'>
                {/* <label htmlFor="username"/> */}
                <input type="text" id="username" name="username" placeholder='Username' className='form-text-input'/>
                {/* <label htmlFor="password"/> */}
                <input type="text" id="password" name="password" placeholder='Password' className='form-text-input'/>
                <button className='decorative-button' onClick={() => {displayDashboard()}}>Log In</button>
            </div>
        </form>
    </>
  )
}

export default LogInForm