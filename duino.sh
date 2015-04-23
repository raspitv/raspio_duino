#!/bin/bash
# script to auto-install all the RasPiO Duino sketches on Pi

# create sketchbook directory if doesn't exist
mkdir /home/pi/sketchbook

# give it the right permissions
chmod 755 /home/pi/sketchbook

# go to the /gome/pi directory
cd /home/pi

# clone the RasPiO Duino github repo
git clone https://github.com/raspitv/raspio_duino.git

# move the Python scripts to the /home/pi directory
mv /home/pi/raspio_duino/*.py /home/pi

# copy all the sketches to the sketchbook
cp -r /home/pi/raspio_duino/* /home/pi/sketchbook
