import React from 'react'
import { ReactComponent as SvgLogo } from "../assets/logo.svg";


function DisplayLogo() {
  return (
    <div id='logo-image-div'>
        <SvgLogo/>
    </div>
  )
}
export default DisplayLogo