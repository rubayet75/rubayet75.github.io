//Developed by Rubayet Khan
#include "NewPing.h"
 int command;
// Hook up HC-SR04 with Trig to Arduino Pin 2, Echo to Arduino pin 3
// Maximum Distance is 400 cm
 #include <Servo.h> 

Servo myservo; 
int pos = 1;
#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200
 int st=0;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
int duration, distance;
 
int iterations = 4;
 
void setup() {
  Serial.begin (9600);
  myservo.attach(9); 
  myservo.write(1);
  if(Serial.available()>0)
  myservo.write(90);
}
 void stopradar(){
  myservo.write(0);}
void loop() {
  if (Serial.available()>0)
  {
 
   if (pos == 1)
  st = 0;
    
 if (pos == 180)
  st = 1;
    
 if (st==0)
  pos = pos+1;
    
 if (st==1)
      pos = pos-1;
         
  myservo.write(pos);
  duration = sonar.ping_median(iterations);
  delay(20);
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
   if (distance >= 200 || distance <= 2 ) {
    distance=200;
  }
  // Send results to Serial Monitor
   Serial.print(pos); Serial.print(" "); Serial.println(distance);
  delay(30);
 
 
  delay(10);
}

}
