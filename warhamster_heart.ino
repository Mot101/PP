#include <SoftwareSerial.h> 
#include <AFMotor.h>
#include <Servo.h>    
Servo servo_v; 
Servo servo_h; 
SoftwareSerial mySerial(0, 1);
AF_DCMotor motor_right(1);
AF_DCMotor motor_left(2);
int val;
int speed_1=100;
double deg=5;
double deg_v=90;
double deg_h=90;
int ledPin = A0;
int pishPin = A1;

void setup()  
{
  pinMode(ledPin, OUTPUT);
  pinMode(pishPin, OUTPUT);
  servo_v.attach(10);
  servo_h.attach(9);
  digitalWrite(pishPin, HIGH);
  delay(2000);
  digitalWrite(pishPin, LOW);
  servo_h.write(90);
  servo_v.write(60);
  Serial.begin (38400);
}
 
void loop() 
{
  motor_left.setSpeed(speed_1);
  motor_right.setSpeed(speed_1);
  if (Serial.available()) {
    val = Serial.read();
  switch(val){
    case 'F':
      if(servo_v.read()<79){
      motor_right.run(FORWARD);
      motor_left.run(FORWARD);
      }
      break;
    case 'L':
      if(servo_v.read()<79){
      motor_right.run(FORWARD);
      motor_left.run(BACKWARD);}
      break;
    case 'R':
      if(servo_v.read()<79){
      motor_right.run(BACKWARD);
      motor_left.run(FORWARD);}
      break;
    case 'B':
      if(servo_v.read()<79){
      motor_right.run(BACKWARD);
      motor_left.run(BACKWARD);
      }
      break;    
    case 'f':
      motor_right.run(RELEASE);
      motor_left.run(RELEASE);
      break;
    case '1':
      speed_1=100;
      break;
    case '2':
      speed_1=150;
      break; 
    case '3':
      speed_1=200;
      break; 
    case '4':
      speed_1=255;
      break;
    case 'U':
        deg_v=servo_v.read();
        if(deg_v<180){
          deg_v=deg_v+deg;
          servo_v.write(deg_v); 
          delay(100);
        }
        break;
    case 'D':
      deg_v=servo_v.read();
        if(deg_v>0){
          deg_v=deg_v-deg;
          servo_v.write(deg_v); 
          delay(100);
        }
        break;
    case 'P':
      deg_h=servo_h.read();
        if(deg_h>0){
          deg_h=deg_h-deg;
          servo_h.write(deg_h); 
          delay(100);
        }
        break;
    case 'O':
      deg_h=servo_h.read();
        if(deg_h<180){
          deg_h=deg_h+deg;
          servo_h.write(deg_h); 
          delay(100);
        }
        break;
     case 'N':
        servo_v.write(60);  
        break;
     case 'Z':
        servo_h.write(90);  
        break;
     case 'W':
        if(servo_v.read()>77){
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          digitalWrite(pishPin, HIGH);
          delay(1000);
          digitalWrite(pishPin, LOW);
        }
        break;
     case '5':
        deg=10;
        break;
     case '6':
        deg=5;
        break;
     case '7':
        deg=1;
        break;
     case '8':
        servo_v.write(90);
        break;      
   delay(10);
  }
  }
}
