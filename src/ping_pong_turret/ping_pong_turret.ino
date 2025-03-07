#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Servo myServo;
Servo rotatingServo;

#define CLK A0
#define DT A1
#define SW A2

int counter = 90;
int currentStateCLK;
int lastStateCLK;

unsigned long lastButtonPress = 0;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;


void setup() {
  myServo.attach(6); // Attach the servo to pin 6
  rotatingServo.attach(7);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

    // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);

  pinMode(SW, INPUT_PULLUP);
  // Setup Serial Monitor
  Serial.begin(9600);
  myServo.write(counter);
  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  rotatingServo.write(89); //stop rotation
}

void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      if (counter<0)
        counter=0;
    } else {
      // Encoder is rotating CW so increment
      counter ++;
      if (counter>179)
        counter=179;
    }
    // Move the servo
    myServo.write(counter);
    Serial.print("Position: ");
    Serial.println(counter);
  }
  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  // Read the button state
  int btnState = digitalRead(SW);
  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
      start_shooter();
    }
    // Remember last button press event
    lastButtonPress = millis();
  }

  delay(1);
}

// void servoSweep() {
//   int servoDelay = 30;
//   int servoAngle;

//   // Sweep from 0 to 180 degrees
//   for (servoAngle = 60; servoAngle <= 80; servoAngle += 5) {
//     myServo.write(servoAngle);
//     delay(servoDelay);
//   }

//   // Sweep from 180 to 0 degrees
//   for (servoAngle = 80; servoAngle >= 60; servoAngle -= 5) {
//     myServo.write(servoAngle);
//     delay(servoDelay);
//   }
// }

void shooter(){
  delay(1000);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(2000);

  rotatingServo.write(0);
  delay(250);
  rotatingServo.write(89);

  delay(1000);
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  delay(500);


}

void start_shooter(){

  myStepper.setSpeed(15);
  myStepper.step(stepsPerRevolution / 8);
  delay(1000);

  shooter();

  myStepper.setSpeed(15);
  myStepper.step(-stepsPerRevolution / 8);
  delay(1000);

  shooter();

  // Rotate CCW quickly at 10 RPM
  myStepper.setSpeed(15);
  myStepper.step(-stepsPerRevolution / 8);
  delay(1000);

  shooter();

  myStepper.setSpeed(15);
  myStepper.step(stepsPerRevolution / 8);

}
