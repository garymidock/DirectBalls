// constants won't change. They're used here to
// set pin numbers:
const int redLightPin   = 5; //arduino digital pin 11 controls red light
const int greenLightPin = 6; //arduino digital pin 12 controls green light
const int blueLightPin  = 7; //arduino digital pin 13 controls blue light

// Variables will change:
int redLedState          = HIGH;         // the current state of the red light output pin
int greenLedState        = HIGH;         // the current state of the green light output pin
int blueLedState         = HIGH;         // the current state of the blue light output pin
int stateNum             = 1;            // contains the number of the state being executed
int lastButtonState      = LOW;          // the previous reading from the input pin
int ballIsInPosition     = 0;            // when true, display final light pattern

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

  Serial.println("end of setup");
  Serial.print("timeForStateChange: " );
  Serial.println(timeForStateChange);

}

void loop() {
  // put your main code here, to run repeatedly:

  switch (stateNum)
  {

    //release balls
    case 1:
      stateNum = 2; //balls have been released so flash lights
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
      //      int timeDiff =0;
      //      Serial.print("timeDiff: ");
      //      Serial.println(timeDiff);

      //      if ((millis() - timeForStateChange) < 0)
      //      {
      //        Serial.println("setting ballIsInPostion to 1");
      //        ballIsInPosition = 1;
      //      }
      if (millis() > timeForStateChange)
      {
        stateNum = 3;

      }
      if (ballIsInPosition == 1)
      {
        //        stateNum = 3; //lights have been flashing and ball is in position for final light pattern
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
  Serial.print("millis(): ");
  Serial.println(millis());
  Serial.print("stateNum: ");
  Serial.println(stateNum);


}

