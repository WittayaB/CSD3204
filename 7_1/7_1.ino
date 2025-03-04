#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// กำหนดค่า WIFI
const char* ssid = "CSD3204";
const char* password = "csd3204y25";

// กำหนดค่า MQTT Broker
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_password = "";

// กำหนดพินสำหรับ sensor DHT11 และ LED
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 19;

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
const long interval = 5000; // ส่งข้อมูลทุก 5 วินาที

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("กำลังเชื่อมต่อกับ WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("เชื่อมต่อ WiFi สำเร็จแล้ว");
  Serial.print("ที่อยู่ IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("ข้อความที่เข้ามา [");
  Serial.print(topic);
  Serial.print("]: ");

  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (String(topic) == "2024/led/G14") {
    if (message == "เปิด") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED เปิดแล้ว");
      
    } else if (message == "ปิด") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED ปิดแล้ว");
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("กำลังพยายามเชื่อมต่อกับ MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_user, mqtt_password)) {
      Serial.println("เชื่อมต่อกับ MQTT สำเร็จแล้ว");
      client.subscribe("2024/led/G14");
    } else {
      Serial.print("ไม่สามารถเชื่อมต่อ, รหัสข้อผิดพลาด - ");
      Serial.print(client.state());
      Serial.println(" - ลองใหม่ใน 5 วินาที");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(115200);

  setup_wifi();
  dht.begin();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > interval) {
    lastMsg = now;

    float temperature = dht.readTemperature();
    if (isnan(temperature)) {
      Serial.println("ไม่สามารถอ่านค่าอุณหภูมิจาก DHT11");
      return;
    }

    String tempStr = String(temperature, 2);
    Serial.print("อุณหภูมิ: ");
    Serial.print(tempStr);
    Serial.println(" °C");

    client.publish("IOT/temperature/G14", tempStr.c_str());
  }
}