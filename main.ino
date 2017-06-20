// offset: 91 92 99 94 95 97, laranja na ponta 300 Ohms
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
int ofsServo2 = 92;
int ofsServo3 = 99;
int ofsServo4 = 94;
int ofsServo5 = 95;
int ofsServo6 = 97;

const int X1 = A0, Y1 = A1, X2 = A2, Y2 = A3;
boolean touch();
int x_cord = 0, y_cord = 0, val = 0, count = -1, arr[11], k = 0;

int incomingByte = 0;

float teta = 0;
float fi = 0;

int errx = 0, errx_ant, erry = 0, erry_ant, errxAnt = 0, erryAnt = 0;

int centralx = 500, centraly = 500;

void setup()
{
  servo_1.attach(7);
  servo_2.attach(6);
  servo_3.attach(5);
  servo_4.attach(4);
  servo_5.attach(3);
  servo_6.attach(2);
  Serial.begin(115200);
}

void moveServo() {
  //  float s1 = constrain(ofsServo1+(teta*3.0)+(fi*4.0), -10.0, 10.0);
  //  float s2 = constrain(ofsServo2-(teta*3.0)+(fi*4.0), -10.0, 10.0);
  //  float s3 = constrain(ofsServo3+(teta*2.0)-(fi*4.6), -10.0, 10.0);
  //  float s4 = constrain(ofsServo4+(teta*5.0)+(fi*0.6), -10.0, 10.0);
  //  float s5 = constrain(ofsServo5-(teta*5.0)+(fi*0.6), -10.0, 10.0);
  //  float s6 = constrain(ofsServo6-(teta*2.0)-(fi*4.6), -10.0, 10.0);

  servo_1.write(ofsServo1 + (teta * 3.0) + (fi * 4.0));
  servo_2.write(ofsServo2 - (teta * 3.0) + (fi * 4.0));
  servo_3.write(ofsServo3 + (teta * 2.0) - (fi * 4.6));
  servo_4.write(ofsServo4 + (teta * 5.0) + (fi * 0.6));
  servo_5.write(ofsServo5 - (teta * 5.0) + (fi * 0.6));
  servo_6.write(ofsServo6 - (teta * 2.0) - (fi * 4.6));
  //Serial.println(ofsServo1+(teta*3.0)+(fi*4.0));
  //Serial.write(false ? "JJ" : "NJJ");
}

float Kp = 0.015; 
float Ki = 0.0;
float Kd = 0.125;
static byte Run = 1;

void loop()
{
  if (Serial.available())
  {
    char Rx = Serial.read();
    const int Dist = 150;
    if (Rx == 'R' || Rx == 'r') Run = !Run;
    else if(Rx == 'q') Kp *= 1.18920;
    else if(Rx == 'a') Kp *= 0.84089;
    else if(Rx == 'w') Ki *= 1.18920;
    else if(Rx == 's') Ki *= 0.84089;
    else if(Rx == 'e') Kd *= 1.18920;
    else if(Rx == 'd') Kd *= 0.84089;
    
    else if(Rx == 0x41) { centraly -= 10; }
    else if(Rx == 0x42) { centraly += 10; }
    else if(Rx == 0x44) { centralx += 10; }
    else if(Rx == 0x43) { centralx -= 10; }
        
    else if(Rx == '8') { centralx = 500; centraly = 500 + Dist; }
    else if(Rx == '2') { centralx = 500; centraly = 500 - Dist; }
    else if(Rx == '4') { centralx = 500 + Dist; centraly = 500; }
    else if(Rx == '6') { centralx = 500 - Dist; centraly = 500; }
    else if(Rx == '5') { centralx = 500; centraly = 500; }
    else if(Rx == '7') { centralx = 500 + Dist; centraly = 500 + Dist; }
    else if(Rx == '9') { centralx = 500 - Dist; centraly = 500 + Dist; }
    else if(Rx == '1') { centralx = 500 + Dist; centraly = 500 - Dist; }
    else if(Rx == '3') { centralx = 500 - Dist; centraly = 500 - Dist; }

    Serial.print("Gain: ");
    Serial.print(Kp,4);
    Serial.print(' ');
    Serial.print(Ki,4);
    Serial.print(' ');
    Serial.println(Kd,4);
    
  }

  if (touch() > 0) {
    static byte warn = 0;
    if (x_cord < 800 && y_cord < 800) {
      static float Px, Ix, Dx;
      static float Py, Iy, Dy;

      errxAnt = errx;
      erryAnt = erry;

      errx = centralx - x_cord;
      erry = centraly - y_cord;

      Py = -erry * Kp;
      Dy = (erryAnt - erry) * Kd;

      Px = errx * Kp;
      Dx = (errx - errxAnt) * Kd;

      teta = Py + Dy;
      fi   = Px + Dx;

      //      if(teta > 0) teta = teta * teta;
      //      else teta = -(teta * teta);
      //      if(fi > 0) fi = fi * fi;
      //      else fi = -(fi * fi);

      //Serial.write("Bolinha: T=");
      teta = constrain(teta, -10.0, 10.0);
      fi   = constrain(fi,   -10.0, 10.0);
      //Serial.print(teta, 2);
      //Serial.print(" F=");
      //Serial.println(fi, 2);

      if (Run) moveServo();


      warn = 0;
    } else {
      teta = 0;
      fi = 0;
      if (!warn) {
        Serial.write("Centraliza\n");
        warn = 1;
      }
      moveServo();
    }

    //Serial.print("Y: ");
    //Serial.print(x_cord);
    //Serial.print(" X: ");
    //Serial.println(y_cord);
  }

  delay(10);
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
