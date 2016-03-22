// constants won't change. They're used here to
// set pin numbers:
const int redLightPin   = 13; //arduino digital pin 11 controls red light
const int greenLightPin = 12; //arduino digital pin 12 controls green light
const int blueLightPin  = 11; //arduino digital pin 13 controls blue light

// Variables will change:
int redLedState   = HIGH;         // the current state of the red light output pin
int greenLedState = HIGH;         // the current state of the green light output pin
int blueLedState  = HIGH;         // the current state of the blue light output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastRedLedChangeTime   = 0;  // the last time the output pin was toggled
long lastGreenLedChangeTime = 0;  // the last time the output pin was toggled
long lastBlueLedChangeTime  = 0;  // the last time the output pin was toggled
long redLightChangeDelay    = 50;    // the debounce time; increase if the output flickers
long greenLightChangeDelay  = 50;    // the debounce time; increase if the output flickers
long blueLightChangeDelay   = 50;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:
  // initialize digital light pins as outputs.
  pinMode(redLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(blueLightPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //release balls

  //flash lights
  if ((millis() - lastRedLedChangeTime) > redLightChangeDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    redLedState = !redLedState;
    lastRedLedChangeTime = millis();
  }

  digitalWrite(redLightPin, redLedState);

  //display final light pattern
  int lightKey = random(2);
  switch (lightKey)
  {
    case 1:
//    Serial.println("displaying final light pattern: ");
    break;

      //read direction
  {
  case 2:
  Serial.println("reading direction given by child to kinect: ");
  break;
    
  }

  //set gates

  //grade effort

  }
  
  
  


  

}
