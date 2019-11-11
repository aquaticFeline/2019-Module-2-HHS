/*
 Edit: using the basis of the fade program and circuit,
  a potentiometer was wired up on A4. As it's turned,
  the LED gets dimmer or brighter, and the values are
  printed to serial port. The LED is not visibly
  blinking, but it blinks to accomplish the dimming
  and brightening effect.
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int ledT = 8;     
int delayCount = 0;


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(ledT, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  // should affect blink speed 
  brightness = analogRead(A4)/10;
  Serial.println(brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  // wait for 30 milliseconds to see the dimming effect

  //delay(30);
  
  delayCount= analogRead(A4) + 50;
  digitalWrite(ledT, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayCount);                       // wait for a second
  digitalWrite(ledT, LOW);    // turn the LED off by making the voltage LOW
  delay(delayCount); 
}
