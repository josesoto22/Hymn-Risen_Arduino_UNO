#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define REST     0

const int buzzer = 11;

const int tempo = 120;

const int msPerBeat = 60000 / tempo;

int melody[] = {
  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_E4, 100,  NOTE_E4, 100,  NOTE_D4,  33,
  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_C4, 100,  NOTE_B3,  50,  NOTE_C4,  50,
  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_B3,  33,  NOTE_F4,  34,  NOTE_E4,  33,
  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_E4, 100,  NOTE_E4, 100,  NOTE_D4,  33,
  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_C4, 100,  NOTE_B3,  50,  NOTE_C4,  50,
  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_B3,  33,  NOTE_F4,  34,  NOTE_E4,  33,
  NOTE_C4,  50,  NOTE_B3,  50,  NOTE_C4, 100,  NOTE_D4, 100,  NOTE_G3,  50,
  NOTE_G3,  50,  NOTE_D4,  33,  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_D4,  33,
  NOTE_C4,  34,  NOTE_F4,  33,  NOTE_A3,  33,  NOTE_C4,  34,  NOTE_B3,  33,
  NOTE_E4, 100,  NOTE_C4,  50,  NOTE_B3,  50,  NOTE_C4, 100,  NOTE_D4, 100,
  NOTE_G3,  50,  NOTE_G3,  50,  NOTE_D4,  33,  NOTE_D4,  34,  NOTE_E4,  33,
  NOTE_D4,  33,  NOTE_C4,  34,  NOTE_F4,  33,  NOTE_A3,  33,  NOTE_C4,  34,
  NOTE_B3,  33,  NOTE_E4, 100,  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_E4, 100,
  NOTE_E4, 100,  NOTE_D4,  33,  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_C4, 100, 
  NOTE_B3,  50,  NOTE_C4,  50,  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_B3,  33, 
  NOTE_F4,  34,  NOTE_E4,  33,  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_E4, 100,  
  NOTE_E4, 100,  NOTE_D4,  33,  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_C4, 100,
  NOTE_B3,  50,  NOTE_C4,  50,  NOTE_C4,  50,  NOTE_D4,  50,  NOTE_B3,  33,
  NOTE_F4,  34,  NOTE_E4,  33,  NOTE_C4,  50,  NOTE_B3,  50,  NOTE_C4, 100,
  NOTE_D4, 100,  NOTE_G3,  50,  NOTE_G3,  50,  NOTE_D4,  33,  NOTE_D4,  34,
  NOTE_E4,  33,  NOTE_D4,  33,  NOTE_C4,  34,  NOTE_F4,  33,  NOTE_A3,  33,
  NOTE_C4,  34,  NOTE_B3,  33,  NOTE_E4, 100,  NOTE_C4,  50,  NOTE_B3,  50,
  NOTE_C4, 100,  NOTE_D4, 100,  NOTE_G3,  50,  NOTE_G3,  50,  NOTE_D4,  33,
  NOTE_D4,  34,  NOTE_E4,  33,  NOTE_D4,  33,  NOTE_C4,  34,  NOTE_F4,  33,
  NOTE_A3,  33,  NOTE_C4,  34,  NOTE_B3,  33,  NOTE_E4, 100
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

void playSong() {
  for (int i = 0; i < notes * 2; i = i + 2) {
    int pitch = melody[i];
    int durationMs = (melody[i + 1] * msPerBeat) / 100;

    tone(buzzer, pitch, durationMs * 0.9);

    delay(durationMs);

    noTone(buzzer);
  }
}

void setup() {

  pinMode(buzzer, OUTPUT);

  playSong();
}

void loop() {
}