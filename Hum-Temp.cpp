#include <DHT.h>

#define DHTPIN 2     // Define el pin al que está conectado el sensor DHT22
#define DHTTYPE DHT22   // Define el tipo de sensor (DHT22 en este caso)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  
  dht.begin();         // Inicializa el sensor DHT
}

void loop() {
  // Lee la temperatura en grados Celsius
  float temperatura = dht.readTemperature();
  
  // Lee la humedad relativa
  float humedad = dht.readHumidity();
  
  // Verifica si la lectura del sensor fue exitosa
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT!");
    return;
  }
  
  // Muestra la temperatura y la humedad en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");
  
  delay(2000);  // Espera 2 segundos antes de realizar la siguiente lectura
}
