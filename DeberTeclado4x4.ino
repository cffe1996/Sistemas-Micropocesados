#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13,12,11,10,9,8);
const byte filas= 4;
const byte columnas= 4;
char keys[filas][columnas] =
{{'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'}};
char pin[5];
int pos=0;
byte pinfil[filas] = {0, 1, 2, 3};
byte pincol[columnas] = {4, 5, 6, 7};
Keypad teclado = Keypad( makeKeymap(keys), pinfil, pincol, filas, columnas );

void setup(){
lcd.begin(15, 1);
lcd.setCursor(0,1);
lcd.print("Igrese la Contraseña:");
}

void loop(){
pin[pos] = teclado.getKey();

if (pin[pos]){
lcd.clear();
for(int i = 0; i <= posicion; i++){
lcd.setCursor(i,1);
lcd.print("*");
}
posicion++;
if(pos == 5) pos = 0;
}

if(pin[4] == 'A'){
pin[4] = 'a';
if(pin[0] == '1' && pin[1] == '2' && pin[2] == '3' && pin[3] == '4'){
lcd.clear();
lcd.setCursor(0,1);
lcd.print("Contraseña Correcta ");
}
else {
lcd.clear();
lcd.setCursor(0,1);
lcd.print("Contraseña Incorrecta ");
delay(10);
}
