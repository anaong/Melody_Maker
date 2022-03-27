//Andre Ong
//CPSC-42
//12-5-19
//User types in input for the note, octave, and note value
//Then it play the melody the user typed in

#include "frequencies.h"
#include "functions.h"
#include "keypad.h"

int speaker_pin = 10;
int green_led_1 = 11;
int green_led_2 = 12;
int red_led = 13;

boolean led_state[3] = {LOW, LOW, LOW};//green to red

void setup() {
  pinMode(green_led_1, OUTPUT);
  pinMode(green_led_2, OUTPUT);
  pinMode(red_led, OUTPUT);
  Serial.begin(9600);
}

void loop() { 
  int frequency[250];
  int timing[250];
  
  int input_done = 0;
  int count = 0;
  
  //getting input from user
  while(input_done != 68){//68 = characater D
    change_led_state(led_state, green_led_1);
    int note_input = customKeypad.waitForKey();
    char_to_int(note_input);
    Serial.println(note_input);

    change_led_state(led_state, green_led_1);
    change_led_state(led_state, green_led_2);
    int octave_input = customKeypad.waitForKey();
    char_to_int(octave_input);
    Serial.println(octave_input);

    frequency[count] = piano_frequencies[note_input][octave_input - 1];

    change_led_state(led_state, green_led_1);
    int timing_input = customKeypad.waitForKey();
    char_to_timing(timing_input);
    Serial.println(timing_input);
    
    timing[count] = timing_input;

    count++;

    change_led_state(led_state, red_led);
    input_done = customKeypad.waitForKey();
    Serial.println(input_done);

    turn_off_led(led_state);
  }
  Serial.println("Done");
  Serial.println(count);

  delay(1000);

  change_led_state(led_state, red_led);
  int again = 0;
  //playing the melody
  while(again != 68){
    play_melody(frequency, timing, count);
    again = customKeypad.waitForKey();
    Serial.println(again);
  }
  change_led_state(led_state, red_led);
}
