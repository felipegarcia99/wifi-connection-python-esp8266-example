#include <ESP8266WiFi.h>

const char *ssid = "";
const char *password = "";

IPAddress server(192,168,0,198);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  conectar_wifi();
  print_conexao_wifi();
  conectar_server();
}

void loop() {
  enviar("Hi");
  String answer = receber();
  
  Serial.println("from server: " + answer);
  client.flush();
}

void enviar(String dado){
  client.println(dado + "\r");
}

String receber(){
  String answer = client.readStringUntil('\r');
  return answer;
}

void conectar_wifi(){
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}

void print_conexao_wifi(){
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void conectar_server(){
  client.connect(server, 8080);   // Connection to the server
}
