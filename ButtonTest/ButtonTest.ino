#include <Keypad.h>
#include "pitches.h"
#include "melodies.h"

byte buzzer = A4;

const byte ROWS = 4;
const byte COLS = 4;
const byte CELLS = 16;
char keys[ROWS][COLS] = {
    {'1','2','3','4'},
    {'5','6','7','8'},
    {'9','A','B','C'},
    {'D','E','F','G'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int estado[CELLS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int claves[CELLS] = {1,2,4,8,3,6,1,2,7,5,4,6,7,5,8,3}; //{1,2,4,8,3,6,1,2,7,5,4,6,7,5,8,3}

int getSelected() { // 0 = FREE, 1 = SELECTED, 2 = WON
    for(int i = 0; i < CELLS; i++) {
      if(estado[i] == 1) {
        return i; 
      }
    }
    return -1;
}
void checkOver() {
    int g = 0;
    for(int i = 0; i < CELLS; i++) {
      if(estado[i] == 2) {
        g++; 
      }
    }
    if(g == CELLS) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Ganaste");
    }
}

void gameAt(int a) {
    if(estado[a] == 0) {
      sound(a);
      Serial.println(claves[a]);
      if(getSelected() != -1) {
        if(claves[getSelected()] - claves[a] == 0) {
          Serial.println("Par");
          estado[getSelected()] = 2;
          estado[a] = 2;
          digitalWrite(LED_BUILTIN, HIGH);
          delay(1000);                       
          digitalWrite(LED_BUILTIN, LOW);
          checkOver();
        }
        
        else {
          Serial.println("Nope");
          estado[getSelected()] = 0;
        }
      }
      
      else {
        estado[a] = 1;
      }
    }
    
    else {
      Serial.println("Ya ha sido seleccionada");
      return;
    }
}

void sound(int a) {
  switch (claves[a]){
    case 1:
      tone1(buzzer);
      break;
    case 2:
      tone2(buzzer);
      break;
    case 3:
      tone3(buzzer);
      break;
    case 4:
      tone4(buzzer);
      break;
    case 5:
      tone5(buzzer);
      break;
    case 6:
      tone6(buzzer);
      break;
    case 7:
      tone7(buzzer);
      break;
    case 8:
      tone8(buzzer);
      break;
  }
}

void setup(){
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    char key = keypad.getKey();
}

void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        switch (key){
          case '1':
            gameAt(0);
            break;
          case '2':
            gameAt(1);
            break;
          case '3':
            gameAt(2);
            break;
          case '4':
            gameAt(3);
            break;
          case '5':
            gameAt(4);
            break;
          case '6':
            gameAt(5);
            break;
          case '7':
            gameAt(6);
            break;
          case '8':
            gameAt(7);
            break;
          case '9':
            gameAt(8);
            break;
          case 'A':
            gameAt(9);
            break;
          case 'B':
            gameAt(10);
            break;
          case 'C':
            gameAt(11);
            break;
          case 'D':
            gameAt(12);
            break;
          case 'E':
            gameAt(13);
            break;
          case 'F':
            gameAt(14);
            break;
          case 'G':
            gameAt(15);
            break;
        }
        break;
    }
}
