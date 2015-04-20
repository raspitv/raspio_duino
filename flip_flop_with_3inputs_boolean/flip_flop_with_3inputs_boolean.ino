/*
  Adjust our flip-flop, so that when pin 8 or 7 or 6 is HIGH
  the flashing is fast
 */

int led = 13;           // set pin 13 LED variable name
int newled = 5;         // add our second LED on pin 5
int time_delay = 500;   // set time delay (mS) duration here

void setup() {                
  pinMode(led, OUTPUT);       // set up LED pin 13 as output
  pinMode(newled, OUTPUT);    // set second LED pin 5 as output
  pinMode(8, INPUT);          // set up pin 8 as an input
  pinMode(7, INPUT);          // set up pin 7 as an input
  pinMode(6, INPUT);          // set up pin 6 as an input
}

// the loop routine runs over and over again forever:
void loop() {
  // if any pin 6 or 7 or 8 is HIGH
  if (digitalRead(6) || digitalRead(7) || digitalRead(8)) {
    time_delay = 250;             // set delay to 250
  }
  else {
    time_delay = 1000;
  }
  digitalWrite(led, HIGH);    // turn LED ON (HIGH is the voltage level)
  digitalWrite(newled, LOW);  // turn newLED OFF (LOW is the voltage level)
  delay(time_delay);          // wait for time_delay
  digitalWrite(led, LOW);     // turn LED OFF by making the voltage LOW
  digitalWrite(newled, HIGH); // turn LED ON by making the voltage HIGH
  delay(time_delay);          // wait for time_delay
}

