/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int button = 8;        // pin for the button

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);       //configure as output
  pinMode(button, INPUT);     //configure as Input
}

// the loop routine runs over and over again forever:
void loop() {
  while(digitalRead(button)==LOW)
  {
    analogWrite(led,0);       //while butten pressed led off
  }
                              //else fading the led
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // set the brightness to zero ones the it fully bright
  if (brightness >= 255) {
   brightness =0;
   }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
