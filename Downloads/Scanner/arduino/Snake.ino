#include <Adafruit_NeoPixel.h>
#include "Graphs.h"
#define PIN 13
#define N_LEDS 64
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
const int vrx = 1;
const int vry = 0;
int xPosition = 0;
int yPosition = 0;
void(* resetFunc) (void) = 0;
int x = 0;
int pos = 0;
void probar();
int f = 0;
int snake[64];
int pasar = 0;
int pasar2 = 0;
int almacenar = 0;
int atrapar = 0;
void setup() {
Serial.begin(9600);
Serial.print("INICIO");
strip.begin();
strip.setBrightness(10);
strip.show();
pinMode(vrx, INPUT);
pinMode(vry, INPUT); 
int azar = random(1,63);
int azar2 = random(1,63);
atrapar = random(1,63);
while(atrapar == azar || atrapar == azar2){atrapar = random(1,63);}
strip.setPixelColor(atrapar, 0, 255, 0);
strip.setPixelColor(azar, 255, 0, 0);
strip.setPixelColor(azar2, 255, 0, 0);
strip.setPixelColor(0, 0, 0, 255);
ocupado[atrapar] = 2;
ocupado[azar] = 1;
ocupado[azar2] = 1;
ocupado[0] = 1;
snake[x] = 0;
x += 1;
strip.show();
<<<<<<< HEAD
probar();
}
=======
probar();}
>>>>>>> 1db7c18 (Version final)
void loop() {}
void probar(){
llenar();
Serial.println("ESTOY EN PROBAR");
int u = 0;
while(true){
  xPosition = analogRead(vrx);
  yPosition = analogRead(vry);
<<<<<<< HEAD
  if(xPosition > 1000){
      avanzar(8);
  }
  else if(yPosition > 1000){
    avanzar(-1);
  }
  else if(xPosition < 50){
    avanzar(-8);
  }
  else if(yPosition < 50){
    avanzar(1);
  }
  if(agarrar){
    for(f=0;f<x;f++){
      almacenar = snake[f];
    }
    search(grafo,almacenar, almacenar-pos);
    if(perder){perder=0;if(pos==1){pos=8;}else{pos=1;}}
    strip.setPixelColor(almacenar-pos, 0, 0, 255);
     snake[x] = almacenar-pos;
     x += 1;
     Serial.println("ESTOY EN AGARRAR");
     Serial.println(almacenar-pos);
     Serial.println(x);
    atrapar = random(0,63);
    Serial.println(atrapar);
    while(ocupado[atrapar] == 1){atrapar = random(0,63);}
    ocupado[atrapar] = 2;
   strip.setPixelColor(atrapar, 0, 255, 0);
   strip.show();
   agarrar = false;
  }
  strip.show();
  delay(100);
}
Serial.println("TERMINADO");
}
void avanzar(int n){
    pos = n;
    Serial.println(snake[0]);
    Serial.println(snake[0]+n);
=======
  if(xPosition > 1000){avanzar(8);}
  else if(yPosition > 1000){avanzar(-1);}
  else if(xPosition < 50){avanzar(-8);}
  else if(yPosition < 50){avanzar(1);}
  if(agarrar){
    for(f=0;f<x;f++){almacenar = snake[f];}
    search(grafo,almacenar, almacenar-pos);
    while(perder){perder=0;if(pos==1){pos=8;}else if(pos==8){pos=-1;}
    else if(pos==-1){pos=-8;}else{pos=-1;}
    search(grafo,almacenar, almacenar-pos);}
    strip.setPixelColor(almacenar-pos, 0, 0, 255);
     snake[x] = almacenar-pos;
     x += 1;
    atrapar = random(1,63);
    while(ocupado[atrapar] == 1){atrapar = random(1,63);}
    ocupado[atrapar] = 2;
   strip.setPixelColor(atrapar, 0, 255, 0);
   strip.show();
   agarrar = false;}
  strip.show();
  delay(100);}}
void avanzar(int n){
    pos = n;
>>>>>>> 1db7c18 (Version final)
    search(grafo, snake[0], snake[0]+n);
    if(perder == 1){lose();}
    strip.setPixelColor(snake[0]+n, 0, 0, 255);
    strip.setPixelColor(snake[0], 0, 0, 0);
    pasar = snake[0];
    snake[0] += n;
    delay(10);
    for(f=1;f<x;f++){
       pasar2 = snake[f];
       snake[f] = pasar;
       ocupado[pasar] = 1;
       strip.setPixelColor(pasar, 0, 0, 255);
       strip.setPixelColor(pasar2, 0, 0, 0);
       ocupado[pasar2] = 0;
       pasar = pasar2;
<<<<<<< HEAD
       delay(10);
    }
    strip.show();
}
void lose(){
  for(int y=0;y<64;y++){
    strip.setPixelColor(y, 255, 0, 0);
    delay(1);
  }
  strip.show();
  delay(3000);
  resetFunc();
}
=======
       delay(10);}strip.show();}
void lose(){
  for(int y=0;y<64;y++){
    strip.setPixelColor(y, 255, 0, 0);
    delay(1);}
  strip.show();
  delay(3000);
  resetFunc();}
>>>>>>> 1db7c18 (Version final)
