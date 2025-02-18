int adcPin = 36; // กำหนดหมายเลขขาที่จะอ่าน ADC

void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(adcPin);

  // แปลงค่า ADC เป็นแรงดันไฟฟ้า
  float voltage = (value / 4095.0) * 3.3;

  Serial.print("ADC value: ");
  Serial.print(value);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(1000); // 1 วินาที
}