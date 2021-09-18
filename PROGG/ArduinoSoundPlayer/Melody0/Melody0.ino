/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * Пример использования пьезоизлучателя для проигрывания 
 * мелодии.  
 * Для этого на пьезоизлучатель подаётся сигнал 
 * соответствующей частоты.
 *
 *   Расчет тонов производится следующим образом:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * таблица различных тонов:
 *
 * нота      частота     период timeHigh
 * c          261 Hz          3830  1915  
 * d          294 Hz          3400  1700  
 * e          329 Hz          3038  1519  
 * f          349 Hz          2864  1432  
 * g          392 Hz          2550  1275  
 * a          440 Hz          2272  1136  
 * b          493 Hz          2028  1014  
 * C          523 Hz          1912  956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */
  
int speakerPin = 9;

int length = 15;                  // число нот
char notes[] = "ccggaagffeeddc "; // пробел - пауза
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // проиграть тон, соответствующий ноте
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // пауза
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // пауза между нотами
    delay(tempo / 2); 
  }
} 
