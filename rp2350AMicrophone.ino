/*
   Mono analog microphone example using electret mike on A0
   Run using the Arduino Serial Plotter to see waveform.
   Released to the Public Domain by Earle F. Philhower, III

   Wire the mike's VCC to 3.3V on the Pico, connect the mike's
   GND to a convenient Pico GND, and then connect mike OUT to A0
*/
#include <stdint.h>
uint8_t  my_byte = 0xf0;
int16_t  trig_pin = 2;
int16_t  echo_pin = 4;
uint32_t duration, cm , blah;
uint64_t big_int;

#include <ADCInput.h>
#define LEDPIN 25
bool led_on = false;

//  ADCInput mike(A0);

 ADCInput mike(A0, A1);        // For stereo/dual mikes, could use this line instead

unsigned long led_time = 100; // 500  ---->>>  1/2 sec on and 1/2 sec off
unsigned long lasttime = 0; // last millis() time we turned the led off or on
unsigned long now = millis();
long speedOfLight_km_s = 300000L;  // see the Integer Constants page for explanation of the 'L'
long long xsixty4; // 64-bit integer
long double ydoub;  // "long" double?

void setup() {
  Serial.begin(2400);
  Serial.println("Baud Rate : 2400");
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);
    
  //mike.begin(8000);
  mike.begin(1000);

 // while (1) {
   
    // For stereo/dual mikes, use this line instead
    //   Serial.printf("%d %d\n", mike.read(), mike.read()); 
 // }
}

void loop() {
  trig_pin++;
  
  //unsigned long
  now = millis();
    if (lasttime - now > led_time) {
        led_on = !led_on;
        digitalWrite(LEDPIN, led_on);
        //last_time = now;
        lasttime = now;
    }
     Serial.printf("%d\n", mike.read());
     Serial.print("Loop : ");
     Serial.write(trig_pin);
     Serial.write(13);     Serial.write(10);
}
