#include <avr/wdt.h>
#include <avr/sleep.h>
#include <EEPROM.h>
float datocad = 0;
byte est = LOW;

void setup() {
  est = EEPROM.read(0);
  Serial.begin(9600);
  Serial.println("Levantarse");

  if (est == LOW) {
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0, HIGH);
    wdt_enable(WDTO_8S);
  }
  else {
    sleep_disable();
    EEPROM.write(0, LOW);
    wdt_enable(WDTO_500MS);
  }
}

void loop() {
  if (est == LOW) {
    Serial.println("Durmiendo");
    delay(500);
    sleep_mode();
  }
  else {
    datocad = analogRead(A0);
    Serial.println("ACTIVADO");
    Serial.println(datocad);
    delay(500);
  }
}
