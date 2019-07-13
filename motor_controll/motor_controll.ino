
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pos = 0; 
int motor1 =2;
int motor2 = 4;
int motor1_spd = 5;
int motor2_spd =6;
int incomingByte = 0;


void setup() {
  Serial.begin(9600);
 // myservo.attach(9);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
}

void loop() {
  // send data only when you receive data:
        if (Serial.available() > 0) {
                incomingByte = Serial.read();
                if(incomingByte == 1){
                  unsigned long start = millis();
                  while (millis() < start + 4000) {
                  analogWrite(motor1_spd,255);
                  analogWrite(motor2_spd,0);
                  delay(500);
                  }
                } else {
                  analogWrite(motor1_spd,0);
                  analogWrite(motor2_spd,0);
                  }
                if(incomingByte == 2){
                  unsigned long start = millis();
                  while (millis() < start + 2000) {
                 analogWrite(motor1_spd,0);
                  analogWrite(motor2_spd,255);
                  delay(500);
                  }
                } else {
                  analogWrite(motor1_spd,0);
                  analogWrite(motor2_spd,0);
                  }
                if(incomingByte == 3){
                  unsigned long start = millis();
                  while (millis() < start + 2000) {
                   analogWrite(motor1_spd,255);
                  analogWrite(motor2_spd,255);
                  }
                } else {
                  analogWrite(motor1_spd,0);
                  analogWrite(motor2_spd,0);
                  }
        }
        delay(10);

}
