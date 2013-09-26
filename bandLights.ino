#define TOTALLIGHTS 50
#define XMASPIN 5 

#define DELAYLONG 16
#define DELAYSHORT 6
#define ZERO  digitalWrite(XMASPIN,LOW); delayMicroseconds(DELAYSHORT); digitalWrite(XMASPIN,HIGH);    delayMicroseconds(DELAYLONG);       
#define ONE digitalWrite(XMASPIN,LOW);    delayMicroseconds(DELAYLONG);   digitalWrite(XMASPIN,HIGH);    delayMicroseconds(DELAYSHORT);

void SETBULB(byte Bulb, byte Brightness, byte R, byte G, byte B)
{

 digitalWrite(XMASPIN,HIGH);  
 delayMicroseconds(DELAYSHORT); 

 //Bulb 
   if (Bulb & 0x20) { ONE } else { ZERO };
   if (Bulb & 0x10) { ONE } else { ZERO };
   if (Bulb & 0x8) { ONE } else { ZERO };
   if (Bulb & 0x4) { ONE } else { ZERO };
   if (Bulb & 0x2) { ONE } else { ZERO };
   if (Bulb & 0x1) { ONE } else { ZERO };


 //Brightness
   if (Brightness & 0x80) { ONE } else { ZERO };
   if (Brightness & 0x40) { ONE } else { ZERO };
   if (Brightness & 0x20) { ONE } else { ZERO };
   if (Brightness & 0x10) { ONE } else { ZERO };
   if (Brightness & 0x8) { ONE } else { ZERO };
   if (Brightness & 0x4) { ONE } else { ZERO };
   if (Brightness & 0x2) { ONE } else { ZERO };
   if (Brightness & 0x1) { ONE } else { ZERO };

 //Blue
   if (B & 0x8) { ONE } else { ZERO };
   if (B & 0x4) { ONE } else { ZERO };
   if (B & 0x2) { ONE } else { ZERO };
   if (B & 0x1) { ONE } else { ZERO };


 //Green
   if (G & 0x8) { ONE } else { ZERO };
   if (G & 0x4) { ONE } else { ZERO };
   if (G & 0x2) { ONE } else { ZERO };
   if (G & 0x1) { ONE } else { ZERO };

 //Red
   if (R & 0x8) { ONE } else { ZERO };
   if (R & 0x4) { ONE } else { ZERO };
   if (R & 0x2) { ONE } else { ZERO };
   if (R & 0x1) { ONE } else { ZERO };

 digitalWrite(XMASPIN,LOW);
 delayMicroseconds(40);

}


//How long to cycle up through each bulb
const int cycletime = 20;

void setup() {                
 // initialize the digital pin as an output.
 // Pin 13 has an LED connected on most Arduino boards:

 Serial.begin(9600);
 pinMode(XMASPIN, OUTPUT);  
 delay(500);
 
 //Cycle all bulbs to white
 for(int i=0;i<50;i++) {
 SETBULB(i, 255, 255, 255, 255);
 delay(cycletime);
 }

//Cycle all the bulbs off
 for(int i=0;i<50;i++){
   SETBULB(i, 0, 0, 0, 0);
   delay(cycletime);
 }  
}

void Bounce()
{
 int inc = 1;
 int CurrentLight = 0;
 
 while (true) {
   if (inc == 1){
     CurrentLight++;
   }
   else{
    CurrentLight--;
   }

   if (CurrentLight < 0){
     inc = 1;
     CurrentLight = 0;    
   }
   if (CurrentLight > TOTALLIGHTS-1){
     inc = 0;
     CurrentLight = TOTALLIGHTS-1;
   }
   
    for(int i=0;i<50;i++){
       if (CurrentLight == i){
          SETBULB(CurrentLight, 255, 255, 0, 0);
         
         }
         
       else{
          SETBULB(i, 255, 0, 0, 255);
       }    
     }    
  delay(3);
  } 
}


void thickBounce()
{
 int inc = 1;
 int CurrentLight = 0;
 
 while (true) {
   if (inc == 1){
     CurrentLight++;
   }
   else{
    CurrentLight--;
   }

   if (CurrentLight < 0){
     inc = 1;
     CurrentLight = 0;    
   }
   if (CurrentLight > TOTALLIGHTS-1){
     inc = 0;
     CurrentLight = TOTALLIGHTS-1;
   }
   
    for(int i=0;i<50;i++){
       if (CurrentLight == i){
          SETBULB(CurrentLight, 255, 255, 0, 0);
          
          SETBULB(CurrentLight - 1, 255, 255, 0, 0);
          SETBULB(CurrentLight - 2, 255, 255, 0, 0);
         
         }
         
       else{
          SETBULB(i, 255, 0, 0, 255);
       }    
     }    
  delay(3);
  } 
}

int fade = 10;
int fadeAmt = 5;

void Fade() {

fade = fade + fadeAmt;
delay(15);
Serial.println(fade);

if(fade < 10 || fade > 245) {
    fadeAmt = -fadeAmt;
  }
  
  
for(int i = 0; i<50; i++) {

  SETBULB(i, fade, 0, 255, 0);
  
}
}

void evenOdd() {
  for(int e = 0; e<50; e = e + 2) {
    SETBULB(e, 255, 0, 255, 0);
  }
  for(int x = 1; x < 50; x = x + 2) {
    SETBULB(x, 255, 255, 0, 0);
  }
  
  delay(1000);
  
   for(int e = 0; e<50; e = e + 2) {
    SETBULB(e, 255, 255, 0, 0);
  }
  for(int x = 1; x < 50; x = x + 2) {
    SETBULB(x, 255, 0, 255, 0);
  }
  
  delay(1000);
  
  
}

void randColor() {
  int r = random(0, 255);
  int g = random(0, 255);
  int b = random(0, 255);
  
  for(int i = 0; i < 50; i++) {
    SETBULB(i, 255, r, g, b);
  }
  
  delay(500);
}

void loop() {
/* Functions to choose from are as follows:
  -Bounce
  -thickBounce
  -Fade
  -evenOdd
  -randColor
  -Any others we would want to add
*/
  //thickBounce();
  //Bounce();
  //Fade();
  //evenOdd();
  randColor();
 
}



