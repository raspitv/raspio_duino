/*
  BlinkPWM sets an LED to Max (255) for one second, 
  then Min (50) for one second, repeatedly.
 */

// name our PWM pin:
int led = 5;

void setup() {                
  pinMode(led, OUTPUT);  // set pin as output 
}

void loop() {
  analogWrite(led, 255); // set LED to Maximum (255)
  delay(1000);           // wait for a second
  analogWrite(led, 50);  // set LED to Minimum (50)
  delay(1000);           // wait for a second
}
// analogWrite accepts values from 0 to 255 (8 bit)
