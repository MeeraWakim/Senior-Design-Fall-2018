// defines pins numbers
const int trig1 = ;
const int echo1 = ;
const int trig2 = ;
const int echo2 = ;
const int trig3 = ;
const int echo3 = ;
const int trig4 = ;
const int echo4 = ;

// defines variables
long duration;
int distance;
boolean sensor1 = false;
boolean sensor2 = false;
boolean sensor3 = false;

boolean sensor5 = false; // this is a comment :)
//hello yes?
//poop diddy scoop

//hopefully this causes a merge conflict
//scoop diddy woop
//they say disneyland is the happiest place on earth, but apparently they've never been to the ETC.


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
int myTrigPins[] = {trig1, trig2, trig3, trig4};
int myEchoPins[] = {echo1, echo2, echo3, echo4};
int sensorStates[] = {sensor1,sensor2,sensor3,sensor4};
int savedDistanceVals[] = [4];
}

void loop() {

  for (int i=1; i <= 4; i++){
    //setting pins in this iteration of the loop
    trigPin = myTrigPins[i-1];
    echoPin = myEchoPins[i-1];
    
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance = duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
  
    //saving distance/duration values
    savedDistanceVals[i-1] = distance;      
  }

  for (int i=1; i <= 4; i++){
    //change 1 val to real distance limit
    if(savedDistanceVals[i-1]<1){
      sensorStates[i-1] = false;
    }
  }

  //vector shit
  
  

}
