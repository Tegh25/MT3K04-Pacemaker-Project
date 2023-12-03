import tkinter as tk
import tkinter.ttk as ttk
from tkinter.constants import *
from platform import system as sys
class VerticalScrolledFrame(ttk.Frame):
    def __init__(self, parent, *args, **kw):
        def _configure_interior(event):
            size = (interior.winfo_reqwidth(), interior.winfo_reqheight())
            canvas.config(scrollregion="0 0 %s %s" % size)
            if interior.winfo_reqwidth() != canvas.winfo_width():
                canvas.config(width=interior.winfo_reqwidth())

        def _configure_canvas(event):
            if interior.winfo_reqwidth() != canvas.winfo_width():
                canvas.itemconfigure(interior_id, width=canvas.winfo_width())

        def _on_mousewheel(event, scroll=None):
            os = sys()
            if os == 'Windows':
                canvas.yview_scroll(int(-1*(event.delta/120)), "units")
            elif os == 'Darwin':
                canvas.yview_scroll(int(-1 * event.delta), "units")
            else:
                canvas.yview_scroll(int(scroll), "units")

        def _bind_to_mousewheel(event):
            os = sys()
            if os == 'Windows':
                canvas.bind_all("<MouseWheel>", lambda event : _on_mousewheel(event))
            elif os == 'Darwin':
                canvas.bind_all("<MouseWheel>", lambda event : _on_mousewheel(event))
            else:
                canvas.bind_all("<Button-4>", lambda event : _on_mousewheel(event, scroll=-1))
                canvas.bind_all("<Button-5>", lambda event : _on_mousewheel(event, scroll=1))

        def _unbind_from_mousewheel(event):
            os = sys()
            if os == 'Windows':
                canvas.unbind_all("<MouseWheel>")
            elif os == 'Darwin':
                canvas.unbind_all("<MouseWheel>")
            else:
                canvas.unbind_all("<Button-4>")
                canvas.unbind_all("<Button-5>")

        ttk.Frame.__init__(self, parent, *args, **kw)

        vscrollbar = ttk.Scrollbar(self, orient=tk.VERTICAL)
        vscrollbar.pack(fill=tk.Y, side=tk.RIGHT, expand=tk.FALSE)
        canvas = tk.Canvas(self, bd=0, highlightthickness=0,
                           yscrollcommand=vscrollbar.set)
        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.TRUE)
        vscrollbar.config(command=canvas.yview)

        canvas.xview_moveto(0)
        canvas.yview_moveto(0)

        self.interior = interior = ttk.Frame(canvas)
        interior_id = canvas.create_window(0, 0, window=interior,
                                           anchor=tk.NW)

        interior.bind('<Configure>', _configure_interior)
        canvas.bind('<Configure>', _configure_canvas)
        canvas.bind('<Enter>', _bind_to_mousewheel)
        canvas.bind('<Leave>', _unbind_from_mousewheel)

# Thanks to chlutz214 for the usage update:
if __name__ == "__main__":
        # Set Up root of app
        root = tk.Tk()
        root.geometry("400x500+50+50")
        root.title("VerticalScrolledFrame Sample")

        # Create a frame to put the VerticalScrolledFrame inside
        # holder_frame = tk.Frame(root)
        # holder_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.TRUE)

        # Create the VerticalScrolledFrame
        vs_frame = VerticalScrolledFrame(root)
        vs_frame.pack(side=tk.BOTTOM, fill=tk.BOTH, expand=tk.TRUE)

        # Fill the VerticalScrolledFrame
        i = 0
        while i != 500:
            # item = tk.Entry(vs_frame.interior)
            # item.insert(0, i)
            item = tk.Label(vs_frame.interior, text=i)
            item.pack(side=tk.TOP, fill=tk.X, expand=tk.TRUE)
            i = i + 1

        # Run mainloop to start app
        root.mainloop()