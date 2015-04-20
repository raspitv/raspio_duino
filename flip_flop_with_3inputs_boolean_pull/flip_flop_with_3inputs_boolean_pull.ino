/*
  Adjust our Boolean flip-flop, to use pull-ups to avoid
  spurious input signals. We have to invert our logic as well.
 */

int led = 13;           // set pin 13 LED variable name
int newled = 5;         // add our second LED on pin 5
int time_delay = 500;   // set time delay (mS) duration here

void setup() {                
  pinMode(led, OUTPUT);       // set up LED pin 13 as output
  pinMode(newled, OUTPUT);    // set second LED pin 5 as output
  pinMode(8, INPUT_PULLUP);   // set up pin 8 as an input + pullup
  pinMode(7, INPUT_PULLUP);   // set up pin 7 as an input + pullup
  pinMode(6, INPUT_PULLUP);   // set up pin 6 as an input + pullup
}

// the loop routine runs over and over again forever:
void loop() {
  // if any pin 6 or 7 or 8 is LOW
  // notice the ! in front of each Read to "not" it
  if (! digitalRead(6) || ! digitalRead(7) || ! digitalRead(8)) {
    time_delay = 250;         // set delay to 250
  }
  else {
    time_delay = 1000;        // set (default delay)
  }
  digitalWrite(led, HIGH);    // turn LED ON (HIGH is the voltage level)
  digitalWrite(newled, LOW);  // turn newLED OFF (LOW is the voltage level)
  delay(time_delay);          // wait for time_delay
  digitalWrite(led, LOW);     // turn LED OFF by making the voltage LOW
  digitalWrite(newled, HIGH); // turn LED ON by making the voltage HIGH
  delay(time_delay);          // wait for time_delay
}