/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo,myservo2;  // create servo object to control a servo

int Input,Input2;  // analog pin used to connect the potentiometer
String inData,inData2;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(8);
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0 ) {
      inData = Serial.readStringUntil(':');
      Input = inData.toInt();
      
       // Reading angle of the servo2
      inData2 = Serial.readStringUntil('$');
      Input2 = inData2.toInt();
      
      myservo.write(Input);
      myservo2.write(Input2);



      
     
    
  }
}

