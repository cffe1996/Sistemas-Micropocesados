#include <EEPROM.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <avr/wdt.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int hora;
int minuto;
int segundo;
int i = 0;
int segundos = 10;
int minutos = 11;
String h, m, s;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  EEPROM.write(0, 0);
  if (EEPROM.read(2) == 0) {
    MsTimer2::set(100, reloj);
    MsTimer2::start();
    lcd.setCursor(3, 0);
    lcd.print("00");
    lcd.setCursor(5, 0);
    lcd.print(":");
    lcd.setCursor(6, 0);
    lcd.print("00");
    lcd.setCursor(8, 0);
    lcd.print(":");
    lcd.setCursor(9, 0);
    lcd.print("00");
  }
  if (EEPROM.read(2) == 1) {
    MsTimer2::set(100, reloj);
    MsTimer2::start();
    lcd.setCursor(3, 1);
    lcd.print("00");
    lcd.setCursor(5, 1);
    lcd.print(":");
    lcd.setCursor(6, 1);
    lcd.print("11");
    lcd.setCursor(8, 1);
    lcd.print(":");
    lcd.setCursor(9, 1);
    lcd.print("10");
  }
}
void loop() {

}
void reloj() {
  if (EEPROM.read(2) == 0) {
    if (segundo < 59) {
      segundo++;
      ss = String(segundo);
      if (s.length() == 1) {
        lcd.setCursor(7, 1);
        lcd.print("0");
        lcd.setCursor(8, 1);
        lcd.print(segundo);
      }
      else {
        lcd.setCursor(7, 1);
        lcd.print(segundo);
      }
      if (EEPROM.read(1) == 10) {
        if (segundo == 50) {
          EEPROM.update(2, 1);
          wdt_enable(WDTO_500MS);
        }
      }
    }
    else {
      if (minuto < 59) {
        lcd.setCursor(7, 1);
        lcd.print("00");
        segundo = 0;
        minuto++;
        sm = String(minuto);
        if (m.length() == 1) {
          lcd.setCursor(4, 1);
          lcd.print("0");
          lcd.setCursor(5, 1);
          lcd.print(minuto);
        }
        else {
          lcd.setCursor(4, 1);
          lcd.print(minuto);
        }
        if (minuto == 10) {
          EEPROM.update(1, 1);
        }
      }
      else {
        if (hora < 23) {
          lcd.setCursor(4, 1);
          lcd.print("00");
          minuto = 0;
          segundo = 0;
          hora++;
          h = String(hora);
          if (h.length() == 1) {
            lcd.setCursor(1, 1);
            lcd.print("0");
            lcd.setCursor(2, 1);
            lcd.print(hora);
          }
          else {
            lcd.setCursor(1, 1);
            lcd.print(hora);
          }
        }
      }
    }
  }
  if (EEPROM.read(2) == 1) {
    if (segundos < 59) {
      segundos++;
      s = String(segundos);
      if (ss.length() == 1) {
        lcd.setCursor(7, 1);
        lcd.print("0");
        lcd.setCursor(8, 1);
        lcd.print(segundos);
      }
      else {
        lcd.setCursor(7, 1);
        lcd.print(segundos);
      }
    }
    else {
      if (minutos < 59) {
        lcd.setCursor(7, 1);
        lcd.print("00");
        seg = 0;
        mint++;
        m = String(minutos);
        if (m.length() == 1) {
          lcd.setCursor(4, 1);
          lcd.print("0");
          lcd.setCursor(5, 1);
          lcd.print(minutos);
        }
        else {
          lcd.setCursor(4, 1);
          lcd.print(minutos);
        }
      }
      else {
        if (hora < 23) {
          lcd.setCursor(4, 1);
          lcd.print("00");
          minuto = 0;
          segundo = 0;
          hora++;
          h = String(hora);
          if (sh.length() == 1) {
            lcd.setCursor(1, 1);
            lcd.print("0");
            lcd.setCursor(2, 1);
            lcd.print(hora);
          }
          else {
            lcd.setCursor(1, 1);
            lcd.print(hora);
          }
        }
      }
    }
  }
}
