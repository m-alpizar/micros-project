//  http://www.arduino.cc/en/Tutorial/ADXL3xx
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;

int val;    // variable to read the value from the analog pin
int val2;

int Input,Input2;
const int xpin = A4;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(8);
}

void loop() {
  long valorx;
  long valory;
  int servox;
  int servoy;
  valorx=analogRead(xpin);
  valorx=map(valorx, 335, 662, 180, 0);
  servox=valorx;
  myservo.write(valorx);
  //myservo.write(90); 
  //Serial.print(valorx);
  //Serial.print("\t");
//  print a tab between values:
  valory=analogRead(ypin);
  valory=map(valory, 335, 662, 180, 0);
  servoy=valory;
  myservo2.write(valory);
  //myservo2.write(90);    
  //Serial.println(valory);
  // print a tab between values:
  delay(150);
}

