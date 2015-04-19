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
  ser.write(chr)
  time.slep(.001)
  a = ser.read()
  ser.close()
  return a
  
@app.route("/")
def hello():
  pot = arduino('0')
  water = arduino('1')
  coffee = arduino('2')
  return ""+pot+water+coffee
  
if __name__=="__main__":
  app.run(host='0.0.0.0', port 80, debug(True)
