int trigPin = 0;
 int echoPin = 0;

// defines pins numbers
const int trig1 = 9;
const int echo1 = 10;
const int trig2 = 11;
const int echo2 = 12;
/*const int trig3 = ;
const int echo3 = ;
const int trig4 = ;
const int echo4 = ;*/

// defines variables
long duration;
int distance;
boolean sensor1 = false;
boolean sensor2 = false;
boolean sensor3 = false;
boolean sensor4 = false;
  int myTrigPins[] = {trig1, trig2};
  int myEchoPins[] = {echo1, echo2};
  int sensorStates[] = {sensor1, sensor2};
  int savedDistanceVals[] = {0,0};

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  for (int i = 1; i <= 2; i++) {
    //setting pins in this iteration of the loop
    trigPin = myTrigPins[i - 1];
    echoPin = myEchoPins[i - 1];

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance in centimeters
    distance = duration * 0.034 / 2;

    // Prints the distance on the Serial Monitor
    //Serial.print("Distance (cm): ");
    int directionWords[] = {"Left Side", "Left Corner", "Front", "Right Corner", "Right Side"};
    /* Serial.println(directionWords[i-1]);
    Serial.print(": ");
    Serial.println(distance); */
    String directionOutput = directionWords[i-1] + ": " + String(distance);
    Serial.print(directionOutput);

    //saving distance/duration values
    savedDistanceVals[i - 1] = distance;
  }

  for (int i = 1; i <= 2; i++) {
    //change 1 val to real distance limit
    if (savedDistanceVals[i - 1] < 1) {
      sensorStates[i - 1] = false;
    }
  }

  //vector shit



}
