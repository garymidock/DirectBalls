// constants won't change. They're used here to
// set pin numbers:
const int redLightPin    = 5; //arduino digital pin 5 controls red light
const int greenLightPin  = 6; //arduino digital pin 6 controls green light
const int blueLightPin   = 7; //arduino digital pin 7 controls blue light

const int ballReleasedPin    = 22; //pin 2 is 1 when ball is released
const int Pin3               = 3;  //WHY IS PIN 3 ALWAYS 1? It is always 1 do to the motor driver on the motor control shield
const int ballAtGatePin      = 24; //pin 4 is 1 when ball is at gate

// Variables will change:
int redLedState          = HIGH;         // the current state of the red light output pin
int greenLedState        = HIGH;         // the current state of the green light output pin
int blueLedState         = HIGH;         // the current state of the blue light output pin
int stateNum             = 1;            // contains the number of the state being executed
int lastButtonState      = LOW;          // the previous reading from the input pin
int ballAtGate           = 0;            // when true, display final light pattern
int ballReleased         = 0;            // when true, ball has been released, flash lights
int switchState          = 0;            // 1 = switch state
int valueOfPin3          = 0;
// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastRedLedChangeTime   = 0;     // the last time the output pin was toggled
long lastGreenLedChangeTime = 0;     // the last time the output pin was toggled
long lastBlueLedChangeTime  = 0;     // the last time the output pin was toggled
long redLightChangeDelay    = 150;    // the debounce time; increase if the output flickers
long greenLightChangeDelay  = 50;    // the debounce time; increase if the output flickers
long blueLightChangeDelay   = 250;    // the debounce time; increase if the output flickers

//testing variables
int counter = 0;
long timeForStateChange = 15000;     //stay in a particular state for this time only

void setup() {
  // put your setup code here, to run once:
  // initialize digital light pins as outputs.
  Serial.begin(9600);
  pinMode(redLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(blueLightPin, OUTPUT);

  pinMode(ballReleased, INPUT);
  pinMode(ballAtGate, INPUT);

  pinMode(Pin3, INPUT);

  Serial.println("end of setup");
  Serial.print("timeForStateChange: " );
  Serial.println(timeForStateChange);

}

void loop() {
  // put your main code here, to run repeatedly:
  ballReleased = digitalRead(ballReleasedPin);
  ballAtGate   = digitalRead(ballAtGatePin);

  

  Serial.print("ballReleased: ");
  Serial.println(ballReleased);
  Serial.print("ballAtGate: ");
  Serial.println(ballAtGate);

  int valueOfPin3 = digitalRead(Pin3);
  Serial.print("valueOfPin3: ");
  Serial.println(valueOfPin3);
  

  switch (stateNum)
  {

    //release balls
    case 1:
    if (ballReleased == 1)
    {
      stateNum = 2; //balls have been released so flash lights
    }
      break;

    //flash lights
    case 2:
      if ((millis() - lastRedLedChangeTime) > redLightChangeDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        redLedState = !redLedState;
        lastRedLedChangeTime = millis();
      }

      if ((millis() - lastGreenLedChangeTime) > greenLightChangeDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        greenLedState = !greenLedState;
        lastGreenLedChangeTime = millis();
      }

      if ((millis() - lastBlueLedChangeTime) > blueLightChangeDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        blueLedState = !blueLedState;
        lastBlueLedChangeTime = millis();
      }
      if (ballAtGate == 1)
      {
                stateNum += 1; //lights have been flashing and ball is in position for final light pattern
        //        break;
      }

      break;

    //display final light pattern
    case 3:
      digitalWrite(redLightPin, LOW);
      redLedState = LOW;
      digitalWrite(greenLightPin, LOW);
      greenLedState = LOW;
      digitalWrite(blueLightPin, HIGH);
      blueLedState = HIGH;

      //set gates

      //grade effort

  }
  digitalWrite(redLightPin, redLedState);
  digitalWrite(greenLightPin, greenLedState);
  digitalWrite(blueLightPin, blueLedState);
  Serial.print("stateNum: ");
  Serial.println(stateNum);


}

