
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "Peticion.h"

Peticion p("192.168.0.22:8000/");
void setup() {
  Serial.begin(9600);
  
  WiFi.softAP("Paul Music", "paul12345"); // Nombre de punto de acceso Nuestro
  WiFi.begin("Guzman", "guzman321");// conexion dinamica
  // put your main code here, to run repeatedly:
    Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  if(Serial.available()==true){
      String r= Serial.readStringUntil('\n');
      
      if(r=="a"){// para pausar o reproducir la musica
        p.peticionGet("play");
      }else if(r=="b"){
        p.peticionGet("previous");// para regresar la cancion
      }else if(r=="c"){// para la siguiente cancion
        p.peticionGet("next");
      }
      
  }

}
