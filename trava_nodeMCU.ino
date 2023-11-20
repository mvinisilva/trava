//Inclusão de bibliotecas necessárias
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Variaveis de conexão wifi
const char* ssid = "insira o nome do seu wifi";
const char* password = "insira a senha do seu wifi";

// MQTT Broker utilizado
const char* BROKER_MQTT_SERVER = "mqtt.eclipse.org";
int BROKER_MQTT_PORT = 1883;

// Configuração MQTT
const String HOSTNAME  = "iLocker - insira um nome para o device (deve ser único)";
const char * MQTT_STATE_TOPIC = "displayLockerInfo"; //Topico onde o Device publica.

//LEDs
#define R_LED D3
#define G_LED D2

//Buzzer
#define BUZZER D4

// Cria instância wifi e client
WiFiClient espClient;
PubSubClient client(BROKER_MQTT_SERVER, BROKER_MQTT_PORT, espClient);

void connectWifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando em: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}
\
// Verifica conexão ao client MQTT
bool checkMqttConnection() {
  if (!client.connected()) {
    if (client.connect(HOSTNAME.c_str())) {
      Serial.println("Conectado ao Broker MQTT " + String(BROKER_MQTT_PORT));
      //SUBSCRIÇÃO DE TOPICOS
      client.publish("validateLocker", "hello world");
    }
  }
  return client.connected();
}


void setup() {
  Serial.begin(9600);
  connectWifi();
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (checkMqttConnection()) {
      client.loop();
    }
  }

  if (Serial.available() > 0) {
    data = Serial.read();
    delay(1000);
    Serial.println(data);
    if (data == '1') {
      digitalWrite(G_LED, HIGH);
      delay(2000);
      digitalWrite(G_LED, LOW);
      client.publish(MQTT_STATE_TOPIC, "Acessado por: Leonardo");
      client.publish(MQTT_STATE_TOPIC, "Acesso liberado");
    } else {
      digitalWrite(R_LED, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(2000);
      digitalWrite(BUZZER, LOW);
      digitalWrite(R_LED, LOW);
      client.publish(MQTT_STATE_TOPIC, "Acessado por: Desconhecido");
      client.publish(MQTT_STATE_TOPIC, "Acesso negado");
    }
  }
}
