#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // กำหนดความกว้างของจอแสดงผล OLED
#define SCREEN_HEIGHT 64 // กำหนดความสูงของจอแสดงผล OLED
#define OLED_RESET -1 // กำหนดขา RESET ของจอแสดงผล OLED (หรือ -1 ถ้าไม่ได้ใช้)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int adcPin = 34; // กำหนดหมายเลขขาที่จะอ่านค่า ADC

void setup() {
  Serial.begin(115200);

  // กำหนด Address I2C ที่ 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // หยุดการทำงานถ้าจอแสดงผล OLED ไม่ตอบสนอง
  }

  display.clearDisplay(); // ล้างจอแสดงผล OLED
  display.setTextSize(1); // กำหนดขนาดตัวอักษร
  display.setTextColor(SSD1306_WHITE); // กำหนดสีตัวอักษร
  display.setCursor(0, 0); // กำหนดตำแหน่งเริ่มต้นของเคอร์เซอร์
  display.println(F("Reading ADC...")); // พิมพ์ข้อความ "Reading ADC..."
  display.display(); // แสดงผลข้อความบนจอแสดงผล OLED
}


void loop() {
  int value = analogRead(adcPin);

  // แปลงค่า ADC เป็นแรงดันไฟฟ้า
  float voltage = (value / 4095.0) * 3.3;

  // แสดงข้อมูลบน Serial Monitor
  Serial.print("ADC value: ");
  Serial.print(value);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // แสดงผลบน OLED
  display.clearDisplay(); // ล้างหน้าจอ
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("ADC Reading: "));
  display.setCursor(0, 20);
  display.println(F("Value: "));
  display.setCursor(0, 40);
  display.print(F("Voltage: "));
  display.print(voltage, 2); // แสดงทศนิยม 2 ตำแหน่ง
  display.println(F(" V"));
  display.display(); // แสดงผลบนจอ OLED

  delay(1000); // หน่วงเวลา 1 วินาที
}