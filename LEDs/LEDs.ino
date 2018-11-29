int ledOn = A1; // the pin the LED is connected to
int ledOff = A4;

void setup() {
  pinMode(ledOn, OUTPUT); // Declare the LED as an output
  pinMode(ledOff, OUTPUT);
}

void loop() {
  digitalWrite(ledOn, HIGH); // Turn the LED on
  delay(2000);
  digitalWrite(ledOn, LOW);
  delay(2000);
  digitalWrite(ledOff, HIGH);
  delay(2000);
  digitalWrite(ledOff, LOW);
  delay(2000);
}
