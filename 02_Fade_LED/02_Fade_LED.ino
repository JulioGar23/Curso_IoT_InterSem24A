// Fade New_Version 
// Code by: Julio A. García-Rodríguez.
// 19/06/2024 - Program for IIOT

int led = 2;
int brillo = 1;
int incremento = 2;

void setup() {
  ledcAttach(led, 4000, 8);    // ledcAttach es un nuevo comando, desde 2024.
                                // Esta función es usada para configurar LEDC con una frecuencia y resolución dada. 
                                // El canal para LEDC será seleccionado automáticamente. 
                                // Sintaxis: bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);
                                //           "pin" select LEDC pin.
                                //           "freq" select frequency of pwm.
                                //           "resolution" select resolution for LEDC channel. Range is 1-14 bits (1-20 bits for some new versions of ESP32).
  // ledcAttach(0, 4000, 8);    // 4 kHz PWM, 8-bit resolution.
}

void loop() 
{
  ledcWrite(led, brillo);
  brillo = brillo + incremento;
  if (brillo <= 0 || brillo >= 255)      // if you have selected 8 bits resolution, change 3 to 2^8 = 256
  {  
    incremento = -incremento;
  }
  delay(20);
}