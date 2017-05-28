#include "pitches.h"

void tone1(byte buzzer) {
  digitalWrite(buzzer, HIGH);
  
  tone(buzzer, 493.88, 1000/3);
  delay(1000/3);
  
  tone(buzzer, 659.25, 1500/3);
  delay(1500/3);
  tone(buzzer, 783.99, 500/3);
  delay(500/3);
  tone(buzzer, 739.99, 1000/3);
  delay(1000/3);
  
  tone(buzzer, 659.25, 2000/3);
  delay(2000/3);
  tone(buzzer, 987.77, 1000/3);
  delay(1000/3);
  
  tone(buzzer, 880.00, 3000/3);
  delay(3000/3);
  
  tone(buzzer, 739.99, 3000/3);
  delay(3000/3);
  
  tone(buzzer, 659.25, 1500/3);
  delay(1500/3);
  tone(buzzer, 783.99, 500/3);
  delay(500/3);
  tone(buzzer, 739.99, 1000/3);
  delay(1000/3);
  
  tone(buzzer, 622.25, 2000/3);
  delay(2000/3);
  tone(buzzer, 698.46, 1000/3);
  delay(1000/3);
  
  tone(buzzer, 493.88, 5000/3);
  delay(5000/3);
}

void playTone(int tone, int duration, byte buzzer) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
      digitalWrite(buzzer, HIGH);
      delayMicroseconds(tone);
      digitalWrite(buzzer, LOW);
      delayMicroseconds(tone);
    }
}
void playNote(char note, int duration, byte buzzer) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
      if (names[i] == note) {
        playTone(tones[i], duration-200, buzzer);
      }
    }
}
void tone2(byte buzzer) {
  digitalWrite(buzzer, HIGH);
  
  int length = 26;
  char notes[] = "eeeeeeegcde fffffeeeeddedg";
  int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

  int tempo = 300;
  
  for (int i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo ); // rest
      } else {
          playNote(notes[i], beats[i] * tempo, buzzer);
        }
    
    // pause between notes
    delay(tempo / 2); 
   }
}

void tone3(byte buzzer) {
  digitalWrite(buzzer, HIGH);
          
  tone(buzzer, NOTE_D5, 100);
  delay(80);
  tone(buzzer, NOTE_F5, 100); 
  delay(80);
  tone(buzzer, NOTE_D6, 200); 
  delay(250);
  
  tone(buzzer, NOTE_D5, 100); 
  delay(80);
  tone(buzzer, NOTE_F5, 100); 
  delay(80);
  tone(buzzer, NOTE_D6, 200);
  delay(250);
  
  tone(buzzer, NOTE_E6, 200); 
  delay(200);
  tone(buzzer, NOTE_F6, 100); 
  delay(100);
  tone(buzzer, NOTE_E6, 100); 
  delay(80);
  tone(buzzer, NOTE_F6, 100); 
  delay(80);
  tone(buzzer, NOTE_E6, 100); 
  delay(80);
  tone(buzzer, NOTE_C6, 100); 
  delay(80);
  tone(buzzer, NOTE_A5, 100); 
  delay(300);
  
  tone(buzzer, NOTE_A5, 200); 
  delay(100);
  tone(buzzer, NOTE_D5, 200); 
  delay(100);
  tone(buzzer, NOTE_F5, 100); 
  delay(100);
  tone(buzzer, NOTE_G5, 100); 
  delay(100);
  tone(buzzer, NOTE_A5, 100); 
  delay(500);
  
  tone(buzzer, NOTE_A5, 200); 
  delay(100);
  tone(buzzer, NOTE_D5, 200); 
  delay(100);
  tone(buzzer, NOTE_F5, 100); 
  delay(100);
  tone(buzzer, NOTE_G5, 100); 
  delay(100);
  tone(buzzer, NOTE_E5, 100); 
  delay(500);
}

void tone4(byte buzzer) {
  digitalWrite(buzzer, HIGH);
  
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void tone5(byte buzzer) {
  digitalWrite(buzzer, HIGH);
  
  tone(buzzer, 988, 250);
  delay(1000);
  tone(buzzer, 988, 250);
  delay(400);
  tone(buzzer, 880, 250);
  delay(400);
  tone(buzzer, 988, 250);
  delay(1000);
  
  tone(buzzer, 988, 250);
  delay(400);
  tone(buzzer, 880, 250);
  delay(400);
  tone(buzzer, 988, 250);
  delay(1000);
  
  tone(buzzer, 988, 250);
  delay(400);
  tone(buzzer, 880, 250);
  delay(400);
  tone(buzzer, 784, 1000);
  delay(1000);
  tone(buzzer, 880, 1000);
  delay(1000);
}

void tone6(byte buzzer) {
    digitalWrite(buzzer, HIGH);
    
    for(int i=0; i<4; i++) {
    tone(buzzer, NOTE_G4);
    delay(500);
    noTone(buzzer);
    tone(buzzer, NOTE_C4);
    delay(500);
    noTone(buzzer);
    tone(buzzer, NOTE_DS4);
    delay(250);
    noTone(buzzer);
    tone(buzzer, NOTE_F4);
    delay(250);
    noTone(buzzer);
    }
}

void tone7(byte buzzer){
  digitalWrite(buzzer, HIGH);
  
  int melody[] = {
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4
};

int noteDurations[] = {
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8
};

int pace = 1450;

  for (int Note = 0; Note <32; Note++) {//counter of Notes (54 limit the array)
    int duration = pace/noteDurations[Note];//Adjust duration with the pace of music
    tone(buzzer, melody[Note],duration); //Play note

    // to distinguish the notes, set a minimum time between them.
    delay(duration*1.2);
  }
}

void tone8(byte buzzer) {
    digitalWrite(buzzer, HIGH);
    
    tone(buzzer,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(buzzer,LA3,Q);
    delay(1+Q);
    tone(buzzer,LA3,Q);
    delay(1+Q);
    tone(buzzer,F3,E+S);
    delay(1+E+S);
    tone(buzzer,C4,S);
    delay(1+S);
    
    tone(buzzer,LA3,Q);
    delay(1+Q);
    tone(buzzer,F3,E+S);
    delay(1+E+S);
    tone(buzzer,C4,S);
    delay(1+S);
    tone(buzzer,LA3,H);
    delay(1+H);
    
    tone(buzzer,E4,Q); 
    delay(1+Q); 
    tone(buzzer,E4,Q);
    delay(1+Q);
    tone(buzzer,E4,Q);
    delay(1+Q);
    tone(buzzer,F4,E+S);
    delay(1+E+S);
    tone(buzzer,C4,S);
    delay(1+S);
    
    tone(buzzer,Ab3,Q);
    delay(1+Q);
    tone(buzzer,F3,E+S);
    delay(1+E+S);
    tone(buzzer,C4,S);
    delay(1+S);
    tone(buzzer,LA3,H);
    delay(1+H);
}

