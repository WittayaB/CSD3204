// lab4_3.ino
// กำหนดความถี่ของโน้ตดนตรี
#define DO 523
#define RE 587
#define ME 659
#define FA 698
#define SO 783
#define RA 880
#define TE 987

// กำหนดขา buzzer
const int buzzerPin = 25;

// กำหนดเวลา 1000 = 1 วินาที
const int t = 1000;

void setup() {
  // ตั้งค่า pinMode เป็น OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // โน้ตดนตรี
  tone(buzzerPin, DO); delay(t);
  tone(buzzerPin, RE); delay(t);
  tone(buzzerPin, ME); delay(t);
  tone(buzzerPin, FA); delay(t);
  tone(buzzerPin, SO); delay(t);
  tone(buzzerPin, TE); delay(t);

  // ปิดเสียง
  noTone(buzzerPin); delay(5*t);
}