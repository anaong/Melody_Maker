#pragma once

void change_led_state(boolean (&led_state)[3], int led_pin){
  led_state[led_pin - 11] = !led_state[led_pin - 11];
  digitalWrite(led_pin, led_state[led_pin - 11]);
}

void turn_off_led(boolean (&led_state)[3]){
  for(int i = 0; i < 3; i++){
    if(led_state[i]){
      led_state[i] = LOW;
      digitalWrite(i + 11, led_state[i]);
    }
  }
}

void char_to_int (int &input){
  switch (input){
    case 48:
      input = 0;
      break;
    case 49:
      input = 1;
      break;
    case 50:
      input = 2;
      break;
    case 51:
      input = 3;
      break;
    case 52:
      input = 4;
      break;
    case 53:
      input = 5;
      break;
    case 54:
      input = 6;
      break;
    case 55:
      input = 7;
      break;
    case 56:
      input = 8;
      break;
    case 57:
      input = 9;
      break;
    case 65://A
      input = 10;
      break;
    case 66://B
      input = 11;
      break;
    case 67://C
      input = 12;
      break;
  }
}

void char_to_timing(int &input){
  switch (input){
    case 49://1
      input = 1;//whole
      break;
    case 50://2
      input = 2;//half
      break;
    case 51://3
      input = 4;//quarter
      break;
    case 52://4
      input = 8;//eigth
      break;
    case 53://5
      input = 16;//sixteenth
      break;
    case 54://6
      input = 48;//dottted whole
      break;
    case 55://7
      input = 24;//dotted half
      break;
    case 56://8
      input = 12;//dotted quarter
      break;
    case 57://9
      input = 6;//dotted eigth
      break;
    case 48://0
      input = 3;//dotted sixteenth
      break;
  }
}

//function from: https://circuitdigest.com/microcontroller-projects/playing-melodies-on-piezo-buzzer-using-arduino-tone-function
//in the Play_Pirates() function
//Calculating the timing explanation: https://github.com/nseidle/AxelF_DoorBell/wiki/How-to-convert-sheet-music-into-an-Arduino-Sketch
void play_melody(int frequency[], int timing[], int count){
  for (int i = 0; i < count; i++) {
    int note_duration = 1200 / timing[i];//increase constant = longer note
    tone(10, frequency[i], note_duration);

    int pauseBetweenNotes = note_duration * 1.3;//increase constant = slower tempo
    delay(pauseBetweenNotes);
    noTone(10);
   }
}
