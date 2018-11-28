int trigPin = 0;
int echoPin = 0;

// defines pins numbers
const int trig1 = 30;
const int echo1 = 31;
const int trig2 = 32;
const int echo2 = 33;
const int trig3 = 34;
const int echo3 = 35;
const int trig4 = 36;
const int echo4 = 37;
const int trig5 = 22;
const int echo5 = 24;
const int trig6 = 40;
const int echo6 = 41;
const int trig7 = 42;
const int echo7 = 43;
const int trig8 = 44;
const int echo8 = 45;

// defines variables
long duration;
int distance;
boolean sensor1 = false;
boolean sensor2 = false;
boolean sensor3 = false;
boolean sensor4 = false;
boolean sensor5 = false;
boolean sensor6 = false;
boolean sensor7 = false;
boolean sensor8 = false;
  const int myTrigPins[] = {trig1, trig2, trig3, trig4, trig5, trig6, trig7, trig8};
  const int myEchoPins[] = {echo1, echo2, echo3, echo4, echo5, echo6, echo7, echo8};
  int sensorStates[] = {sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7, sensor8};
  int savedDistanceVals[] = {0,0,0,0,0,0,0,0};

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
    const char* directionWords[] = {"Left Side", "Left Corner", "Front", "Right Corner", "Right Side", "Right Rear Corner", "Back", "Left Rear Corner"};
    Serial.print(directionWords[i]);
    Serial.print(": ");
    Serial.println(distance);

    //saving distance/duration values
    savedDistanceVals[i] = distance;

    //change 1 val to real distance limit
   
    if (savedDistanceVals[i] < 10) {
      sensorStates[i] = true;
    }

    else if (savedDistanceVals[i] > 10) {
      sensorStates[i] = false;
    }

  }

  for (int i = 0; i <= 7; i++) {
    Serial.print(sensorStates[i]);
    if (i == 7) {
      Serial.println();
    }
  }
  
  // turns sensor state array into a string of 0s and 1s
  String stringy = "";
  for (int i = 0; i <= 7; i++) {
    stringy += sensorStates[i];
  }

  // creates an array of case states of 0s and 1s and corresponding word associated with it
  const char* stateCases[] = {"10000000", "11100000", "11000000", "10100000", "01100000", "00100000", "01010000",
  "01110000", "00111000", "00011000", "00101000", "00110000", "00001000", "00001110", "00001100", "00000110",
  "00001010", "00000111", "00000101", "00000010", "10000011", "10000001", "10000010", "00000011"};
  
  const char* wordCases[] = {"Left Wall", "Left Front Corner", "Left Front Corner", "Left Front Corner", 
  "Left Front Corner", "Front Wall", "Front Corner", "Front Corner", "Right Front Corner", "Right Front Corner", 
  "Right Front Corner", "Right Front Corner", "Right Wall", "Right Rear Corner", "Right Rear Corner",
  "Right Rear Corner", "Right Rear Corner", "Rear Corner", "Rear Corner", "Rear Wall", "Left Rear Corner", 
  "Left Rear Corner", "Left Rear Corner", "Left Rear Corner"};
  
  String myCase = myStateFunction(stringy, stateCases, wordCases);
  Serial.println(myCase);


  //vector


}

String myStateFunction(String x, const char* y[], const char* z[]){
  String result;
  for (int i = 0; i <= 24; i++) {
    if (x == y[i]) {
      result = z[i];
      return result;
    }
  }
}
