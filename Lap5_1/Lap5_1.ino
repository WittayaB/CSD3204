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
  float Vout = (value / 4095.0) * 3.3; // หน่วย V
  float temperature = (Vout - 0.4) / 0.0195; // หน่วย Celsius

  // แสดงข้อมูลบน serial monitor
  Serial.print("ADC value: ");
  Serial.print(value);
  Serial.print(", Voltage: ");
  Serial.print(Vout);
  Serial.print(" V, Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // แสดงผลบน OLED
  display.clearDisplay(); // ล้างหน้าจอ
  // ... (ส่วนของการแสดงผลบน OLED จะต้องเพิ่มโค้ดในส่วนนี้)
// แสดงผลบน OLED
display.clearDisplay(); // ล้างหน้าจอ
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

display.setCursor(0, 0);
display.println(F("Temperature Sensor: "));

display.setCursor(0, 20);
display.print(F("ADC Value: "));
display.print(value);

display.setCursor(0, 40);
display.print(F("Temp: "));
display.print(temperature, 2); // ทศนิยม 2 ตำแหน่ง

// print.print((char)247) = display ° on OLED
display.print((char)247);
display.print(F(" C"));

display.display();
delay(1000);



}