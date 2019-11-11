int ledT = 8;     
int delayCount = 0;

void setup() {
  pinMode(ledT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delayCount= analogRead(A4) + 50;
  digitalWrite(ledT, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayCount);                       // wait for a second
  digitalWrite(ledT, LOW);    // turn the LED off by making the voltage LOW
  delay(delayCount); 
}
