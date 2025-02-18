#define SONAR_PIN 4

void setup() {
  Serial.begin(115200);
}

void loop() {
  // อ่านค่าสัญญาณแอนะล็อกจาก ZX-SONAR
  int analogValue = analogRead(SONAR_PIN);

  // คำนวณระยะทาง 12 บิต
  float distance = (analogValue * 100.0) / 4095.0;

  // คำนวณระยะทาง ค่าประมาณ ADC/40
  float approxDistance = analogValue / 40.0;

  // แสดงผล
  Serial.print("ค่า ADC: ");
  Serial.print(analogValue);
  Serial.print(", ระยะทางจากการคำนวณ = ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print(", ระยะทางจากการประมาณค่า = ");
  Serial.print(approxDistance);
  Serial.println("cm");

  delay(3000);
}