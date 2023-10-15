import React, {Component} from 'react'
import HomePage from './HomePage';
import SignUpPage from './SignUpPage';
import LoginPage from './LoginPage';
import DashboardPage from './DashboardPage';
import DisplayLogo from './DisplayLogo';

const PageEnum = {
    HOME: 1,
    SIGNUP: 2,
    LOGIN: 3,
    DASHBOARD: 4
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
                displayDashboardPage={this.dashboard}
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
                displayDashboardPage={this.dashboard}
                displayHomePage={this.home}
                />
            </>
        )
    }

    displayDashboardPage = () => {
        return(
            <>
                <DisplayLogo/>
                <DashboardPage
                displayHomePage={this.home}
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
        else if(this.state.displayDiv==PageEnum.DASHBOARD){
            return this.displayDashboardPage()
        }
    }
}
export default WelcomeForm