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

int incomingByte = 0;

float teta = 0;
float fi = 0;

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
  if(incomingByte == '5'){ //Centraliza
    teta = 0;
    fi = 0;
    Serial.write("Centraliza\n");
    moveServo();
  }
  if(incomingByte == '8'){ //(Desce (teta-1))
    Serial.write("8\n");
    teta += 0.5;
    moveServo();
  }
  if(incomingByte == '2'){ //Sobe  teta+1
    Serial.write("2\n");
    teta -= 0.5;
    moveServo();
  }
  if(incomingByte == '4'){ //Sobe fi+1
    Serial.write("4\n");
    fi += 0.5;
    moveServo();
  }
  if(incomingByte == '6'){ //Sobe fi+1
    Serial.write("6\n");
    fi -= 0.5;
    moveServo();
  }
}

void loop() 
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    defineAngles(incomingByte);
  }
  delay(50);
}
