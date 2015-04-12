#include <FastPin.h>

FastPin led(13);

void setup() {
  // put your setup code here, to run once:
  led.output();
}

void loop() {
  // put your main code here, to run repeatedly:
  led.high();
  delay(500);
  
  led.low();
  delay(500);
}
