#define S  0
#define B0  31
#define C1  33 //do
#define CS1 35 //do#
#define D1  37 //re
#define DS1 39 //re#
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

#define r 4000  //redonda
#define b 2000  //blanca
#define n 1000  //negra
#define c 500   //corchea
#define s 250   //semicorchea
#define f 125   //fusa
#define g 62    //semifusa

int led = 22;
int speakerOut = 26;

// Melody 1: Star Wars Imperial March

int melody1[] = { A4, S, A4, S, A4, S, F4, S, C5, S, A4, S, F4, S, C5, S, A4, S, E5, S, E5, S, E5, S, F5, S, C5, S, G5, S, F5, S, C5, S, A4, S};
int beats1[] = { 50, 20, 50, 20, 50, 20, 40, 5, 20, 5, 60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5, 60, 10, 40, 5, 20, 5, 60, 40};

int MAX_COUNT = sizeof(melody1) / 2;
void setup() {

pinMode(speakerOut, OUTPUT);

pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {
for (int iTono = 0; iTono < MAX_COUNT; iTono++)
  {
   tone(speakerOut, melody1[iTono]);
   delay(beats1[iTono]*10);
  }
  noTone(speakerOut);
  delay(2000);
}

void tone(byte pin, int freq) {
  ledcSetup(0, 2000, 8); // setup beeper
  ledcAttachPin(pin, 0); // attach beeper
  ledcWriteTone(0, freq); // play tone
}
void noTone(byte pin) {
  tone(pin, 0);
}