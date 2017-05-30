#include <Servo.h>             
 
Servo servo_1;        
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

int angle = 95;    
 
void setup() 
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(2500);
  digitalWrite(13, LOW);
  servo_1.attach(7);     
  servo_2.attach(8);
  servo_3.attach(9);
  servo_4.attach(10);
  servo_5.attach(11);
  servo_6.attach(12);
  delay(1000);
  servo_1.write(angle); delay(500);
  servo_2.write(angle); delay(500);
  servo_3.write(angle); delay(500);
  servo_4.write(angle); delay(500);
  servo_5.write(angle); delay(500);
  servo_6.write(angle); delay(500);
  delay(500);
  digitalWrite(13, HIGH);
} 
  
void loop() 
{ 
  for(; angle < 180; angle += 1)   
  {                                  
    servo_1.write(angle);                
    servo_2.write(angle);
    servo_3.write(angle);
    servo_4.write(angle);
    servo_5.write(angle);
    servo_6.write(angle);
    delay(20);                       
  } 
 
  delay(1000);
  
  for(; angle>=10; angle-=1)     
  {                                
    servo_1.write(angle);              
    servo_2.write(angle);
    servo_3.write(angle);
    servo_4.write(angle);
    servo_5.write(angle);
    servo_6.write(angle);
    delay(15);                       
  } 

    delay(500);
}
