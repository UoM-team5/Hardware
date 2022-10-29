import tkinter as tk
from tkinter import ttk
import serial
import time
# 
arduino = serial.Serial(port='COM7', baudrate=115200, timeout=.1)

LARGE_FONT= ("Verdana", 13)

# Send stuff to arduino through Serial
def write(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)


# UI 
class Main(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        tk.Tk.wm_title(self, "Valve controller")

        container = tk.Frame(self)
        container.pack(side="top", fill = "both", expand = True)
        container.grid_rowconfigure(0, weight= 1)
        container.grid_columnconfigure(0, weight= 1)

        self.frames = {}

        for F in (StartPage, PageOne):
            frame = F(container, self)
            self.frames[F] = frame
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):

        frame = self.frames[cont]
        frame.tkraise()
        

class StartPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text = "the Start Page", font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="I want to control my valve",
         command=lambda: controller.show_frame(PageOne))
        button1.pack()

class PageOne(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text = "Valve controller", font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Home",
         command=lambda: controller.show_frame(StartPage))
        button1.pack()

        button2 = ttk.Button(self, text="close valve",
         command=lambda: write("0"))
        button2.pack()

        button3 = ttk.Button(self, text="open valve",
         command=lambda: write("1"))
        button3.pack()


gui=Main()
gui.mainloop()