/* LCD Thermometer Sketch for RasPiO Duino 20x4 i2c LCD

Library version:1.1 from robot-r-us.com
Compatible with the Arduino IDE 1.0 and above
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int ADCpin = 0;                    // declare variables
int iterations = 10;
float voltage = 3.3;
float voltage1 = 3.3;
int reading = 0;
int reading1 = 0;

// set LCD i2c address to 0x27 and 20 char x 4 line display
LiquidCrystal_I2C lcd(0x27,20,4);  

void setup()
{
  lcd.init();                      // initialize lcd 
  lcd.backlight();
  lcd.setCursor(0, 0);             // go to column 0 row 0
  lcd.print("    i2c 20x4 LCD");   // Print txt on LCD
  lcd.setCursor(0, 1);
  lcd.print("     powered by");
  lcd.setCursor(0, 3); 
  lcd.print("    RasPiO Duino");
  delay(5000);
  lcd.clear();
}

void loop()
{
      analogRead(ADCpin);    // first ADC reading discarded
      delay(20);
      reading = 0;           // read ADC pin 0 10 times
      for (int loop = 0; loop < iterations; loop++)
      {
         reading += analogRead(ADCpin);
         delay(20);
      }  
      analogRead(1);
      delay(20);
      reading1 = 0;           // read ADC pin 1 10 times
      for (int loop = 0; loop < iterations; loop++)
      {
         reading1 += analogRead(1);
         delay(20);
      } 

      lcd.setCursor(0, 0);
      lcd.print(reading / iterations);
      lcd.print("    ");      
      lcd.print(reading1 / iterations);      
      lcd.print("    AD raw");

      voltage = reading / 1023.0 / iterations * 3.3;
      voltage1 = reading1 / 1023.0 / iterations * 3.3;        

      lcd.setCursor(0, 1);
      lcd.print(voltage, 3);   // print voltage to 3dp
      lcd.print("  ");
      lcd.print(voltage1, 3);
      lcd.print("  Volts");

      lcd.setCursor(0, 2);
      int temperature = voltage * 100 - 50;
      lcd.print(temperature);
      lcd.print((char)223);    // print degree symbol
      lcd.print("C   ");
      int temperature1 = voltage1 * 100 - 50;      
      lcd.print(temperature1);
      lcd.print((char)223);
      lcd.print("C   RasPiO");

      lcd.setCursor(0, 3);
      lcd.print("20x4 i2c LCD  Duino");
      delay(500);
}
