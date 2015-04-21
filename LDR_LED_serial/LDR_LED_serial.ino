/*
LDR_LED_serial - sketch to read the light level on LDR, alter 
brightness of LED and report output to serial port
*/
int ADCpin = 0;                // define the variables
int LEDpin = 5;
int LEDbrightness = 0;

void setup() {
    pinMode(LEDpin,OUTPUT);    // set up output pin
    Serial.begin(9600);        // start serial port
}

void loop() {
    // read our analog pin
    analogRead(ADCpin);    // first ADC reading is discarded
    delay(20);
    int reading = 0;       // now we read the ADC pin 'proper'
    reading = analogRead(ADCpin);
    int adc = reading;     // we need to store this value now
    delay(20);             // short pause avoids over-sampling
                           // calculate voltage as a float
    float voltage = reading * 3.3 / 1023.0;
    
    reading = 1023 - reading;          // invert ADC reading
    // map ADC reading from 10 bit (1023) to 8 bit (255)
    LEDbrightness = map(reading, 0, 1023, 0, 255);
    analogWrite(LEDpin, LEDbrightness);

    // Write the output to serial port just how we want it
    Serial.print("ID");Serial.print(ADCpin);Serial.print(" ");
    Serial.print(voltage, 3);Serial.print(" V ");    
    Serial.print(" ADC: ");
    Serial.println(adc);       // println causes line break
    delay(1000);               // stops overloading serial
}
