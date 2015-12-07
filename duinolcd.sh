#!/bin/bash
# script to auto-install RasPiO Duino LCD library/sketch

# go to the /home/pi directory
cd /home/pi

# grab the RasPiO Duino LCD zip file
wget http://rasp.io/duinoLCD.zip

# unzip the duinoLCD file
unzip /home/pi/duinoLCD.zip

# copy the library files to the library
sudo cp -r /home/pi/LiquidCrystal_I2C1602V1 /usr/share/arduino/libraries

# update local RasPiO Duino Git repo
cd /home/pi/raspio_duino
git pull

# copy LCD sketches to sketchbook
cp -r LCD* /home/pi/sketchbook

# clean up after ourself by removing installation files
rm -r /home/pi/__MACOSX
rm /home/pi/duinoLCD.zip
rm -r /home/pi/LiquidCrystal_I2C1602V1