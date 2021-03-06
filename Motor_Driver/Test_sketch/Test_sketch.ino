int In1 = 8;
int In2 = 9;
int In3 = 10;
int In4 = 11;
int EnA = 5; //right motor speed control: PWM pin on Arduino denoted by "~"
int EnB = 6;  //left motor speed control: PWM pin on Arduino denoted by "~"

void accelerate() // accelerate from rest to maximum speed
{
  for (int i = 0; i < 151; i++)
  {
    analogWrite(EnA, i);
    analogWrite(EnB, i);
    delay(100);
  }
} 
void decelerate()  // decelerate from maximum speed to rest
{
  for (int i = 150; i >= 0; --i)
  {
    analogWrite(EnA, i);
    analogWrite(EnB, i);
    delay(100);
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
void setup() 
{
  // put your setup code here, to run once:
  
  // All motor control pins are outputs
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  goForward();
  delay(2000);
  decelerate();
  noGo();
  delay(1000);
  accelerate();
  goBackward();
  delay(2000);
  decelerate();
  noGo();
  delay(1000);
}
