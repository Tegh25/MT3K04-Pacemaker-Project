import React from 'react'
import { ReactComponent as SvgLogo } from "../assets/logo.svg";


function DisplayLogo() {

//   Description: Functional component responsible for displaying a logo using SVG graphics.

// UI Elements:
//   - Renders an <SvgLogo /> component wrapped inside a <div> element with the id 'logo-image-div'.

// Note: The specific implementation details of the SvgLogo component are not provided here, 
// but it is presumed to be a custom SVG graphic representing the logo of the application.

  return (
    <div id='logo-image-div'>
        <SvgLogo/>
    </div>
  )
}
export default DisplayLogo