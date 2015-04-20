/*
  BlinkPWM_flip_flop_RGB pulses each colour of an RGB LED 
  from Min (0) to Max (255) and back again, repeatedly. 
 */

int time_delay = 2;   // set time delay (mS) duration here

void setup() {                
  for (int rgbPin = 9; rgbPin < 12; rgbPin++) {
    pinMode(rgbPin, OUTPUT); // set pins 9-11 as outputs
  }
}

void loop() { 
   for (int rgbPin = 9; rgbPin < 12; rgbPin++) {
               // fade rgbPin from off (0) to brightest (255)
      for (int brightness = 0; brightness < 255; brightness++) {
         analogWrite(rgbPin, brightness);
         delay(time_delay);
      } 
               // fade rgbPin from brightest (255) to off (0)
      for (int brightness = 255; brightness >= 0; brightness--) {
         analogWrite(rgbPin, brightness);
         delay(time_delay);
      }
   } 
}
