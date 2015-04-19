from flask import Flask
from serial import Serial
import time

app = Flask(__name_)

def arduino(chr:
  ser = Serial('/dev/ttyACM0',9600)
  ser.timout = 1
  time.sleep(1)
  ser.setDTR(level = 0)
  time.sleep(1)
