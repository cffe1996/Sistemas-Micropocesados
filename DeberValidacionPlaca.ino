/*
   Deber Verificacion placa de vehículos
*/


char    placa[7];
String  placaing;
boolean num, letras;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese el número de placa para verificar: ");
}

void loop() {
  if (Serial.available() > 0) {
    placaing = Serial.readString();
    placaing = placaing.substring(0, 3) + placaing.substring(4, placaing.length());
    if (placaing.length() == 6) {
      placaing = placaing.substring(0, 3) + "0" + placaing.substring(3, placaing.length());
    }   for (int i = 0; i < placaing.length(); i++) {
      placa[i] = placaing.charAt(i);
    }for (int i = 0; i < 3; i++) {
         if (placa[i] >= 'A' && placa[i] <= 'Z') {
          letras = true;
            for (int i = 3; i < 7; i++) {
              if (placa[i] >= '0' && placa[i] <= '9') {
              num = true;
            } else {
            num = false;
          }
        }
      } else {
        letras = false;
      }
    }
    if (num == true && letras == true) {
      Serial.println("");
      letraprovincias();
    } else {
      Serial.println("");
      Serial.println("No VALIDA");
    }
  }
}

void letraprovincias() {
  if (placa[0] == 'E') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Esmeraldas");
  }

  if (placa[0] == 'M') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Manabí");
  }

  if (placa[0] == 'R') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Los Ríos");
  }

  if (placa[0] == 'G') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Guayas");
  }

  if (placa[0] == 'Y') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Santa Elena");
  }

  if (placa[0] == 'O') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de El Oro");
  }

  if (placa[0] == 'C') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Carchi");
  }

  if (placa[0] == 'I') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Imbabura");
  }

  if (placa[0] == 'P') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Pichincha");
  }

  if (placa[0] == 'X') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Cotopaxi");
  }

  if (placa[0] == 'J') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Santo Domingo de los Colorados");
  }

  if (placa[0] == 'T') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Tungurahua");
  }

  if (placa[0] == 'B') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Bolívar");
  }

  if (placa[0] == 'H') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Chimborazo");
  }

  if (placa[0] == 'U') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Cañar");
  }

  if (placa[0] == 'A') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Azuay");
  }

  if (placa[0] == 'L') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Loja");
  }

  if (placa[0] == 'K') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Sucumbíos");
  }

  if (placa[0] == 'N') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Napo");
  }

  if (placa[0] == 'Q') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Orellana");
  }

  if (placa[0] == 'S') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Pastaza");
  }

  if (placa[0] == 'V') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Morona Santiago");
  }

  if (placa[0] == 'Z') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Zamora Chinchipe");
  }

  if (placa[0] == 'W') {
    Serial.println("Placa VALIDA");
    Serial.println("Pertenece a la Provincia de Galápagos");
  }
}
