/*
  Adjust our flip-flop, so that when pin 8, 7 or 6 is HIGH
  the flashing is faster and when pin 8, 7 or 6 LOW it's slower
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int newled = 5;         // add our second LED on pin 5
int time_delay = 500;   // set time delay (mS) duration here
int input_value = 1;    // set our initial input value

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(newled, OUTPUT);    // set up our second LED as output
  pinMode(8, INPUT);          // set up pin 8 as an input
  pinMode(7, INPUT);          // set up pin 7 as an input
  pinMode(6, INPUT);          // set up pin 6 as an input
}

// the loop routine runs over and over again forever:
void loop() {
  time_delay = 1000;             // set delay to 1000 ms
  input_value = digitalRead(8);  // read our input pin 8
  if (input_value == 1) {        // if it's HIGH
    time_delay /= 2;             // set delay to half
  }
  input_value = digitalRead(7);  // read our input pin 7
  if (input_value == 1) {        // if it's HIGH
    time_delay /= 2;             // set delay to half
  }
  input_value = digitalRead(6);  // read our input pin 7
  if (input_value == 1) {        // if it's HIGH
    time_delay /= 2;             // set delay to half
  }
  digitalWrite(led, HIGH);    // turn LED ON (HIGH is the voltage level)
  digitalWrite(newled, LOW);  // turn newLED OFF (LOW is the voltage level)
  delay(time_delay);          // wait for time_delay
  digitalWrite(led, LOW);     // turn LED OFF by making the voltage LOW
  digitalWrite(newled, HIGH); // turn LED ON by making the voltage HIGH
  delay(time_delay);          // wait for time_delay
}
