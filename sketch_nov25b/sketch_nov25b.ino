#include <MQ2.h>

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
  
int pin = A0;
int ledPin = 7;
  
MQ2 mq2(pin);

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  mq2.begin();
  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, LOW);
  delay(1000);
}

void loop(){
  digitalWrite(ledPin, LOW);
  float* values = mq2.read(true);
  float co = mq2.readCO();
  float smoke = mq2.readSmoke();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CO: ");
  lcd.setCursor(4,0);
  lcd.print(co);
  // Smoke
  lcd.setCursor(0,1);
  lcd.print("Smoke: ");
  lcd.setCursor(7,1);
  lcd.print(smoke);

  if (co > 2.0) {
    digitalWrite(ledPin, HIGH);
  }
  delay(2000);
}
