/*
LDR_LED - sketch to read the light level on an LDR and 
alter the brightness of an LED in response to it
*/
int ADCpin = 0;              // define the variables
int LEDpin = 5;
int LEDbrightness = 0;

void setup() {
  pinMode(LEDpin,OUTPUT);    // set up output pin
}

void loop() {
      // read our analog pin
      analogRead(ADCpin);    // first ADC reading is discarded
      delay(20);
      int reading = 0;       // now we read the ADC pin 'proper'
      reading = analogRead(ADCpin);
      delay(20);             // short pause avoids over-sampling

      reading = 1023 - reading;          // invert ADC reading
      // map ADC reading from 10 bit (1023) to 8 bit (255)
      LEDbrightness = map(reading, 0, 1023, 0, 255);
      analogWrite(LEDpin, LEDbrightness);
}
