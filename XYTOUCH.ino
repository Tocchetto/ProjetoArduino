/* DOCUMENTATION BY CHANDAN KUMAR 01/03/2015
  INTERFACE 4 WIRE RESISTIVE TOUCH SCREEN WITH ARDUINO

            ________________
           |                |
           |                |
           |     TOUCH      |
           |                |
           |                |
           |     SCREEN     |
           |    (YL1083)    |
           |                |
           |                |
            ________________

           ||||||||
           __   __   __   __
          |X1| |Y1| |X2| |Y2|
           ||   ||   ||   ||
           A0   A1   A2   A3

  FOR Y-AXIS:

  X1 GND
  X2 +5V
  MAKE Y1 AND Y2 AS INPUT MEANS HIGH IMPEDANCE
  NOW READ ANALOG VALUE ON Y2

  FOR X-AXIS:

  Y1 GND
  Y2 +5V
  MAKE X1 AND X2 AS INPUT MEANS HIGH IMPEDANCE
  NOW READ ANALOG VALUE ON Y2

*/

const int X1 = A0, Y1 = A1, X2 = A2, Y2 = A3, button = 6;

boolean touch();

int x_cord = 0, y_cord = 0, val = 0, count = -1, arr[11], k = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  while (touch() > 0)
  {
    Serial.print("Y: ");
  Serial.print(x_cord);
  Serial.print(" X: ");
  Serial.println(y_cord);
  delay(500);
//
//    if (x_cord > 0 && x_cord < 345 && y_cord > 0 && y_cord < 200) // 1
//    {
//      Serial.println(1);
//    }
//
//    if (x_cord > 350 && x_cord < 643 && y_cord > 0 && y_cord < 200) // 2
//    {
//      Serial.println(2);
//    }
//
//    if (x_cord > 650 && x_cord < 1000 && y_cord > 0 && y_cord < 200) // 3
//    {
//      Serial.println(3);
//    }
//
//    if (x_cord > 0 && x_cord < 345 && y_cord > 210 && y_cord < 473) // 4
//    {
//      Serial.println(4);
//    }
//
//    if (x_cord > 350 && x_cord < 643 && y_cord > 210 && y_cord < 473) // 5
//    {
//      Serial.println(5);
//    }
//
//    if (x_cord > 650 && x_cord < 1000 && y_cord > 210 && y_cord < 473) // 6
//    {
//      Serial.println(6);
//    }
//
//    if (x_cord > 0 && x_cord < 345 && y_cord > 480 && y_cord < 750) // 7
//    {
//      Serial.println(7);
//    }
//
//    if (x_cord > 350 && x_cord < 643 && y_cord > 480 && y_cord < 750) // 8
//    {
//      Serial.println(8);
//    }
//
//    if (x_cord > 650 && x_cord < 1000 && y_cord > 480 && y_cord < 750) // 9
//    {
//      Serial.println(9);
//    }
//
//
//    if (x_cord > 345 && x_cord < 650 && y_cord > 800 && y_cord < 1000) // 0
//    {
//      Serial.println(0);
//    }
//
//    if (x_cord > 0 && x_cord < 345 && y_cord > 800 && y_cord < 1000) // *
//    {
//      Serial.println('*');
//    }
//
//    if (x_cord > 650 && x_cord < 1000 && y_cord > 800 && y_cord < 1000) // #
//    {
//      Serial.println('#');
//    }

  }
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
