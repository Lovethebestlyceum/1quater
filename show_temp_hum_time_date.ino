#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1307);
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
const int buttonupPin = 9 ;
const int buttonsetPin = 10 ;
const int buttondownPin = 11  ;
LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long timenow;
void setup()
{
  pinMode(buttonupPin , INPUT_PULLUP);
  pinMode(buttondownPin, INPUT_PULLUP);
  pinMode(buttonsetPin, INPUT_PULLUP);
  delay(300);
  Serial.begin(9600);
  time.begin();
  lcd.begin();
  dht.begin();
  lcd.backlight();
}
void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print(time.gettime("d-m"));
  lcd.setCursor(8, 0);
  lcd.print(time.gettime( "H:i:s"));
  Serial.println(time.gettime( "H:i:s"));
  lcd.setCursor(1, 1);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(8, 1);
  lcd.print("H:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(5,0);
  lcd.print("   ");
   lcd.setCursor(6,1);
  lcd.print("  ");
   lcd.setCursor(13,1);
  lcd.print("    ");
}
