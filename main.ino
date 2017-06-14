// offset: 91 93 99 92 98 97, laranja na ponta 300 Ohms
//Centralizado X: 500 Y: 500

//Centro Cima X:500 Y:335
//Centro Baixo X:500 Y:683

//Esquerda Cima X:795 Y:335
//Direita Cima X:224 Y:335

//Esquerda Baixo X:795 Y:683
//Direita Baixo X:224 Y:683

//Esquerda Centro X:795 Y:500 
//Direita Centro X:224 Y:500 
#include <Servo.h>             

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

int ofsServo1 = 91;
int ofsServo2 = 93;
int ofsServo3 = 99;
int ofsServo4 = 92;
int ofsServo5 = 98;
int ofsServo6 = 97;

const int X1 = A0, Y1 = A1, X2 = A2, Y2 = A3;
boolean touch();
int x_cord = 0, y_cord = 0, val = 0, count = -1, arr[11], k = 0;

int incomingByte = 0;

float teta = 0;
float fi = 0;

int errx, errx_ant, erry, erry_ant;

int centralx = 500, centraly = 500;

void setup() 
{
  servo_1.attach(7);
  servo_2.attach(6);
  servo_3.attach(5);
  servo_4.attach(4);
  servo_5.attach(3);
  servo_6.attach(2);
  Serial.begin(9600);
}

void moveServo(){
  servo_1.write(ofsServo1+(teta*3.0)+(fi*4.0));
  servo_2.write(ofsServo2-(teta*3.0)+(fi*4.0));
  servo_3.write(ofsServo3+(teta*2.0)-(fi*4.6));
  servo_4.write(ofsServo4+(teta*5.0)+(fi*0.6));
  servo_5.write(ofsServo5-(teta*5.0)+(fi*0.6));
  servo_6.write(ofsServo6-(teta*2.0)-(fi*4.6));
}

void defineAngles(int incomingByte){
    if(x_cord < 795 && x_cord > 224){
      if(y_cord < 683 && y_cord > 335 ){
        teta += errx;
        fi += erry;
        moveServo();
      }
    }else{
      teta = 0;
      fi = 0;
      Serial.write("Centraliza\n");
      moveServo();
    }
}

void loop() 
{

  if(touch()>0){

    if(x_cord < 800 && y_cord < 800){
      errx = centralx - x_cord;
      erry = centraly - y_cord;
      teta -= errx * 0.05;
      fi += erry * 0.05;
      Serial.write("Bolinha\n");
      moveServo();
    }else{
      teta = 0;
      fi = 0;
      Serial.write("Centraliza\n");
      moveServo();
    }

    Serial.print("Y: ");
    Serial.print(x_cord);
    Serial.print(" X: ");
    Serial.println(y_cord);
    delay(500);
  }
  
  delay(50);
}

boolean touch()
{
  boolean touch1 = false;

  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  digitalWrite(X1, LOW);
  digitalWrite(X2, HIGH);
  pinMode(Y1, INPUT);
  pinMode(Y2, INPUT);
  delay(10);
  y_cord = analogRead(Y2);

  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, HIGH);
  pinMode(X1, INPUT);
  pinMode(X2, INPUT);
  delay(10);
  x_cord = analogRead(X2);

  if (x_cord > 0 && x_cord < 1000 && y_cord > 0 && y_cord < 1000)
    touch1 = true;

  return touch1;
}
