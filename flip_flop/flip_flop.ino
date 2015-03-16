/*
  Make a flip-flop, which is an alternating pair of 
  LEDs or lights where one is on when the other is off
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int newled = 5;         // add our second LED on pin 5
int time_delay = 500;   // set time delay (mS) duration here

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(newled, OUTPUT);    // set up our second LED as output
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);    // turn LED ON (HIGH is the voltage level)
  digitalWrite(newled, LOW);  // turn newLED OFF (LOW is the voltage level)
  delay(time_delay);          // wait for time_delay
  digitalWrite(led, LOW);     // turn LED OFF by making the voltage LOW
  digitalWrite(newled, HIGH); // turn LED ON by making the voltage HIGH
  delay(time_delay);          // wait for time_delay
}
