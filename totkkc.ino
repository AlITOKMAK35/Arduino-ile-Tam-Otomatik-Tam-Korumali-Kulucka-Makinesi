#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6,7,8);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);

#include <dht11.h>  // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 9  // DHT11PIN olarak Dijital 2'yi belirliyoruz.
dht11 DHT11;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define fan 10
#define noz 11
#define ampul 12
#define motor 13

unsigned long eskizaman = 0;
unsigned long yenizaman;

void setup() {
  Serial.begin(9600);
  mySerial.begin(115200);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  myRTC.setDS1302Time(00, 0, 3, 0, 1, 1, 2014);

  lcd.clear();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("KULUCKA MAKINESI");
  lcd.setCursor(0, 1);
  lcd.print("EEM429 GRUP I_15 ");
  delay(5000);

  lcd.clear();
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read());  //Forward what Serial received to Software Serial Port
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read());  //Forward what Software Serial received to Serial Port
  }
}

void mesaj() {
  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1");
  updateSerial();
  mySerial.println("AT+CMGS=\"+905378862682\"");  // enter your phone number here (prefix country code)
  updateSerial();
  mySerial.print(DHT11.temperature);  // enter your message here
  updateSerial();
  mySerial.print(DHT11.humidity);  // enter your message here
  updateSerial();
  mySerial.write(26);
}

void loop() {
  yenizaman = millis();
  int chk = DHT11.read(DHT11PIN);
  myRTC.updateTime();
  Serial.println(myRTC.minutes);
  Serial.println(myRTC.seconds);

  Serial.print(myRTC.minutes);
  if (myRTC.dayofmonth < 18)

  {

    if ((float)DHT11.temperature <= 30) {
      digitalWrite(ampul, HIGH);
      digitalWrite(fan, LOW);
    } else if ((float)DHT11.temperature >= 32) {
      digitalWrite(fan, HIGH);
      digitalWrite(ampul, LOW);
    }

    if ((float)DHT11.humidity >= 60.0) {
      digitalWrite(fan, HIGH);
      digitalWrite(noz, LOW);
    } else if ((float)DHT11.humidity <= 55.0) {
      digitalWrite(noz, HIGH);
    }
  }

  if (myRTC.dayofmonth >= 18) {


    if ((float)DHT11.temperature <= 30) {
      digitalWrite(ampul, HIGH);
    } else if ((float)DHT11.temperature >= 32) {
      digitalWrite(fan, HIGH);
    }

    if ((float)DHT11.humidity >= 70) {
      digitalWrite(fan, HIGH);
    } else if ((float)DHT11.humidity <= 65.0) {
      digitalWrite(noz, HIGH);
    }
  }

  if (myRTC.minutes % 2 == 0) 
  {
    digitalWrite(motor, HIGH);
   if(myRTC.seconds % 30 == 0){
    mySerial.println("AT");
    updateSerial();

    mySerial.println("AT+CMGF=1");
    updateSerial();
    mySerial.println("AT+CMGS=\"+905378862682\"");  // enter your phone number here (prefix country code)
    updateSerial();
    mySerial.print("SICAKLIK :");
    mySerial.println((float)DHT11.temperature);  // enter your message here
    updateSerial();
    mySerial.print("NEM DEGERI :");
    mySerial.println((float)DHT11.humidity);  // enter your message here
    updateSerial();
    mySerial.print("GUN :");
    mySerial.println(myRTC.dayofmonth);  // enter your message here
    updateSerial();

    mySerial.write(26);
   }
   }
   else if (myRTC.minutes % 2 != 0) {
    digitalWrite(motor, LOW);
  }

  if (yenizaman - eskizaman >= 30) {

    lcd.setCursor(0, 0);
    lcd.print("SICAKLIK :");
    lcd.print((float)DHT11.temperature);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("NEM:%");
    lcd.print((float)DHT11.humidity, 1);
    lcd.print(" GUN:");
    lcd.print(myRTC.dayofmonth);
    eskizaman = yenizaman;
  }
}
