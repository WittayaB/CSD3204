#define LED_PIN 19

void setup() {
    Serial.begin(115200);

    // ตั้งค่า PWM เป็น OUTPUT
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    for (int D = 22; D <= 255; D++) {
        // D duty cycle
        analogWrite(LED_PIN, D);
        Serial.print("Current PWM Duty Cycle: ");
        Serial.println(D);
        delay(1000);
    }
}
