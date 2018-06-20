//created by Mkerner1876 @ https://github.com/Mkerner1876/Arduino-Plane-w-radio
#include<Servo.h>
Servo thrustServo;
Servo aileron1;
Servo aileron2;
Servo rudder1;
Servo landing1;
Servo landing2;
Servo landing3;
Servo cargobay;
int thrustcount = 0;
int state;
int flag = 0;      //makes sure that the serial only prints once the state
int stateStop = 0;
void setup() {
  thrustServo.attach(8);
  aileron1.attach(2);
  aileron2.attach(3);
  rudder1.attach(4);
  landing1.attach(5);
  landing2.attach(6);
  landing3.attach(7);
  aileron1.write(90);
  aileron2.write(90); //ailerons will point up, so they will be level with this.
  landing1.write(90);
  landing2.write(90);
  landing3.write(90); //deploys gear to take off
}

void loop() {
  Serial.begin(9600);
  if (Serial.available() > 0) {
    state = Serial.read();
    flag = 0;
  }
  if (state == 'F') {
    //thurst servo up
    thrustcount++;
    if (flag == 0) {
      Serial.print("Increased thrust.");
      flag = 1;
    }
  }
  else if (state == 'B') {
    //thurst servo down
    thrustcount--;
    if (flag == 0) {
      Serial.print("Decreased thrust.");
      flag = 1;
    }
  }
  if (thrustcount == 0) {
    thrustServo.write(0);
  }
  if (thrustcount == 1) {
    thrustServo.write(36);
  }
  if (thrustcount == 2) {
    thrustServo.write(72);
  }
  if (thrustcount == 3) {
    thrustServo.write(108);
  }
  if (thrustcount == 4) {
    thrustServo.write(144);
  }
  if (thrustcount == 5) {
    thrustServo.write(180);
  }
  else if (state == 'Q') {
    //plane aileron roll left
    aileron1.write(135);
    delay(1000);
    aileron1.write(90);
    if (flag == 0) {
      Serial.print("Turned left.");
      flag = 1;
    }
  }
  else if (state == 'E') {
    //plane aileron roll right
    aileron2.write(135);
    delay(1000);
    aileron2.write(90);
    if (flag == 0) {
      Serial.print("Turned right.");
      flag = 1;
    }
  }
  else if (state == 'S') {
    //engines stop
    thrustServo.write(0);
    if (flag == 0) {
      Serial.print("Engines stopped.");
      flag = 1;
    }
  }
  else if (state == 'U') {
    //plane up
    aileron1.write(135);
    aileron2.write(135);
    if (flag == 0) {
      Serial.print("Aileron Up.");
      flag = 1;
    }
  }
  else if (state == 'N') {
    //plane levels
    aileron1.write(90);
    aileron2.write(90);
    if (flag == 0) {
      Serial.print("Plane level.");
      flag = 1;
    }

  }
  else if (state == 'D') {
    //plane down
    aileron1.write(45);
    aileron1.write(45);

    if (flag == 0) {
      Serial.print("Aileron down.");
      flag = 1;
    }
  }
  if (state == 'O') {
    //landing up
    landing1.write(0);
    landing2.write(0);
    landing3.write(0);
    if (flag == 0) {
      Serial.print("Landing gear deploying.");
      flag = 1;
    }
  }
  if (state == 'P') {
    landing1.write(90);
    landing2.write(90);
    landing3.write(90);
    //landing down

  }
 
}

