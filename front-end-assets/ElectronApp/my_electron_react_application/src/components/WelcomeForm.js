import React, {Component} from 'react'
import HomePage from './HomePage';
import SignUpPage from './SignUpPage';
import LoginPage from './LoginPage';
import DashboardPage from './DashboardPage';
import DisplayLogo from './DisplayLogo';

const PageEnum = {
    home: 1,
    signup: 2,
    login: 3,
    dashboard: 4
}

class WelcomeForm extends Component {
    constructor(props){
        super(props)
        this.state = {
            displayDiv: PageEnum.home
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
                <DashboardPage/>
            </>
        )
    }

    
    signUp = () => {
        this.setState({
            displayDiv: PageEnum.signup
        })
    }

    logIn = () => {
        this.setState({
            displayDiv: PageEnum.login
        })
    }

    home = () => {
        this.setState({
            displayDiv: PageEnum.home
        })
    }

    dashboard = () => {
        this.setState({
            displayDiv: PageEnum.dashboard
        })
    }

    render = () => {
        if(this.state.displayDiv==PageEnum.home){
            return this.displayHomePage()
        }
        else if(this.state.displayDiv==PageEnum.signup){
            return this.displaySignupPage()
        }
        else if(this.state.displayDiv==PageEnum.login){
            return this.displayLoginPage()
        }
        else if(this.state.displayDiv==PageEnum.dashboard){
            return this.displayDashboardPage()
        }
    }
}
export default WelcomeForm