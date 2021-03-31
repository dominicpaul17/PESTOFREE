#include <HCSR04.h>
#define led 4            
#define buzzer 8     
#define sensor 13     
int sound=250; 
UltraSonicDistanceSensor distanceSensor(4, 2);

void setup()
{
Serial.begin(9600);
pinMode(sensor,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(7, OUTPUT);
}

void loop(){
    int detect=digitalRead(sensor);   
    if(detect==LOW)               
    {       
      tone(buzzer,2000);            
    }
    else{
      
      noTone(buzzer);
    }
    delay(100);
      Serial.println(distanceSensor.measureDistanceCm());
        if(distanceSensor.measureDistanceCm()<50)
        {
          Serial.println("human is near");
          digitalWrite(7,LOW);
          delay(100);
        }
        else{
          Serial.println("human is not near");
          digitalWrite(7, HIGH);
          delay(100);
    }
      delay(500);

}
