// กำหนดขา GPIO
#define SW1_PIN 0  // กำหนดปุ่ม SW1 ที่ขา 0
#define LED_PIN 18 // กำหนด LED ที่ขา 18

void setup() {
    // ตั้งค่า Serial Monitor เพื่อแสดงข้อมูล
    Serial.begin(115200);

    // ตั้งค่าขา SW1 เป็น INPUT (อินพุตแบบต่อลง เนื่องจาก ZX-SWITCH01 มีพูลอัปในตัว)
    pinMode(SW1_PIN, INPUT);

    // ตั้งค่าขา LED เป็น OUTPUT
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // อ่านค่าจาก SW1
    int sw1State = digitalRead(SW1_PIN);

    // ตรวจสอบสถานะของปุ่ม
    if (sw1State == LOW) {  // LOW แปลว่าปุ่มถูกกด
        digitalWrite(LED_PIN, HIGH); // เปิด LED
        Serial.println("SW1 is Pressed!"); // แสดงข้อความบน Serial Monitor
    } else {
        digitalWrite(LED_PIN, LOW); // ปิด LED
        Serial.println("SW1 is not Pressed!"); // แ
    }
// เพิ่มดีเลย์เล็กน้อยเพื่อลดการกระพริบ
delay(100);
}