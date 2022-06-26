
#include <SoftwareSerial.h>
//Serial comm setup
#define rxPin 9
#define txPin 12
SoftwareSerial mySerial(rxPin, txPin);

//Color sensor setup
#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define outPin 8

int red;
int grn;
int blu;
String color = "";
int count = 0;
long startTiming = 0;
long elapsedTime = 0;

//Ultrasonic setup
int triggerPin = 11;      //Define IO pins
int echoPin = 10;
long duration;
double distance;


void getColor()
{
  readRGB();
  
  if (red > 100 && red < 200 && grn > 230 && grn < 640 && blu > 210 && blu < 490) color = "RED";
  else if (red > 60 && red < 115 && grn > 75 && grn < 140 && blu > 105 && blu < 220) color = "YELLOW";
  else if (red > 145 && red < 320 && grn > 110 && grn < 200 && blu > 70 && blu < 140) color = "BLUE";
  else  color = "NO_COLOR";
}

/* read RGB components */
void readRGB()
{
  red = 0;
  grn = 0;
  blu = 0;
  int n = 10;
  for (int i = 0; i < n; ++i)
  {
    //read red component
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);

    //read green component
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn = grn + pulseIn(outPin, LOW);

    //let's read blue component
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu = blu + pulseIn(outPin, LOW);
  }
  red = red / n;
  grn = grn / n;
  blu = blu / n;
  Serial.println(red);
  Serial.println(grn);
  Serial.println(blu);
  
}

void setup()
{

  //Color

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  //Ultra

  pinMode(triggerPin, OUTPUT);   //Define pin
  pinMode(echoPin, INPUT);
  mySerial.begin(9600);           //Starts the serial communication
  startTiming = millis();
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(triggerPin, LOW);   //Reset the trigger pin
  delay(1000);
  digitalWrite(triggerPin, HIGH);     //Create a 10 micro second pulse
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Read the pulse travel time in microseconds.
  distance = duration * 0.034 / 2;   //Calculate the distance - speed of sound is 0.034 cm per microsecond
  

  if (distance < 11) {
    Serial.println("OK");
    getColor();
    elapsedTime = millis() - startTiming;
    if (elapsedTime > 1000)
    {
      Serial.println(color);
      mySerial.println(color);
      startTiming = millis();
    }
  }

}
