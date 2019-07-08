/*
   DEBER Timer1 Seguridad domótica
*/
#include <TimerOne.h>
#include <MsTimer2.h>

int contrase = 0;
String pswd;
boolean validar;
int cont = 0;
int horero, minutero, segundero;
int activar = 0;
int rnd;

void setup() {
  MsTimer2::set(500, reloj);
  MsTimer2::start();
//  attachInterrupt(0, funcionamiento, LOW);
  Serial.begin(9600);
  Timer1.initialize(500000);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (contrase == 1) {
    if (Serial.available() > 0) {
      pswd = Serial.readString();
      validar = pswd.equals("qwerty");
      if (validar == true) {
        Serial.print("Contraseña Correcta");
        delay(500);
        activar = 1;
      }
      else {
        Serial.print("Contraseña Inorrecta");
        delay(500);
        activar = 0;
      }
    }
  }
}


void reloj() {
  if (segundero < 60) {
    Serial.print(horero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(segundero);
    segundero++;
  }
  else {
    segundero = 0;
    if (minutero < 60) {
      Serial.print(horero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.println(segundero);
      minutero++;

    }
    else {
      minutero = 0;
      if (horero < 12) {
        Serial.print(horero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.println(segundero);
        horero++;
        if (activar == 1) {
          if (horero > 12) {
            rnd = random(0, 2);
            digitalWrite(4, rnd);
            rnd = random(0, 2);
            digitalWrite(5, rnd);
            rnd = random(0, 2);
            digitalWrite(6, rnd);
            rnd = random(0, 2);
            digitalWrite(7, rnd);
            rnd = random(0, 2);
            digitalWrite(8, rnd);
            Serial.print("ENCENDIDAS");
        }
      }
    }
    else {
      horero = 0;
    }
  }
}
}
