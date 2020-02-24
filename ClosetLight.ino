/***************************
Title: Closet Light
Author: Dalton Vislisel
Description: This code is for an Arduino Uno equipped with a sonar sensor to automatically turn on LED strips when the door is opened.
Date of Last Edit: 2/24/2020
****************************/

//Define the pins you used on your Arduino with their corresponding LED colors.
#define REDPIN 3
#define GREENPIN 6
#define BLUEPIN 5

//Define the two pins used for the sonar sensor to operate.
#define trigPin 11
#define echoPin 12

void setup() {
  //Telling the Arduino what each used pin’s job is.
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //Declare variables for red, green, and blue lights. Declare variables for the sonar sensor to compute the equation for distance. 
  long duration, cm;
  int r, g, b;
  cm = 0;
  duration = 0;

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  //Equation for the sonar sensor to output in cm.
  cm = (duration/2) / 29.1;

  /*
  Code used to print the sonar sensor output for testing.
  Serial.print(cm);
  */

  //If the sensor reads over 50 cm the lights turn white, anything under 50 cm the lights will be off. 
  //Change the r,g,b values to change the color.
  if (cm > 50){
  r = 255;
  g = 255;
  b = 255;

  analogWrite(REDPIN, r);
  analogWrite(BLUEPIN, b);
  analogWrite(GREENPIN, g);
  }else{
  r = 0;
  g = 0;
  b = 0;

  analogWrite(REDPIN, r);
  analogWrite(BLUEPIN, b);
  analogWrite(GREENPIN, g);
  }

  //Change this if you dont want the code to constanly run.
  delayMicroseconds(1000000000000);
}
