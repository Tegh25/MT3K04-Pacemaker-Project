import React, {useState} from 'react'
import fs from 'fs'
import { ReactComponent as SvgHeart } from "../assets/heart.svg";



function WriteLogin (username, password) {
    // fs.writeFile('../assets/users.json', JSON.stringify(username), 'utf8', (err) => {
    //     if (err) {
    //         console.error(err);
    //         return;
        // }
}

function SignUpForm() {
  return (
    <div className='form-div'>
        <div className='form-header-div'>
            <h1 className='form-header-text'>Sign Up</h1>
            <SvgHeart id="heart-image"/>
        </div>
        <form>
            <div className='form-inputs-div'>
                {/* <label htmlFor="username"/> */}
                <input type="text" id="username" name="username" placeholder='Username' className='form-text-input'/>
                {/* <label htmlFor="password"/> */}
                <input type="text" id="password" name="password" placeholder='Password' className='form-text-input'/>
                <button className='decorative-button' onClick={WriteLogin}>Create Account</button>
            </div>
        </form>
    </div>
  )
}
export default SignUpForm