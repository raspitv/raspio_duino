/*
  BlinkPWM_loop pulses an LED from Min (0) to Max (255) 
  and back again, repeatedly.
 */

// name our PWM pin:
int led = 5;

void setup() {                
  pinMode(led, OUTPUT);  // set pin as output 
}

void loop() {
               // fade led pin from off (0) to brightest (255)
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(led, brightness);
      delay(2);    // 2ms delay between steps
    } 
               // fade led pin from brightest (255) to off (0)
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(led, brightness);
      delay(2);    // 2ms delay between steps
    } 
}
