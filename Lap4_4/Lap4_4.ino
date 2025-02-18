// lab4_4.ino
const int buzzerPin = 25;
const int songLength = 12; // มี 12 โน้ต

char notes[] = { 'd', 'd', 'r', 'd', 'f', 'm',
                 'd', 'd', 'r', 'd', 's', 'f',
                 'd', 'd', 'd', 'r',
                 'f',  'm' ,'m', 'r',
                 'd','d','r','f','r','s',
                 'd','d','r','d','f','m',}; // โน้ตตามที่ต้องการ
int beats[] = { 2, 2, 2, 2, 2, 3, 
                2, 2, 2, 2, 2, 3,
                2, 2, 2,2,
                2,2,2,2,
                2,2,2,3,2,2,2,
                2,2,2,2,3,2, }; // ความยาวของแต่ละโน้ต
int tempo = 260; // ตั้งค่า tempo ให้เหมาะสม

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < songLength; i++) {
    int duration = beats[i] * tempo;
    if (notes[i] == ' ') {
      delay(duration);
    } else {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration + 50); // หน่วงเวลาระหว่างโน้ต
    }
  }
  delay(1000); // หน่วงเวลา 1 วินาทีก่อนเริ่มใหม่
}

int frequency(char note) {
  switch (note) {
    case 'd': return 262; // DO
    case 'r': return 294; // RE
    case 'm': return 330; // MI
    case 'f': return 349; // FA
    case 's': return 392; // SO
    default: return 0;
  }
}
