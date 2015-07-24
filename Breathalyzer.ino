/*

@ Code for interfacing Alcohol Gas Sensor MQ-3 with Arduino
@ Code by Daniel Spillere Andrade and Daniel Amato Zabotti
@ daniel@danielandrade.net / danielzabotti@gmail.com
@     www.DanielAndrade.net

*/


const int analogPin = 0;    // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph
short sensorReading;
short sensor = 0;
int ledPins[] = {
  13,11,10,9,8,7,6,5,4,3,2 // Here we have the number of LEDs to use in the BarGraph
  };   
int x[] = {
  650,760, 820,840,860 // Here we have the number of LEDs to use in the BarGraph
  };   
  
void setup() {
  Serial.begin(9800);
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }}

void loop() {
  //This is the code to light up LED's
  int sensorReading = analogRead(analogPin);
//  Serial.println("sensor reading: ");
//  Serial.println(sensorReading);
//   int ledLevel = map(sensorReading, 500, 950, 0, ledCount);

   print();
   delay(500);
   if(sensorReading >= 650 && sensorReading <= 760) //20%
   {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[2], HIGH); 
     digitalWrite(ledPins[3], LOW);
     digitalWrite(ledPins[4], LOW);  
     digitalWrite(ledPins[5], LOW);
     digitalWrite(ledPins[6], LOW);   
     digitalWrite(ledPins[7], LOW);
     digitalWrite(ledPins[8], LOW);  
     digitalWrite(ledPins[9], LOW);
     digitalWrite(ledPins[10], LOW);       
   }
   else if(sensorReading > 760 && sensorReading <=820 )//40%
   {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[2], HIGH);        
     digitalWrite(ledPins[3], HIGH);
     digitalWrite(ledPins[4], HIGH);  
     digitalWrite(ledPins[5], LOW);
     digitalWrite(ledPins[6], LOW);   
     digitalWrite(ledPins[7], LOW);
     digitalWrite(ledPins[8], LOW);  
     digitalWrite(ledPins[9], LOW);
     digitalWrite(ledPins[10], LOW);      
   }
   else if(sensorReading > 820 && sensorReading <=840 ) //60%
   {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[2], HIGH);        
     digitalWrite(ledPins[3], HIGH);
     digitalWrite(ledPins[4], HIGH);        
     digitalWrite(ledPins[5], HIGH);
     digitalWrite(ledPins[6], HIGH);   
     digitalWrite(ledPins[7], LOW);
     digitalWrite(ledPins[8], LOW);  
     digitalWrite(ledPins[9], LOW);
     digitalWrite(ledPins[10], LOW);       
   } 
   else if(sensorReading > 840 && sensorReading <=860 ) //80%
   {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[2], HIGH);        
     digitalWrite(ledPins[3], HIGH);
     digitalWrite(ledPins[4], HIGH);        
     digitalWrite(ledPins[5], HIGH);
     digitalWrite(ledPins[6], HIGH);          
     digitalWrite(ledPins[7], HIGH);
     digitalWrite(ledPins[8], HIGH);  
     digitalWrite(ledPins[9], LOW);
     digitalWrite(ledPins[10], LOW);    
   }
   else if(sensorReading > 860)
   {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[2], HIGH);        
     digitalWrite(ledPins[3], HIGH);
     digitalWrite(ledPins[4], HIGH);        
     digitalWrite(ledPins[5], HIGH);
     digitalWrite(ledPins[6], HIGH);          
     digitalWrite(ledPins[7], HIGH);
     digitalWrite(ledPins[8], HIGH);        
     digitalWrite(ledPins[9], HIGH);
     digitalWrite(ledPins[10], HIGH);     
   }    
   if(sensorReading < 650){
     for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        digitalWrite(ledPins[thisLed], LOW);
     }
    }

//   for (int thisLed = 0; thisLed < ledCount; thisLed++) {
//     print();
//     if (thisLed < ledLevel) {
//       digitalWrite(ledPins[thisLed], HIGH);
//     }
//
//     else {
//       digitalWrite(ledPins[thisLed], LOW);
//     }  
//   }

}

void print(){
  sensorReading = analogRead(analogPin);
  Serial.println("sensorReading: ");
  Serial.println(sensorReading);
  Serial.println("\r\n");

  delay(500);
}
