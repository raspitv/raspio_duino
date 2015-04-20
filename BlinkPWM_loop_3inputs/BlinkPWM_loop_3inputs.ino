/*
  BlinkPWM_loop_3inputs pulses an LED from Min (0) to Max (255) 
  and back again, repeatedly. Speed controlled by 3 inputs.
 */

int led = 5;          // name our PWM pin:
int time_delay = 8;   // set time delay (mS) duration here
int input_value = 1;  // set our initial input value

void setup() {                
  pinMode(led, OUTPUT);  // set pin as output
  for (int thisPin = 6; thisPin < 9; thisPin++) {
    pinMode(thisPin, INPUT); // set pins 6-8 as inputs
  }
}

void loop() {
   time_delay = 8;                         // set default delay
   for (int thisPin = 6; thisPin < 9; thisPin++) { 
      input_value = digitalRead(thisPin);  // read input pin
      if (input_value == 1) {              // if it's HIGH
         time_delay /= 2;                  // set delay to half
      }   
   }    
               // fade led pin from off (0) to brightest (255)
   for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(led, brightness);
      delay(time_delay);
   } 
               // fade led pin from brightest (255) to off (0)
   for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(led, brightness);
      delay(time_delay);
   } 
}
