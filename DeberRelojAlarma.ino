#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int segundosrel = 0 ;
int minutosrel = 0 ;
int horasrel = 0 ;
int alarma = 0;
int alaract = 0;
int apagar = 0;
int back=0;
int i = 0;
int j = 0;
String h;
String m;
String s;

void setup() {
  lcd.begin(16, 2);
  attachInterrupt(0, alarma, LOW);
  attachInterrupt(0, activar, LOW);
  attachInterrupt(1, seleccion, LOW);
  MsTimer2::set(10, reloj);
  MsTimer2::start();
  LCD.setCursor(1, 0);
  LCD.print("RELOJ");
  LCD.setCursor(1, 1);
  LCD.print("00:");
  LCD.setCursor(4, 1);
  LCD.print("00:");
  LCD.setCursor(7, 1);
  LCD.print("00");
  LCD.setCursor(10, 0);
  LCD.print("OFF");
  pinMode(indicador, OUTPUT);
  i = EEPROM.read(0);
  j = EEPROM.read(1);
}
void loop() {
  if (alaract == 1) {
    if (Serial.available() > 0)
      if (alarma.length() == 5) {
        i = alarma.substring(3, 0).toInt();
        j = alarma.substring(3, 5).toInt();
        lcd.setCursor(5, 0);
        lcd.print("ACTIVADA");
        alarma = 0;
      }
  }}
void reloj() {
  if (segundosrel < 59) {
    segundosrel++;
    s = String(segundosrel);
    if (s.length() == 1) {
      lcd.setCursor(6, 1);
      lcd.print("0");
      lcd.setCursor(5, 1);
      lcd.print(segundosrel);
    }
    else {
      lcd.setCursor(6, 1);
      lcd.print("segundosrel");
    }
  }
  else {
    if (minutosrel < 59) {
      lcd.setCursor(3, 1);
      lcd.print("00");
      segundosrel = 0;
      minutosrel++;
      m = String(minutosrel);
      if (m.length() == 1) {
        lcd.setCursor(2, 1);
        lcd.print("0");
        lcd.setCursor(3, 1);
        lcd.print(minutosrel);
      }
      else {
        lcd.setCursor(2, 1);
        lcd.print(minutosrel);
      }
    }
    else {
      if horasrel < 23) {
      lcd.setCursor(2, 1);
        lcd.print("00");
        minutosrel = 0;
        segundosrel = 0;
        horasrel++;
        h = String(horasrel);
        if (h.length() == 1) {
          lcd.setCursor(1, 1);
          lcd.print("0");
        }
        else {
          lcd.setCursor(1, 1);
          lcd.print(horasrel);
        }
      }
    }
  }
}
}

void seleccion() {
  lcd.clear();
  switch (sel) {
case0:
      sel++;
      lcd.setCursor(0, 1);
      lcd.print("Alarma ON");
      break;
case1:
      if (sel == 1) {
        lcd.setCursor(0, 1);
        lcd.print("Ingrese Alarma");
      }
  }
}
void activar() {
  if (act == 1) {
    lcd.setCursor(0, 1);
    lcd.print("ACTIVADA");
  }
}
void backup() {
  if (back==1) {
    EEPROM.write(0, i);
    EEPROM.write(0, j);
  }
}
}
