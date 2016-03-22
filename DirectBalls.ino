int redLightPin   = 11; //arduino digital pin 11 controls red light
int greenLightPin = 12; //arduino digital pin 12 controls green light
int blueLightPin  = 13; //arduino digital pin 13 controls blue light
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

  //display final light pattern
  int lightKey = random(2);
  switch (lightKey)
  {
    case 1:
    Serial.println("displaying final light pattern: ");
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
