String readString;
#include <VarSpeedServo.h>
#include <SoftwareSerial.h>
unsigned long startMillis;
unsigned long currentMillis;
//Define Nano communications
#define rxPin 12
#define txPin 13
String col;
String sortColor;
char c;
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

//Servos from bottom to top
VarSpeedServo s1;
VarSpeedServo s2;
VarSpeedServo s3;
VarSpeedServo s4;
VarSpeedServo s5;
VarSpeedServo s6;// create servo object to control a servo

boolean r = false;
boolean y = false;
boolean b = false;

void pickUp() {

  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);

  s1.write(90, 10, true);
  s2.write(55, 20, true);
  s3.write(175, 25, true);
  s4.write(130, 25, true);
  s5.write(100, 25, true);
  s6.write(2400);



}
void moveRed() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);

 
  s2.write(130, 35, true);
  s3.write(165, 35, true);
  s4.write(120, 35, true);
  s5.write(100, 35, true);
 
  s1.write(30, 20, true);
  s2.write(55, 20, true);
  s6.write(60, 35, true);
  delay(200);
  r = false;


}

void moveBlue(){

  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);

 
  s2.write(130, 35, true);
  s4.write(135, 35, true);
  s5.write(100, 35, true);
  s1.write(50, 30, true);
  s3.write(145, 5, true);
  s2.write(25, 20, true);
  s6.write(60, 35, true);

  delay(200);
  s2.write(100, 20, true);
  s3.write(175, 5, true);
  
  b = false;


  
}
void moveYellow(){
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);

 
  s2.write(130, 35, true);
  s4.write(135, 35, true);
  s5.write(100, 35, true);
  s1.write(50, 30, true);
  s3.write(145, 25, true);
  s2.write(25, 25, true);
  s6.write(60, 35, true);

  delay(200);
  s2.write(100, 20, true);
  s3.write(175, 5, true);
  
 
  y = false;

}
void goToStart() {
  
  s2.write(130, 15, true);
  
  s3.write(150, 15, true);
  s4.write(180, 15, true);
  s1.write(120, 25, true);
  
  s4.write(180, 15, true);
  s5.write(100, 15, true);
  s6.write(130, 15, true);

}
void(* resetFunc) (void) = 0; 
void setup() {


  startMillis = millis();
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  //Starting positions
  s1.writeMicroseconds(1700);
  s2.writeMicroseconds(1800);
  s3.writeMicroseconds(2100);
  s4.writeMicroseconds(2400);
  s5.writeMicroseconds(1450);
  s6.writeMicroseconds(1900);


  s2.attach(5);
  delay(300);
  s1.attach(3);
  delay(300);
  s3.attach(6);
  delay(100);
  s4.attach(9);
  delay(100);
  s5.attach(10);
  delay(100);
  s6.attach(11);

  delay(1000);
    s1.detach();
  s2.detach();
  s3.detach();
  s4.detach();
  s5.detach();
  s6.detach();


}

void loop() {
  currentMillis = millis();
  if (mySerial.available() > 0) {

    c = mySerial.read();
    if (c != '\n') {
      col += c;
    }
    if (c == '\n') {

      Serial.println(col);
      sortColor = String(col);
      col = "";

    }
  }

  if (currentMillis - startMillis >= 3000)
  {
    if (sortColor[0] == 'R') {
      r = true;
      b = false;
      y = false;
    } else if (sortColor[0]  == 'B') {
      b = true;
      r = false;
      y = false;
    } else if (sortColor[0]  == 'Y') {
      y = true;
      b = false;
      r = false;
    }
    Serial.println(sortColor);
    startMillis = currentMillis;
    if (r == true) {
      pickUp();
      delay(100);
      moveRed();
      delay(200);
      r=false;

      delay(500);
      resetFunc();

    } else if (b == true) {
      pickUp();
      delay(100);
      moveBlue();
      delay(200);
      b=false;

      delay(500);
      resetFunc();

    }else if (y == true) {
      pickUp();
      delay(100);
      moveYellow();
      delay(200);
      y=false;

      delay(500);
      resetFunc();

    }
  }


}
