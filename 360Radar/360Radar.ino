#include <Servo.h>
#include <SoftwareSerial.h>
 
#define echoPin 9   // attach pin 9 Arduino to pin Echo of HC-SR04
#define trigPin 10  //attach pin 10 Arduino to pin Trig of HC-SR04
#define echoPin2 12 // attach pin 12 Arduino to pin Echo of HC-SR04
#define trigPin2 13 //attach pin 13 Arduino to pin Trig of HC-SR04
#define lediPin 5 //define pin 5 for led
#define button 11 //define pin 11 for button

SoftwareSerial SIM900(7, 8); //define pins you use whit SIM900
Servo Myservo;
 
// defines variables
long duration;  // radar 1 variable for the duration of sound wave travel
int distance; // radar 1 variable for the distance measurement

long duration2; // radar 2 variable for the duration of sound wave travel
int distance2;  // radar 2 variable for the distance measurement
 
volatile int halytetty = 0;
int pos;
int buttonValue = 0;
int start = 0;
 
int tutka1();
int halytys();
int ledi();
 
void setup() {
  Myservo.attach(6); 
 
  pinMode(lediPin, OUTPUT);   // Sets the ledPin as an OUTPUT

  pinMode(trigPin, OUTPUT);   // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);    // Sets the echoPin as an INPUT

  pinMode(trigPin2, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT);   // Sets the echoPin as an INPUT

  pinMode(button, INPUT_PULLUP); //set button as an INPUT_PULLUP
 
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  SIM900.begin(19200);  //SIM900 serial communication is starting whit 19200 of baudrate speed
}
 
void loop() {
  buttonValue = digitalRead(button);
  //if button pressed start scannin
  if(buttonValue == 1){
    start = 1;
  }
  // Serial.println(buttonValue);
  while (halytetty == 0 && start == 1) {
    delay(1000);
    //for loop to rotate servo 180 degrees. Every 10 degrees scan once
    for (pos = 0; pos <= 180; pos = pos + 10) {
      buttonValue = digitalRead(button);
      Myservo.write(pos);
      tutka1();
      //if either radar detects target or button is pressed stop scannin
      if (halytetty == 1 || buttonValue == 1) {
        halytetty = 0;
        start = 0;
        delay(3000);
        return;
      }
    }
    delay(1000);
    //for loop to rotate servo 180 degrees for oppisite direction. Every 10 degrees scan once
    for (pos = 180; pos >= 0; pos = pos - 10) {
      buttonValue = digitalRead(button);
      Myservo.write(pos);
      tutka1();
      //if either radar detects target or button is pressed stop scannin
      if (halytetty == 1 || buttonValue == 1) {
        halytetty = 0;
        start = 0;
        delay(3000);
        return;
      }
    }
    delay(1000);
  }
}
 
int tutka1() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor


  // Serial.print("Radar1 Distance: ");
  // Serial.print(distance);
  // Serial.println(" cm");
 
  if (distance <= 10) {
    // Serial.println("\nTutka1 havaitsi kohteen\n");
    halytys();
  }
 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor


  // Serial.print("Radar 2 Distance: ");
  // Serial.print(distance2);
  // Serial.println(" cm");
 
  if (distance2 <= 10) {
    // Serial.println("\nTutka2 havaitsi kohteen\n");
    halytys();
  }
}
 
int halytys() {
  //call ledi and sendSMS subroutines
  ledi();
  sendSMS();
  halytetty = 1;
}
 
int ledi() {
  // LED will blink 10 times
  for (int x; x < 10; x++) {
    digitalWrite(lediPin, HIGH);
    delay(100);
    digitalWrite(lediPin, LOW);
    delay(100);
  }
}

void sendSMS() {
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT+CMGS=\"+358443286650\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("Tutka havaitsi kohteen."); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(5000); 
}