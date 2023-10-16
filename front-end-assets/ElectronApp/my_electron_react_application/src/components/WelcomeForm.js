import React, {Component} from 'react'
import HomePage from './HomePage';
import SignUpPage from './SignUpPage';
import LoginPage from './LoginPage';
import DashboardPage from './DashboardPage';
import DisplayLogo from './DisplayLogo';
import PulseModePage from './PulseModePage';

// Description: React component representing the main application logic for navigating between different pages.

// State Variables:
//   - displayDiv: Variable to track the currently displayed page using the PageEnum constants.

// Methods:
//   - displayHomePage: Method to render the home page with the option to sign up or log in.
//   - displaySignupPage: Method to render the sign-up page with the option to navigate to pulse mode or home.
//   - displayLoginPage: Method to render the login page with the option to navigate to pulse mode or home.
//   - displayPulseModePage: Method to render the pulse mode selection page with options to log out or go to the dashboard.
//   - displayDashboardPage: Method to render the dashboard page with the option to log out.

//   - signUp: Method to set the displayDiv state variable to show the sign-up page.
//   - logIn: Method to set the displayDiv state variable to show the login page.
//   - home: Method to set the displayDiv state variable to show the home page.
//   - pulseMode: Method to set the displayDiv state variable to show the pulse mode selection page.
//   - dashboard: Method to set the displayDiv state variable to show the dashboard page.

//   - render: Method to dynamically render different pages based on the displayDiv state variable.


const PageEnum = {
    HOME: 1,
    SIGNUP: 2,
    LOGIN: 3,
    PULSEMODE: 4,
    DASHBOARD: 5
}

class WelcomeForm extends Component {
    constructor(props){
        super(props)
        this.state = {
            displayDiv: PageEnum.HOME
        }
    }

    displayHomePage = () => {
        return(
            <>
                <DisplayLogo/>
                <HomePage 
                displaySignUpPage={this.signUp} 
                displayLoginPage={this.logIn}
                />
            </>
        )
    }

    displaySignupPage = () => {
        return(
            <>
                <DisplayLogo/>
                <SignUpPage
                displayPulseModePage={this.pulseMode}
                displayHomePage={this.home}
                />
            </>
        )
    }

    displayLoginPage = () => {
        return(
            <>
                <DisplayLogo/>
                <LoginPage
                displayPulseModePage={this.pulseMode}
                displayHomePage={this.home}
                />
            </>
        )
    }

    displayPulseModePage = () => {
        return (
            <>
                <DisplayLogo/>
                <PulseModePage
                displayLoginPage={this.logIn}
                displayDashboardPage={this.dashboard}
                />
            </>
        )
    }

    displayDashboardPage = () => {
        return(
            <>
                <DisplayLogo/>
                <DashboardPage
                displayLoginPage={this.logIn}
                />
            </>
        )
    }

    
    signUp = () => {
        this.setState({
            displayDiv: PageEnum.SIGNUP
        })
    }

    logIn = () => {
        this.setState({
            displayDiv: PageEnum.LOGIN
        })
    }

    home = () => {
        this.setState({
            displayDiv: PageEnum.HOME
        })
    }

    pulseMode = () => {
        this.setState({
            displayDiv: PageEnum.PULSEMODE
        })
    }

    dashboard = () => {
        this.setState({
            displayDiv: PageEnum.DASHBOARD
        })
    }

    render = () => {
        if(this.state.displayDiv==PageEnum.HOME){
            return this.displayHomePage()
        }
        else if(this.state.displayDiv==PageEnum.SIGNUP){
            return this.displaySignupPage()
        }
        else if(this.state.displayDiv==PageEnum.LOGIN){
            return this.displayLoginPage()
        }
        else if(this.state.displayDiv==PageEnum.PULSEMODE){
            return this.displayPulseModePage()
        }
        else if(this.state.displayDiv==PageEnum.DASHBOARD){
            return this.displayDashboardPage()
        }
    }
}
export default WelcomeForm