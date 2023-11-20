#include <Servo.h>
const int LedBlue =11;
const int LedGreen = 12;
const int LedRed = 13;
const int LedWhite1 = 0;
const int LedWhite2 = 3;
const int LedHint = 10;
const int ButtonRed = 2;
const int ButtonGreen = 8;
const int ButtonBlue = 5;
const int ButtonPlay = 1;
const int piezo = 7;
const int servoPin = 9;
int buttonRedState = 0;
int buttonGreenState = 0;
int buttonBlueState = 0;
int buttonPlayState;
int lastButtonPlayState = HIGH;
int playState = 0;
int angle = 90;
Servo servo;

void setup() {
  servo.attach(servoPin);
  pinMode(LedBlue, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedWhite1, OUTPUT);
  pinMode(LedWhite2, OUTPUT);
  pinMode(LedHint, OUTPUT);
  pinMode(ButtonRed, INPUT);
  pinMode(ButtonGreen, INPUT);
  pinMode(ButtonBlue, INPUT);
  pinMode(ButtonPlay, INPUT);
}

void loop() {
  buttonRedState = digitalRead (ButtonRed);
  buttonGreenState = digitalRead (ButtonGreen);
  buttonBlueState = digitalRead (ButtonBlue);
  buttonPlayState = digitalRead (ButtonPlay);
  delay(10);

  digitalWrite(LedHint, HIGH);
  delay(500);
  digitalWrite(LedHint, LOW);
  delay(500);
    
// if play butoon is pressed,play the tone
if (lastButtonPlayState == LOW && buttonPlayState ==HIGH) {
  if(playState == 0){
  playSong1();
  playState=1;
  } else {
    playSong2();
    playState =0;
  }
}
lastButtonPlayState = buttonPlayState;
    
// define the behavior when guessing the right answer
if(buttonRedState == HIGH && playState == 1) {
  guessRight();
  servo.write (angle);
  } else if (buttonBlueState == HIGH && playState == 0) {
  guessRight();
  servo.write (angle);
  } 

// define the behavior when guessing song1 wrong
if(playState == 1 && buttonBlueState == HIGH) {
  guessWrong();
  servo.write (angle);
  }

if(playState == 1 && buttonGreenState == HIGH) {
 guessWrong();
 servo.write (angle);
 }

//define the behavior when guessing song2 wrong
if(playState == 0 && buttonRedState == HIGH) {
  guessWrong();
  servo.write (angle);
  }

if(playState == 0 && buttonGreenState == HIGH) {
  guessWrong();
  servo.write (angle);
  }

}
  
   //Creat Song1 with LEDs
    void playSong1() {
      tone(piezo, 1500, 500);
      digitalWrite (LedRed, HIGH);
      delay(100);
      digitalWrite (LedRed,LOW);
      delay(250);
      tone(piezo, 1200, 500);
      digitalWrite (LedGreen, HIGH);
      delay(100);
      digitalWrite (LedGreen,LOW);
      delay(250);
      tone(piezo, 1000, 500);
      digitalWrite (LedBlue, HIGH);
      delay(100);
      digitalWrite (LedBlue,LOW);
      delay(250);
      
      tone(piezo, 1000, 500);
      digitalWrite (LedRed, HIGH);
      delay(100);
      digitalWrite (LedRed,LOW);
      delay(250);
      tone(piezo, 1200, 500);
      digitalWrite (LedGreen, HIGH);
      delay(100);
      digitalWrite (LedGreen,LOW);
      delay(250);
      tone(piezo, 1500, 500);
      digitalWrite (LedBlue, HIGH);
      delay(100);
      digitalWrite (LedBlue,LOW);
      delay(250);

      tone(piezo, 1350, 500);
      digitalWrite (LedRed, HIGH);
      delay(100);
      digitalWrite (LedRed,LOW);
      delay(250);
      tone(piezo, 1200, 500);
      digitalWrite (LedGreen, HIGH);
      delay(100);
      digitalWrite (LedGreen,LOW);
      delay(250);
      tone(piezo, 1000, 500);
      digitalWrite (LedBlue, HIGH);
      delay(100);
      digitalWrite (LedBlue,LOW);
      delay(250);

      tone(piezo, 1500, 500);
      digitalWrite (LedRed, HIGH);
      delay(100);
      digitalWrite (LedRed,LOW);
      delay(250);
      tone(piezo, 500, 500);
      digitalWrite (LedGreen, HIGH);
      delay(100);
      digitalWrite (LedGreen,LOW);
      delay(250);
      tone(piezo, 1500, 500);
      digitalWrite (LedBlue, HIGH);
      delay(100);
      digitalWrite (LedBlue,LOW);
      delay(250);

      digitalWrite (LedRed, HIGH);
      delay(50);
      digitalWrite (LedRed, LOW);
      delay(50);
      }

      void playSong2() {
      tone(piezo, 200, 250);
      digitalWrite (LedRed, HIGH);
      delay(50);
      digitalWrite (LedRed,LOW);
      delay(150);
      tone(piezo, 250, 250);
      digitalWrite (LedGreen, HIGH);
      delay(50);
      digitalWrite (LedGreen,LOW);
      delay(150);
      tone(piezo, 300, 250);
      digitalWrite (LedBlue, HIGH);
      delay(50);
      digitalWrite (LedBlue,LOW);
      delay(150);

      tone(piezo, 300, 250);
      digitalWrite (LedRed, HIGH);
      delay(50);
      digitalWrite (LedRed,LOW);
      delay(150);
      tone(piezo, 250, 250);
      digitalWrite (LedGreen, HIGH);
      delay(50);
      digitalWrite (LedGreen,LOW);
      delay(150);
      tone(piezo, 200, 250);
      digitalWrite (LedBlue, HIGH);
      delay(50);
      digitalWrite (LedBlue,LOW);
      delay(150);

      tone(piezo, 200, 250);
      digitalWrite (LedRed, HIGH);
      delay(50);
      digitalWrite (LedRed,LOW);
      delay(150);
      tone(piezo, 250, 250);
      digitalWrite (LedGreen, HIGH);
      delay(50);
      digitalWrite (LedGreen,LOW);
      delay(150);
      tone(piezo, 300, 250);
      digitalWrite (LedBlue, HIGH);
      delay(50);
      digitalWrite (LedBlue,LOW);
      delay(150);

      tone(piezo, 300, 250);
      digitalWrite (LedRed, HIGH);
      delay(50);
      digitalWrite (LedRed,LOW);
      delay(150);
      tone(piezo, 250, 250);
      digitalWrite (LedGreen, HIGH);
      delay(50);
      digitalWrite (LedGreen,LOW);
      delay(150);
      tone(piezo, 200, 250);
      digitalWrite (LedBlue, HIGH);
      delay(50);
      digitalWrite (LedBlue,LOW);
      delay(150);

      digitalWrite (LedBlue, HIGH);
      delay(50);
      digitalWrite (LedBlue, LOW);
      delay(50);
      }
      
      // creat a behavior when guessing correct
      void guessRight() {
        servo.write (angle-90);
        tone(piezo,1000,500);
        delay(100);
        tone(piezo,1200,500);
        delay(100);
        tone(piezo,1300,500);
        delay(100);
        tone(piezo,1500,500);
        delay(100);
        tone(piezo,1800,500);
        digitalWrite(LedWhite1,HIGH);
        digitalWrite(LedWhite2,HIGH);
        delay(500);
        digitalWrite(LedWhite1,LOW);
        digitalWrite(LedWhite2,LOW);
        delay(500);
        }
        
      // creat a behavior when guessing incorrect
      void guessWrong() {
        servo.write (angle+90);
        tone(piezo,150,1000);
        digitalWrite(LedWhite1,HIGH);
        digitalWrite(LedWhite2,HIGH);
        delay(500);
        digitalWrite(LedWhite1,LOW);
        digitalWrite(LedWhite2,LOW);
        delay(500);
        digitalWrite(LedHint, HIGH);
        delay(1000);
        digitalWrite(LedHint, LOW);
        }
