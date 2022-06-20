

/**
 * Para realizar peticiones http mas facilmente
 * Author: Paul Santana 
 * Version: 1.0
 */
class Peticion{
    private:
    WiFiClient client;// cliente
    HTTPClient http;// para las peticiones http
    String host;
    public:
    String peticionGet(String info);
    void setHost(String info);
    Peticion(String info);
  };

  Peticion::Peticion(String info){
      host=info;
  }

/**
 * Para realizar la peticion http Get
 */
  String Peticion::peticionGet(String info){
    http.begin(client, host+info);
    int code = http.GET();
    //Serial.print("peticion a:"+host+info);
    if (code >= 200 && code <=299) {//si la peticion fue exitosa entonces
      Serial.println("codigo:"+(String)code);
      Serial.print("mensaje peticion get:");
      Serial.println(http.getString());
      return http.getString();
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(code).c_str());
      return "";
    }
  }
  
/**
 * Para cambiar el nombre del host
 */
 void Peticion::setHost(String info){
    host = info;
  }


  
