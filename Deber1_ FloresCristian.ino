int leds[8]={13,12,11,10,9,8,7,6}; //puertos que se utilizan 
  int  i=0;//variable del vector

void setup() {
    for(i=0;i<8;i++)//configuracion de pines de forma grupal
  { 
    pinMode(leds[i],OUTPUT);//los pines que serán salidas
    }
    i=0;//reseteo de la variable de conteo 

}

void loop() {
  // put your main code here, to run repeatedly:

        
                                                       //Juego1 y Juego2
  
  for(;i<8;i++){
  if(i%2==1)//condicion de verificacion
  {digitalWrite(leds[i],HIGH);//encendido de los Leds
  delay(250);
  }
  }
 
  for(;i>=0;i--)
  {
  if(i%2==1)//condicion de verificacion
  {digitalWrite(leds[i],LOW);// apagagado de los Lesd
  delay(250);}
  }
    i=0;//se reinicia la variable para empezar de 0


  for(i=0;i<8;i++){
  if(i%2==0)//condicion de verificacion 
  {digitalWrite(leds[i],HIGH);//encendido de los Leds
  delay(250);}
  }
  
  for(;i>=0;i--)//
  {
  if(i%2==0)//condicion de verificacion 
  {digitalWrite(leds[i],LOW);//apagado de los Leds
  delay(250);}
    }
    i=0;//se reinicia la variable para empezar de 0

                                                    //Juego3: Cada Led enciende y apaga enseguida

    for (int i=0;i<8;i++){
    digitalWrite(leds[i],HIGH);//encendido de los Leds
    delay(250);
    digitalWrite(leds[i],LOW);//apagado de los Leds
    delay(250);
    }
    i=0; //se reinicia la variable para empezar de 0

                                                    //Juego4: Encienden y apagan grupos de 4 leds (primeros 4 y enseguida los 4 restantes) 
  for(i=0;i<4;i++)
{
  digitalWrite(leds[i],HIGH);
  delay(300);
}
for(i=0;i<4;i++)
{

  digitalWrite(leds[i],LOW);
  delay(300);
}

 for(i=4;i<8;i++)
{
  digitalWrite(leds[i],HIGH);
  delay(300);
}
for(i=4;i<8;i++)
{

  digitalWrite(leds[i],LOW);
  delay(300);
}
i=0;

 
    
                                                //Juego5: encienden todos los leds y se apagan desde el 2 hasta el 7

for(i=0;i<8;i++)
{
  digitalWrite(leds[i],HIGH);
  delay(300);
  
}
for(i=1;i<7;i++)
{
  
  digitalWrite(leds[i],LOW);
  delay(300);
}

  }
