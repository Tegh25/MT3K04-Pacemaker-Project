import React, {Component, useState} from 'react'
import SignUpForm from './SignUpForm';
import LogInForm from './LogInForm';
import { ReactDOM } from 'react';
import { ReactComponent as SvgHeart } from "../assets/heart.svg";

class WelcomePage extends Component {
    constructor(props){
        super(props)
        this.state = {
            displayDiv: <div>
                <h1>Welcome to your PaceMaker</h1>
                <button onClick={()=>this.signUpButton()}>Sign Up</button>
                <button onClick={()=>this.logInButton()}>Log In</button>
            </div>
        }
    }
    signUpButton() {
        this.setState({
            displayDiv: <div><SignUpForm/>
                <button onClick={()=>this.homeButton()}>Home</button>
            </div>
        })
    }

    logInButton(){
        this.setState({
            displayDiv: <div>
                <LogInForm/>
                <button onClick={()=>this.homeButton()}>Home</button>
            </div>
        })
    }

    homeButton(){
        this.setState({
            displayDiv: <div>
            <h1>Welcome to your PaceMaker</h1>
            <button onClick={()=>this.signUpButton()}>Sign Up</button>
            <button onClick={()=>this.logInButton()}>Log In</button>
        </div>
        })
    }

    render() {
        return (
            this.state.displayDiv
        )
    }
}
export default WelcomePage;