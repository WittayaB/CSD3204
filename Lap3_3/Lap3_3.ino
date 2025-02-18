// กำหนดขา GPIO
#define BUTTON_PIN 19  // ปุ่มต่อที่ขา 0
#define LED_PIN1 23    // LED ต่อที่ขา 18
#define LED_PIN 18

// ตัวแปรสำหรับเก็บสถานะ
int counter = 0;   // ตัวนับจำนวนครั้งที่ปุ่มถูกกด
int cur_value = 1; // สถานะปัจจุบันของปุ่ม
int past_value = 1; // สถานะก่อนหน้า

void setup() {
    // ตั้งค่าขา GPIO
    pinMode(BUTTON_PIN, INPUT);  // ตั้งค่าขาเป็น INPUT
    pinMode(LED_PIN, OUTPUT);    // ตั้งค่าขา LED เป็น OUTPUT
    pinMode(LED_PIN1, OUTPUT);
    // ปิด LED เริ่มต้น
        digitalWrite(LED_PIN1, LOW);
            digitalWrite(LED_PIN, LOW);


    // เริ่ม Serial Monitor
    Serial.begin(115200);
}

void loop() {
    // อ่านสถานะปัจจุบันของปุ่ม
    cur_value = digitalRead(BUTTON_PIN);
    int sw1State = digitalRead(BUTTON_PIN);

    if (sw1State == LOW) {  // LOW แปลว่าปุ่มถูกกด
        pinMode(BUTTON_PIN, INPUT); // ปิด LED

        Serial.println("SW1 is Pressed!"); // แสดงข้อความบน Serial Monitor
    } else {
        Serial.println("SW1 is not Pressed!"); // แ
    }
    // ตรวจสอบถ้าปุ่มถูกกด (cur_value == 0) และสถานะก่อนหน้าคือ 1
    if (cur_value == LOW && past_value == HIGH) {
        // เพิ่มตัวนับ
        counter++;

        // พิมพ์ค่าจำนวนครั้งที่กดปุ่มบน Serial Monitor
        Serial.print("Counter = ");
        Serial.println(counter);

        // สลับสถานะของ LED
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        digitalWrite(LED_PIN1, !digitalRead(LED_PIN1));
    }

    // บันทึกสถานะปัจจุบันไปยัง past_value
    past_value = cur_value;

    // หน่วงเวลาดีเลย์เพื่อลดผลกระทบของสัญญาณเด้ง (debouncing)
    delay(50);
}
