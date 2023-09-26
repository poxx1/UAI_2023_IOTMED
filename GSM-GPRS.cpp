#include <SoftwareSerial.h>

// Configuración del módulo GSM
SoftwareSerial gsmSerial(7, 8);  // RX, TX

void setup() {
  // Inicializa la comunicación serial con el módulo GSM
  gsmSerial.begin(9600);
  
  // Inicializa la comunicación serial con el monitor serial
  Serial.begin(9600);
  
  // Espera a que el módulo GSM esté listo
  delay(2000);
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CPIN?");
  delay(1000);
  gsmSerial.println("AT+CREG?");
  delay(1000);
  gsmSerial.println("AT+CGATT?");
  delay(1000);
  gsmSerial.println("AT+CIPSHUT");
  delay(1000);
  gsmSerial.println("AT+CIPMUX=0");
  delay(1000);
  gsmSerial.println("AT+CSTT=\"your_apn_here\",\"username\",\"password\"");
  delay(2000);
  gsmSerial.println("AT+CIICR");
  delay(2000);
  gsmSerial.println("AT+CIFSR");
  delay(1000);
}

void loop() {
  // Envía una solicitud HTTP GET a un servidor
  gsmSerial.println("AT+CIPSTART=\"TCP\",\"example.com\",80");
  delay(2000);
  gsmSerial.println("AT+CIPSEND");
  delay(2000);
  gsmSerial.print("GET /your_api_endpoint HTTP/1.0\r\n");
  gsmSerial.println("Host: example.com");
  gsmSerial.println();
  gsmSerial.write(0x1A);
  delay(5000);  // Espera la respuesta del servidor
  
  // Cierra la conexión
  gsmSerial.println("AT+CIPCLOSE");
  delay(1000);
}