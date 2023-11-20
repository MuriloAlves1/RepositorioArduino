#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Defina o nome da rede Wi-Fi e a senha
const char* ssid = "NomeDaSuaRedeWiFi";
const char* password = "SenhaDaSuaRedeWiFi";

// Defina as informações do servidor MQTT
const char* mqtt_server = "endereço_do_broker_MQTT";
const int mqtt_port = 1883;
const char* mqtt_user = "seu_usuario_MQTT";
const char* mqtt_password = "sua_senha_MQTT";

// Defina o tópico MQTT para controlar o LED
const char* mqtt_topic = "casa/arduino/led";

// Pino do LED
const int ledPin = D1; // Use o pino que desejar

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // Conecte-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede Wi-Fi...");
  }
  Serial.println("Conectado à rede Wi-Fi");

  // Conecte-se ao servidor MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Verifique se o tópico corresponde ao tópico MQTT de controle do LED
  if (String(topic) == mqtt_topic) {
    if (payload[0] == '1') {
      digitalWrite(ledPin, HIGH); // Ligue o LED
    } else {
      digitalWrite(ledPin, LOW); // Desligue o LED
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Conectando ao servidor MQTT...");
    if (client.connect("ArduinoClient", mqtt_user, mqtt_password)) {
      Serial.println("Conectado ao servidor MQTT");
      // Assine o tópico MQTT
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("Falha na conexão ao servidor MQTT. Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
