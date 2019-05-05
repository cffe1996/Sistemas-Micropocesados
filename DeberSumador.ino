//Puertos con entrada de datos digitales
int b3=3;
int b2=4;
int b1=5;
int led1=6;
int led2=7;
int on=0;

int cont1=0;
int cont2=0;
int A=11;
int B=10;
int C=9;
int D=8;
int decenas;
int unidades;
int dec=13;
int uni=12;
void setup() {
pinMode(b3,INPUT);  
pinMode(b2,INPUT);  
pinMode(b1,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(dec,OUTPUT);
pinMode(uni,OUTPUT);

}

void loop() {
  
                   //Boton 1                                  
 if(digitalRead(b1)==LOW)
 {
 delay(120); 
 digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
  if(cont1<25){
    cont1++;
  }else{
    cont1=0;
  }

     mostrar(cont1);
     
 }

        // Boton 2 
        if(digitalRead(b2)==LOW)
 {
 delay(120); 
 digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  if(cont2<25){
    cont2++;
  }else{
    cont2=0;
  }
     mostrar(cont2);  
 }

        // Boton 3
        if(digitalRead(b3)==LOW)
 {
 delay(120); 
 digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
 

     mostrar(cont2+cont1);
     
 }
    
}

void mostrar(int valor){
     decenas=valor/10;
     unidades=valor-decenas*10;
     digitalWrite(dec,HIGH);
     digitalWrite(uni,LOW);
     contador(decenas);
     delay(50);
     digitalWrite(dec,LOW);
     digitalWrite(uni,HIGH);
     contador(unidades);
     delay(50);
  
}

void contador (int dato){
  switch(dato){
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
    }

  }
  
