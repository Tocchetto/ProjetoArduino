#include <Servo.h>             

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;        
int angle = 95;
int zeroServo1 = 84-90;
int zeroServo2 = 86-90;
int zeroServo3 = 96-90;
int zeroServo4 = 90-90;
int zeroServo5 = 94-90;
int zeroServo6 = 88-90;

 
void setup() 
{
  servo_1.attach(7);
  servo_2.attach(6);
  servo_3.attach(5);
  servo_4.attach(4);
  servo_5.attach(3);
  servo_6.attach(2);
} 
  
void loop() 
{
  Serial.begin(9600);
  for(angle=20; angle < 160; angle += 1)   
  {
    Serial.println(angle);
    servo_1.write(zeroServo1+angle); delay(4);
    servo_2.write(zeroServo2+(angle*-1)+180);delay(4);
    servo_3.write(zeroServo3+angle);delay(4);
    servo_4.write(zeroServo4+(angle*-1)+180);delay(4);
    servo_5.write(zeroServo5+angle);delay(4);
    servo_6.write(zeroServo6+(angle*-1)+180);delay(4);
  }   
  delay(500);
  for(angle=160; angle>=20; angle-=1)     
  {
    Serial.println(angle);
    servo_1.write(zeroServo1+angle); delay(4);
    servo_2.write(zeroServo2+(angle*-1)+180);delay(4);
    servo_3.write(zeroServo3+angle);delay(4);
    servo_4.write(zeroServo4+(angle*-1)+180);delay(4);
    servo_5.write(zeroServo5+angle);delay(4);
    servo_6.write(zeroServo6+(angle*-1)+180);delay(4);                 
  }
  delay(500);
}
