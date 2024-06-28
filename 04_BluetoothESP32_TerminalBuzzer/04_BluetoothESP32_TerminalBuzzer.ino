#include "BluetoothSerial.h"

String device_name = "ESP32-ITCG-JAGR";  // Nombre del dispositivo.

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

int buzzer = 2;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name); 
  pinMode(buzzer, OUTPUT); 
  Serial.printf("El dispositivo con nombre \"%s\" está listo.\nAhora puedes emparejarlo con tu Bluetooth!\n", device_name.c_str());
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    char dato = SerialBT.read();
    Serial.write(dato);
    
    if (dato == '1') {
      digitalWrite(buzzer, HIGH);
      Serial.println("\nBuzzer ACTIVADO"); 
      delay(2000);
      digitalWrite(buzzer, LOW);
      Serial.println("\nBuzzer APAGADO");
    } else if (dato == '0') {
      Serial.println("\nALARMA!!!");
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }
  }
  delay(20);
}