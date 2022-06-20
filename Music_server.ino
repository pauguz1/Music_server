
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void setup() {
  Serial.begin(9600);
  
  WiFi.softAP(ssid, password); // Nombre de punto de acceso Nuestro
  WiFi.begin(nombreRed, passwordRed);// conexion dinamica
  // put your main code here, to run repeatedly:
    Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    for (int a = 0; a < 400; a++) {
      S.escucharServer();
    }
  }
  Serial.println();
  Serial.print("Conectado: ");
  Serial.println(WiFi.localIP());

}

void loop() {


}
