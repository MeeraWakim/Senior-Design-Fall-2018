// this code just turns on the lights and then off after a delay

int RED_LED = 49;
int BLUE_LED = 51;
int GREEN_LED = 53;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}
void loop() {
  digitalWrite(RED_LED, HIGH);   
  delay(1000); 
  digitalWrite(GREEN_LED, HIGH);   
  delay(1000);   
  digitalWrite(RED_LED, LOW);   
  delay(1000); 
  digitalWrite(GREEN_LED, LOW);   
  delay(1000);   
}
