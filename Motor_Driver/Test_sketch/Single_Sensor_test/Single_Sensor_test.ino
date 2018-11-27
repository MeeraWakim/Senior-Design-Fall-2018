int trigPin = 0;
int echoPin = 0;

int triggerDistance = 10;

//Motor Connection pin definitions
int EnA = 10; //right motor speed control: PWM pin on Arduino denoted by "~"
int EnB = 5;  //left motor speed control: PWM pin on Arduino denoted by "~"
int In1 = 9;
int In2 = 8;
int In3 = 7;
int In4 = 6;

//ultrasonic sensor pin definitions
const int trig1 = 51;
const int echo1 = 53;

//ultrasonic sensor variable initilization
long duration;
int distance;
boolean sensor1 = false;

  const int myTrigPins[] = {trig1};
  const int myEchoPins[] = {echo1};
  int sensorStates[] = {sensor1};
  int savedDistanceVals[] = {0};

boolean checkSurroundings(){
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

    if (distance <= triggerDistance)
    {
      sensor1 = true;
    }
    else 
    {
      sensor1 = false
    }

    return sensor1;
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
  checkSurroundings();  
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
  checkSurroundings();
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
  checkSurroundings();
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
  checkSurroundings();
}
void leftWall()
{
  goRight();
  delay(500);
  noGo();
  checkSurroundings();
}
void rightWall()
{
  goLeft();
  delay(500);
  noGo();
  checkSurroundings();
}
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
  goForward();
  checkSurroundings();
  if (sensor1 = true)
  {
    noGo();
    delay(100);
    goBackward();
    delay(1000);
    goLeft();
    delay(2000);
  }
  else
  {
    goForward();
  }
}
