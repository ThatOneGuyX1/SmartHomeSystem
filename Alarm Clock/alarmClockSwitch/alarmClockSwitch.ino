/*

*/



#include <Servo.h>

Servo myservo;
#define clockPin A0 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(clockPin);
  Serial.println(value);
  /*
  10 bit resolutions gives us 1023 as a max.
  If we consider 5000 mV as the max we can figure how many steps we need to get 100 mV.
  5000mV / 1023 Steps = 4.88mV / 1 step
  Thus 100 mV / 4.88 mV  = 20.5 steps / 1 step would be the ratio
  */
  if (value > 20){ 
    myservo.write(180);
  }
  else{
    myservo.write(0);
  }
}
