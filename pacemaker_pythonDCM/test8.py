import tkinter as tk

def on_menuitem_click( bg, var ):
    global om, omvar
    om.configure( bg=bg )   # reset button's bg
    omvar.set( var )        # update manually

def add_menuitems_callback( menu, bg ):
    nitems = menu.index(tk.END) + 1
    for i in range (0, nitems):
        v = menu.entrycget( i, "label" )
        menu.entryconfigure( i, command = lambda bg=bg, v=v: on_menuitem_click(bg, v) )
     
root = tk.Tk()

# OptionMenu
omvar = tk.StringVar()
omvar.set( "Options" )
om = tk.OptionMenu( root, omvar, "One", "Two", "Three" )
abg = "light blue"
om.config( activebackground = abg )     # button's active-bg (onclick/onhover)
om.pack()

# add menu callback (force active-bg on the button when the menu pops up)
om['menu'].config( postcommand = lambda: om.config(bg=abg) )

# add menu-items callback (update omvar & reset button's bg when a menu-item is clicked)
add_menuitems_callback( om['menu'], om['bg'] )

# *** NEED TO ALSO RESET BUTTON's BG
# *** WHEN MENU CLOSES VIA OTHER MEANS
# *** (LIKE CLICKING OUTSIDE IT FOR EXAMPLE)

# show the beast
root.geometry( "360x200" )
root.mainloop()