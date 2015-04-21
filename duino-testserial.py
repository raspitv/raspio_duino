import serial
import subprocess
import sys
from time import sleep

def print_there(x, y, text):  # define function to overprint previous output
    sys.stdout.write("\x1b7\x1b[%d;%df%s\x1b8" % (x, y, text))
    sys.stdout.flush()

subprocess.Popen("clear", shell=True)          # clear the screen to start

while True:
    sport = serial.Serial("/dev/ttyAMA0", 9600, timeout=1) # open serial port
    try:                                       # stops program failing 
        response = sport.readlines(None)       # if no serial data
        sport.close()

    except:
        sport.close()
        
    if not response:                           # stops program failing 
        print "no serial data read"            # if no serial data
        sleep(0.5)
        continue                               # skip to top of loop and retry

    print_there(1,2,response)                  # show raw ATMEGA output for A0

    # this last block chops up, formats & displays the output for us
    if response[0].startswith("ID0"):
        volts = float(response[0].split()[1])
        adcval = response[0].split()[4]
        output = ''.join(("Volts: ","{:.3f}".format(volts)," V   ", 
                 "ADC: ", adcval,"  "))
        print_there(2,2,output)
    sleep(1)