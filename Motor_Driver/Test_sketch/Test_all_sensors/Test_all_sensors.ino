//sets trigger distances
int smallTrigger = 10;
int largeTrigger = 35;
String myCase = "";

//zero ultrasonic sensor mode
int trigPin = 0;
int echoPin = 0;

//Motor Connection pin definitions
int EnA = 10; //right motor speed control: PWM pin on Arduino denoted by "~"
int EnB = 5;  //left motor speed control: PWM pin on Arduino denoted by "~"
int In1 = 9;
int In2 = 8;
int In3 = 7;
int In4 = 6;

//Ultrasonic sensor pin definitions
const int trig1 = 43;
const int echo1 = 45;
const int trig2 = 47;
const int echo2 = 49;
const int trig3 = 51;
const int echo3 = 53;
const int trig4 = 42;
const int echo4 = 44;
const int trig5 = 26;
const int echo5 = 28;
const int trig6 = 22;
const int echo6 = 24;
const int trig7 = 31;
const int echo7 = 33;
const int trig8 = 34;
const int echo8 = 36;

//ultrasonic sensor variable initilization
long duration;
int distance;
boolean sensor1 = false;
boolean sensor2 = false;
boolean sensor3 = false;
boolean sensor4 = true;
boolean sensor5 = false;
boolean sensor6 = false;
boolean sensor7 = false;
boolean sensor8 = false;
  const int myTrigPins[] = {trig1, trig2, trig3, trig4, trig5, trig6, trig7, trig8};
  const int myEchoPins[] = {echo1, echo2, echo3, echo4, echo5, echo6, echo7, echo8};
  int sensorStates[] = {sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7, sensor8};
  int savedDistanceVals[] = {0,0,0,0,0,0,0,0};


String checkSurroundings()
{
    for (int i = 0; i < sizeof(myTrigPins)/sizeof(myTrigPins[0]); i++) 
    {
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
  
      //saving distance/duration values
      savedDistanceVals[i] = distance;

      
      
  
      //change 1 val to real distance limit
      if (i == 3) 
      {
        sensorStates[i] = false;
      }
      
      if (savedDistanceVals[i] < smallTrigger and i != 3) 
      {
        sensorStates[i] = true;
      }
  
      else if (savedDistanceVals[i] > smallTrigger) 
      {
        sensorStates[i] = false;
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

  //output state from "checkSurroudings"
  return myCase;
}

//output function for "checkSurroudings"
String myStateFunction(String x, const char* y[], const char* z[])
{
  String result;
  for (int i = 0; i <= 24; i++) {
    if (x == y[i]) {
      result = z[i];
      return result;
    }
  }
}

void accelerate() // accelerate from rest to maximum speed
{
  for (int i = 100; i < 150; i++)
  {
    analogWrite(EnA, i);
    analogWrite(EnB, i);
    delay(20);
  }
} 
void decelerate()  // decelerate from maximum speed to rest
{
  for (int i = 150; i >= 100; --i)
  {
    analogWrite(EnA, i);
    analogWrite(EnB, i);
    delay(20);
  } 
}
void goForward()   //run both motors forward simultaneously
{
  // forward left motor
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnA, 150);
  // forward right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnB, 150);
}
  void noGo() //turn off both motors to stop
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW); 
}

void goBackward()   //run both motors backward simultaneously
{
  // reverse left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnA, 150);
  // reverse right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnB, 150);
}
void goLeft()   //run left motor forward and right motor backward
{
  // forward left motor
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnA, 150);
  // reverse right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnB, 150);
}
void goRight()   //run left motor backward and right motor forward
{
  // reverse left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnA, 150);
  // forward right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnB, 150);
}
void leftFrontCorner()
{
  goLeft();
  delay(500);
  goBackward();
  delay(500);
  goRight();
  delay(1000);
  noGo();
//  checkSurroundings();  
}
void rightFrontCorner()
{
  goRight();
  delay(500);
  goBackward();
  delay(500);
  goLeft();
  delay(1000);
  noGo();
//  checkSurroundings();
}
void rightRearCorner()
{
  goLeft();
  delay(500);
  goForward();
  delay(500);
  goRight();
  delay(1000);
  noGo();
//  checkSurroundings();
}
void leftRearCorner()
{
  goRight();
  delay(500);
  goForward();
  delay(500);
  goLeft();
  delay(1000);
  noGo();
//  checkSurroundings();
}
void leftWall()
{
  goRight();
  delay(500);
  noGo();
//  checkSurroundings();
}
void rightWall()
{
  goLeft();
  delay(500);
  noGo();
//  checkSurroundings();
}
//void frontWall()
//{
//  goBackward();
//  delay(500);
//  noGo();
//  checkDistances();
//  if (leftDistance < rightDistance)
//  {
//    goRight();
//  }
//  else 
//  {
//    goLeft();
//  }
//  delay(500);
//  noGo();
//  checkSurroundings();     
//}
void setup()
{
  // All motor control pins are outputs
    pinMode(EnA, OUTPUT);
    pinMode(EnB, OUTPUT);
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);

  //ultrasonic sensor setup
  for(int i = 0; i < sizeof(myTrigPins)/sizeof(myTrigPins[0]); i++)
  {
    pinMode(myTrigPins[i], OUTPUT);
    pinMode(myEchoPins[i], INPUT);
  }
  Serial.begin(9600); // Starts the serial communication
}


void loop() //makes cart go zoom zoom
{
for (int i = 0; i < sizeof(myTrigPins)/sizeof(myTrigPins[0]); i++) 
    {
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
  
      //saving distance/duration values
      savedDistanceVals[i] = distance;
  
      //change 1 val to real distance limit
      if (i == 3) 
      {
        sensorStates[i] = false;
      }
      
      if (savedDistanceVals[i] < smallTrigger and i != 3) 
      {
        sensorStates[i] = true;
      }
  
      else if (savedDistanceVals[i] > smallTrigger) 
      {
        sensorStates[i] = false;
      }
    }

  
  // turns sensor state array into a string of 0s and 1s
  String stringy = "";
  for (int i = 0; i <= 7; i++) 
  {
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

  //display myCase
  Serial.print(myCase);
}
