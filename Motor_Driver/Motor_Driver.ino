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

//ultrasonic sensor variable initilization
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
  int savedDistanceVals[] = {0,0,0,0,0};




void accelerate() // accelerate from rest to maximum speed
{
  for (int i = 0; i < 256; i++)
  {
    analogWrite(EnA, i);
    analogWrite(EnB, i);
    delay(20);
  }
} 
void decelerate()  // decelerate from maximum speed to rest
{
  for (int i = 255; i >= 0; --i)
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
  analogWrite(EnA, 200);
  // forward right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnB, 200);
}
void goBackward()   //run both motors backward simultaneously
{
  // reverse left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnA, 200);
  // reverse right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnB, 200);
}
void goLeft()   //run left motor forward and right motor backward
{
  // forward left motor
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnA, 200);
  // reverse right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnB, 200);
}
void goRight()   //run left motor backward and right motor forward
{
  // reverse left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  // set speed out of possible range 0~255
  analogWrite(EnA, 200);
  // forward right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed out of possible range 0~255
  analogWrite(EnB, 200);
}
void noGo() //turn off both motors to stop
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW); 
}
void leftCorner()
{
  goLeft();
  delay(1000);
  goBackward();
  delay(1000);
  goRight();
  delay(2000);
  noGo();
  checkSurroundings();  
}
void rightCorner()
{
  goRight();
  delay(1000);
  goBackward();
  delay(1000);
  goLeft();
  delay(2000);
  noGo();
  checkSurroundings();
}
void leftWall()
{
  goRight();
  delay(1000);
  noGo();
  checkSurroundings();
}
void rightWall()
{
  goLeft();
  delay(1000);
  noGo();
  checkSurroundings();
}
void frontWall()
{
  goBackward();
  delay(1000);
  noGo();
  checkDistances();
  if (leftDistance < rightDistance)
  {
    goRight();
  }
  else 
  {
    goLeft();
  }
  delay(1000);
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
  findPerson(); 
  if (pixyDistance < pixyTrigger)
  {
    noGo();
  }
  else 
  {
    checkSurroundings();
    if (obstacle = "left corner")
    {
      leftCorner();
    }
    else if (obstacle = "right corner")
    {
      rightCorner();
    }
    else if (obstacle = "left wall")
    {
      leftWall();
    }
    else if (obstacle = "right wall")
    {
      rightWall();
    }
    else if (obstacle = "front wall")
    {
      frontWall();
    }
    else
    {
      goForward();
    } 
  }
}