#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // ที่อยู่ของ I2C คือ 0x3C (แก้ไขจาก 0x30)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // หยุดการทำงานถ้าจอไม่ตอบสนอง
  }

  display.clearDisplay();
  display.setTextSize(1.7);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(30, 0);
  display.println(F("GroupMember"));
  display.setCursor(30, 20);
  display.println(F("65122250008"));
  display.setCursor(30, 40);
  display.println(F("65122250014")); // รหัสนักศึกษา
  display.display();
}

void loop() {
  // เพิ่มโค้ดที่ต้องการให้ทำงานวนซ้ำ
  // เช่น การแสดงผลข้อมูล หรือการรับค่าจาก Sensor
}