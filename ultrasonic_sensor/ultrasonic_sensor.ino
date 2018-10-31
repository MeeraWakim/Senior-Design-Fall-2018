int trigPin = 0;
int echoPin = 0;

// defines pins numbers
const int trig1 = 8;
const int echo1 = 9;
const int trig2 = 10;
const int echo2 = 11;
const int trig3 = 12;
const int echo3 = 13;
const int trig4 = 6;
const int echo4 = 7;
const int trig5 = 2;
const int echo5 = 3;

// defines variables
long duration;
int distance;
boolean sensor1 = false;
boolean sensor2 = false;
boolean sensor3 = false;
boolean sensor4 = false;
boolean sensor5 = false;
  const int myTrigPins[] = {trig1, trig2, trig3, trig4, trig5};
  const int myEchoPins[] = {echo1, echo2, echo3, echo4, echo5};
  int sensorStates[] = {sensor1, sensor2, sensor3, sensor4, sensor5};
  int savedDistanceVals[] = {0,0};

void setup() {
  for(int i = 0; i < sizeof(myTrigPins)/sizeof(myTrigPins[0]); i++){
    pinMode(myTrigPins[i], OUTPUT);
    pinMode(myEchoPins[i], INPUT);
  }
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  for (int i = 0; i < sizeof(myTrigPins)/sizeof(myTrigPins[0]); i++) {
    //setting pins in this iteration of the loop
    trigPin = myTrigPins[i];
    echoPin = myEchoPins[i];

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
    Serial.println(i);
    Serial.print(": ");
    Serial.println(distance);

    //saving distance/duration values
    savedDistanceVals[i] = distance;
  }

  for (int i = 1; i <= 2; i++) {
    //change 1 val to real distance limit
    if (savedDistanceVals[i - 1] < 1) {
      sensorStates[i - 1] = false;
    }
  }

  //vector



}
