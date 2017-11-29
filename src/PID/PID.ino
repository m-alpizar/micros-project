#include <Servo.h>
#include <PID_v1.h>
Servo myservo;
Servo myservo2;
int input,input2,in,in2;
String inData,inData2;
int Ts = 1;
double Setpoint, Input, Output;
double Setpoint2, Input2, Output2;
float Kp = 0.3;                                                     
float Ki = 0.03;                                                      
float Kd = 0.13;

float Kp2 = 0.3;                                                       
float Ki2 = 0.08;                                                      
float Kd2 = 0.13;
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
PID myPID2(&Input2, &Output2, &Setpoint2, Kp2, Ki2, Kd2, DIRECT);

void setup()
{
  myservo.attach(9);
  myservo2.attach(8);
  Serial.begin(115200);
  myservo.write(80);
  myservo2.write(80);
  Setpoint=200;
  Setpoint2=200;
   myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(5, 100);
  myPID2.SetMode(AUTOMATIC);
  myPID2.SetOutputLimits(5, 100);
  // TIME SAMPLE
  myPID2.SetSampleTime(Ts); 
  myPID.SetSampleTime(Ts);  
  /////
  
 
}

void loop() {
  if (Serial.available() > 0 ) {
      inData = Serial.readStringUntil(':');
      Input = inData.toInt();
      
       // Reading angle of the servo2
      inData2 = Serial.readStringUntil('$');
      Input2 = inData2.toInt();
      
      myPID.Compute();  //action control X compute
      myPID2.Compute(); //   action control  Y compute
      myservo.write(Input);
      myservo2.write(Input2);
 
    
  }else{
    myservo.write(80);
    myservo2.write(80);
  }

  
}




