#include <Wire.h>

void setup() {
  Wire.begin();        // Inicializa la comunicación I2C
  Serial.begin(9600);  // Inicializa la comunicación serial
}

void loop() {
  Wire.beginTransmission(0x68); // Dirección del dispositivo I2C (cambia según tu dispositivo)
  Wire.write(0x00);            // Dirección del registro que deseas leer (cambia según tu dispositivo)
  Wire.endTransmission();
  
  Wire.requestFrom(0x68, 1);   // Dirección del dispositivo I2C y cantidad de bytes a leer
  
  if (Wire.available()) {
    int valor = Wire.read();    // Lee el valor del registro
    Serial.print("Valor leído: ");
    Serial.println(valor);
  }
  
  delay(1000);  // Espera 1 segundo antes de realizar la siguiente lectura
}