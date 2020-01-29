#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7
#define BUTTON_PIN 8
#define COUNT_OF_MODES 2 
boolean buttonWasUp = false;
byte numberSegments[10] = {
 0b00111111, 0b00001010, 0b01011101, 0b01011101, 0b01101010,
 0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110,
};

int currentMode = 1; 

void setup() {
for (int i = 0; i < SEGMENT_COUNT; ++i)
{
pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}
pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
boolean buttonIsUp = digitalRead(BUTTON_PIN);
if (buttonWasUp && !buttonIsUp){
  currentMode = currentMode % COUNT_OF_MODES;
}

int mask = numberSegments[currentMode];
for (int i = 0; i < SEGMENT_COUNT; ++i) { 
boolean enableSegment  =  bitRead(mask, i);
digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
}
}
