// Code by: Julio A. García-Rodríguez.
// Enigma Code for: Month 06, Day 23.

int test_led = 2;  

void setup() {
  pinMode(test_led, OUTPUT);     // Configure the pin as an output.
  digitalWrite(test_led, LOW);   // Initially, turn the LED off.
}

void loop() {
  // Repeat the basic pattern three times
  repeatBlink(3, 200, 150);
  delay(2000); // Pause for 2 seconds

  // Longer sequence
  blink(6000); // On for 6 seconds
  blink(2000); // On for 2 seconds
  blink(3000); // On for 3 seconds

  // Repeat the basic pattern again
  repeatBlink(3, 200, 150);
  delay(2000); // Pause for 2 seconds
}

void blink(int duration) {
  digitalWrite(test_led, HIGH);
  delay(duration);
  digitalWrite(test_led, LOW);
  delay(duration);
}

void repeatBlink(int count, int onTime, int offTime) {
  for(int i = 0; i < count; i++) {
    digitalWrite(test_led, HIGH);
    delay(onTime);
    digitalWrite(test_led, LOW);
    delay(offTime);
  }
}
