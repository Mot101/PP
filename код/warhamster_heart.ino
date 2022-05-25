#include <SoftwareSerial.h> 
#include <AFMotor.h>
#include <Servo.h>    
Servo servo_v; 
Servo servo_h; 
SoftwareSerial mySerial(0, 1);
AF_DCMotor motor_right(1);
AF_DCMotor motor_left(2);
int val;
int base_speed=100;
int speed_1=100;
int deg_h=0;
int deg_v=0;
int ledPin = A0;
int pishPin = A1;
void LEDOn()

{

digitalWrite(ledPin, HIGH);

}

void LEDOff()

{

digitalWrite(ledPin, LOW);

}
void setup()  
{
    int speed_level;
  pinMode(ledPin, OUTPUT);
  pinMode(pishPin, OUTPUT);
  base_speed=100;
  servo_v.attach(10);
  servo_h.attach(9);
  motor_left.setSpeed(speed_1);
  motor_right.setSpeed(speed_1);
   motor_right.run(FORWARD);
  motor_left.run(FORWARD);
  digitalWrite(ledPin, HIGH);
  digitalWrite(pishPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  digitalWrite(pishPin, LOW);
  servo_h.write(90);
  servo_v.write(90);  
  motor_right.run(RELEASE);
  motor_left.run(RELEASE);
  Serial.begin (38400);
  Serial.println("Start Serial");
}
 
void loop() 
{
  motor_left.setSpeed(speed_1);
  motor_right.setSpeed(speed_1);
  if (Serial.available()) {
    val = Serial.read();
  switch(val){
    case 'F':
      motor_right.run(FORWARD);
      motor_left.run(FORWARD);
      break;
    case 'f':
      motor_right.run(RELEASE);
      motor_left.run(RELEASE);
      break;
    case 'L':
      motor_right.run(FORWARD);
      motor_left.run(BACKWARD);
      break;
    case 'l':
      motor_right.run(RELEASE);
      motor_left.run(RELEASE);
      break;
    case 'R':
      motor_right.run(BACKWARD);
      motor_left.run(FORWARD);
      break;
    case 'r':
      motor_right.run(RELEASE);
      motor_left.run(RELEASE);
      break;
    case 'B':
      motor_right.run(BACKWARD);
      motor_left.run(BACKWARD);
      break;
    case 'b':
      motor_right.run(RELEASE);
      motor_left.run(RELEASE);
      break;
    case '1':
      speed_1=base_speed*1;
      break;
    case '2':
      speed_1=base_speed*1.5;
      break; 
    case '3':
      speed_1=base_speed*2;
      break; 
    case '4':
      speed_1=base_speed*2.5;
      break;
    case 'U':
        deg_v=servo_v.read();
        if(deg_v<180){
          deg_v=deg_v+5;
        servo_v.write(deg_v); 
        delay(100);
        }
        break;
    case 'D':
      deg_v=servo_v.read();
        if(deg_v>0){
          deg_v=deg_v-5;
        servo_v.write(deg_v); 
        delay(100);
        }
        break;
    case 'P':
      deg_h=servo_h.read();
        if(deg_h>0){
          deg_h=deg_h-5;
        servo_h.write(deg_h); 
        delay(100);
        }
        break;
    case 'O':
      deg_h=servo_h.read();
        if(deg_h<180){
          deg_h=deg_h+5;
        servo_h.write(deg_h); 
        delay(100);
        }
        break;
     case 'N':
        servo_v.write(90);  
        break;
     case 'Z':
        servo_h.write(90);  
        break;
     case 'W':
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        digitalWrite(pishPin, HIGH);
        delay(1000);
        digitalWrite(pishPin, LOW);
        break;
   delay(10);
  }
  }
}
