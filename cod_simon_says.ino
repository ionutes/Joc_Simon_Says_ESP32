const byte ledPins[] = {16, 18, 17, 19}; // LED pins
const byte buttonPins[] = {21, 23, 26, 27}; // Button pins

#define MAX_GAME_LENGTH 100
byte gameSequence[MAX_GAME_LENGTH] = {0};
byte gameIndex = 0;

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  randomSeed(analogRead(A0));
}
void lightLed(byte ledIndex) {
  digitalWrite(ledPins[ledIndex], HIGH);
  delay(300);
  digitalWrite(ledPins[ledIndex], LOW);
}
void lightLed_over(byte ledIndex) {
  digitalWrite(ledPins[ledIndex], HIGH);
  delay(50);
  digitalWrite(ledPins[ledIndex], LOW);
}
void playSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte currentLed = gameSequence[i];
    lightLed(currentLed);
    delay(50);
  }
}
byte readButtons() {
  while (true) {
    for (byte i = 0; i < 4; i++) {
      byte buttonPin = buttonPins[i];
      if (digitalRead(buttonPin) == LOW) {
        return i;
      }
    }
    delay(1);
  }
}
void gameOver() {
  Serial.print("Game over! your score: ");
  Serial.println(gameIndex - 1);
  gameIndex = 0;
  lightLed_over(0);
  lightLed_over(1);
  lightLed_over(2);
  lightLed_over(3);
  delay(200);
}
bool checkUserSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte expectedButton = gameSequence[i];
    byte actualButton = readButtons();
    lightLed(actualButton);
    if (expectedButton != actualButton) {
      return false;
    }
  }

  return true;
}

/**
   The main game loop
*/
void loop() {
  // Add a random color to the end of the sequence
  gameSequence[gameIndex] = random(0, 4);
  gameIndex++;
  if (gameIndex >= MAX_GAME_LENGTH) {
    gameIndex = MAX_GAME_LENGTH - 1;
  }

  playSequence();
  if (!checkUserSequence()) {
    gameOver();
  }

  delay(300);
}