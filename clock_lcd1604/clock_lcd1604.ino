//#include <LiquidCrystal.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 12, A5, A4, A3, A2);

byte v1[8] = {31, 31, 31, 31, 31, 31, 31, 31};
byte v3[8] = { 0, 0, 0, 0, 31, 31, 31, 31};
byte v8[8] = { 31, 31, 31, 31, 0, 0, 0, 0};
byte v2[8] = {0, 0, 0, 0, 0, 0, 0b00011, 0b00011};
byte v4[8] = {0b00011, 0b00011, 0, 0, 0, 0, 0, 0};
byte v5[8] = {0, 0, 0, 0, 0, 0, 0b11000, 0b11000};
byte v6[8] = {0b11000, 0b11000, 0, 0, 0, 0, 0, 0};
byte v7[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int a[4];
byte i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, e1, e2, e3, e4;
unsigned long timer;
int8_t hour = 0;
int8_t minute = 0;
int8_t sec = 0;
bool dot;
uint8_t pauseButton = 150;

#define leftButton 3
#define rightButton 1
#define upButton 0
#define downButton 2

void setup() {
  lcd.begin(20, 4); //LCD columns and rows
  lcd.createChar(1, v1); lcd.createChar(2, v2); lcd.createChar(3, v3); lcd.createChar(4, v4);
  lcd.createChar(5, v5); lcd.createChar(6, v6); lcd.createChar(7, v7); lcd.createChar(8, v8);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
}

void loop() {

  if (!digitalRead(upButton)) {
    minute--;
    if (minute < 0)minute = 59;
    delay(pauseButton);
  }
  if (!digitalRead(downButton)) {
    hour++;
    if (hour > 23)hour = 0;
    delay(pauseButton);
  }
  if (!digitalRead(leftButton)) {
    hour--;
    if (hour < 0)hour = 23;
    delay(pauseButton);
  }
  if (!digitalRead(rightButton)) {
    minute++;
    if (minute > 59)minute = 0;
    delay(pauseButton);
  }

  if (millis() - timer > 1000) {
    timer = millis();
    dot = !dot;
    sec = sec + 1;
    if (sec > 59) {
      sec = 0;
      minute = minute + 1;
    }
    if (minute > 59) {
      minute = 0;
      hour = hour + 1;
    }
    if (hour > 23) {
      hour = 0;
    }
  }

  a[0] = hour / 10;
  a[1] = hour % 10;
  a[2] = minute / 10;
  a[3] = minute % 10;

  for (i = 0; i < 4; i++) {
    switch (i) {
      case 0: e1 = 0, e2 = 1, e3 = 2; e4 = 3; break;
      case 1: e1 = 5, e2 = 6, e3 = 7; e4 = 8; break;
      case 2: e1 = 11, e2 = 12, e3 = 13; e4 = 14; break;
      case 3: e1 = 16, e2 = 17, e3 = 18; e4 = 19; break;
    }

    switch (a[i]) {
      case 0: d1 = 1, d2 = 0, d3 = 0, d4 = 1, d5 = 1, d6 = 7, d7 = 7, d8 = 1, d9 = 1, d10 = 7, d11 = 7, d12 = 1, d13 = 1, d14 = 3, d15 = 3, d16 = 1; break;
      case 1: d1 = 7, d2 = 0, d3 = 1, d4 = 7, d5 = 7, d6 = 7, d7 = 1, d8 = 7, d9 = 7, d10 = 7, d11 = 1, d12 = 7, d13 = 7, d14 = 3, d15 = 1, d16 = 3; break;
      case 2: d1 = 1, d2 = 0, d3 = 0, d4 = 1, d5 = 7, d6 = 7, d7 = 7, d8 = 1, d9 = 1, d10 = 0, d11 = 0, d12 = 0, d13 = 1, d14 = 3, d15 = 3, d16 = 3; break;
      case 3: d1 = 0, d2 = 0, d3 = 0, d4 = 1, d5 = 7, d6 = 3, d7 = 3, d8 = 1, d9 = 7, d10 = 7, d11 = 7, d12 = 1, d13 = 3, d14 = 3, d15 = 3, d16 = 1; break;
      case 4: d1 = 1, d2 = 7, d3 = 7, d4 = 1, d5 = 1, d6 = 3, d7 = 3, d8 = 1, d9 = 7, d10 = 7, d11 = 7, d12 = 1, d13 = 7, d14 = 7, d15 = 7, d16 = 1; break;
      case 5: d1 = 1, d2 = 0, d3 = 0, d4 = 0, d5 = 1, d6 = 3, d7 = 3, d8 = 3, d9 = 7, d10 = 7, d11 = 7, d12 = 1, d13 = 1, d14 = 3, d15 = 3, d16 = 1; break;
      case 6: d1 = 1, d2 = 0, d3 = 0, d4 = 0, d5 = 1, d6 = 3, d7 = 3, d8 = 3, d9 = 1, d10 = 7, d11 = 7, d12 = 1, d13 = 1, d14 = 3, d15 = 3, d16 = 1; break;
      case 7: d1 = 1, d2 = 0, d3 = 0, d4 = 1, d5 = 7, d6 = 7, d7 = 7, d8 = 1, d9 = 7, d10 = 7, d11 = 7, d12 = 1, d13 = 7, d14 = 7, d15 = 7, d16 = 1; break;
      case 8: d1 = 1, d2 = 0, d3 = 0, d4 = 1, d5 = 1, d6 = 3, d7 = 3, d8 = 1, d9 = 1, d10 = 7, d11 = 7, d12 = 1, d13 = 1, d14 = 3, d15 = 3, d16 = 1; break;
      case 9: d1 = 1, d2 = 0, d3 = 0, d4 = 1, d5 = 1, d6 = 3, d7 = 3, d8 = 1, d9 = 7, d10 = 7, d11 = 7, d12 = 1, d13 = 3, d14 = 3, d15 = 3, d16 = 1; break;
    }

    lcd.setCursor(e1, 0); lcd.write((uint8_t)d1); lcd.setCursor(e2, 0); lcd.write((uint8_t)d2); lcd.setCursor(e3, 0); lcd.write((uint8_t)d3); lcd.setCursor(e4, 0); lcd.write((uint8_t)d4);
    lcd.setCursor(e1, 1); lcd.write((uint8_t)d5); lcd.setCursor(e2, 1); lcd.write((uint8_t)d6); lcd.setCursor(e3, 1); lcd.write((uint8_t)d7); lcd.setCursor(e4, 1); lcd.write((uint8_t)d8);
    lcd.setCursor(e1, 2); lcd.write((uint8_t)d9); lcd.setCursor(e2, 2); lcd.write((uint8_t)d10); lcd.setCursor(e3, 2); lcd.write((uint8_t)d11); lcd.setCursor(e4, 2); lcd.write((uint8_t)d12);
    lcd.setCursor(e1, 3); lcd.write((uint8_t)d13); lcd.setCursor(e2, 3); lcd.write((uint8_t)d14); lcd.setCursor(e3, 3); lcd.write((uint8_t)d15); lcd.setCursor(e4, 3); lcd.write((uint8_t)d16);
  }

  if (dot) {
    lcd.setCursor(9, 0); lcd.write((uint8_t)7); lcd.setCursor(9, 1); lcd.write((uint8_t)7); lcd.setCursor(10, 0); lcd.write((uint8_t)7); lcd.setCursor(10, 1); lcd.write((uint8_t)7);
    lcd.setCursor(9, 2); lcd.write((uint8_t)7); lcd.setCursor(9, 3); lcd.write((uint8_t)7); lcd.setCursor(10, 2); lcd.write((uint8_t)7); lcd.setCursor(10, 3); lcd.write((uint8_t)7);
  }
  else {
    lcd.setCursor(9, 0); lcd.write((uint8_t)2); lcd.setCursor(9, 1); lcd.write((uint8_t)4); lcd.setCursor(10, 0); lcd.write((uint8_t)5); lcd.setCursor(10, 1); lcd.write((uint8_t)6);
    lcd.setCursor(9, 2); lcd.write((uint8_t)2); lcd.setCursor(9, 3); lcd.write((uint8_t)4); lcd.setCursor(10, 2); lcd.write((uint8_t)5); lcd.setCursor(10, 3); lcd.write((uint8_t)6);
  }
}
