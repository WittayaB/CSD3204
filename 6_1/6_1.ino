#define BLYNK_TEMPLATE_ID "TMPL6Ir1MJobl" // ขึ้นอยู่กับของแต่ละคน
#define BLYNK_TEMPLATE_NAME "controlLED" // ขึ้นอยู่กับของแต่ละคน
#define BLYNK_AUTH_TOKEN "" // ขึ้นอยู่กับของแต่ละคน

// Library ของ Blynk
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Wi-Fi Credentials
char ssid[] = "nut"; // ชื่อ Wi-Fi
char pass[] = "nattapon_nut"; // รหัสผ่าน Wi-Fi

// กำหนดพิน LED
#define LED_PIN 19

void setup() {
  // เริ่มต้น Serial Monitor
  Serial.begin(115200);

  // กำหนดให้พิน LED เป็น Output
  pinMode(LED_PIN, OUTPUT);

  // เริ่มต้นการเชื่อมต่อ Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connecting to Blynk...");
}

void loop() {
  // Blynk Run
  Blynk.run();
}

// ฟังก์ชันควบคุม LED ผ่าน Virtual Pin V0
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // รับค่าจากแอป (0 = OFF, 1 = ON)
  digitalWrite(LED_PIN, pinValue); // ควบคุมพิน LED
}