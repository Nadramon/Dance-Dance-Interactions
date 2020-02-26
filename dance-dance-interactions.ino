int echoPins[] = {5, 6, 9};
int trigPins[] = {4, 7, 8};
int buzzerPin = 10;
double C[3][7] = {{523, 587, 659, 698, 784, 880, 988}, {131, 147, 165, 175, 196, 220, 247}, {262, 294, 330, 350, 392, 440, 493}};
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < sizeof(echoPins); i++) {
    pinMode(echoPins[i], INPUT);
  }

  for (int i = 0; i < sizeof(trigPins); i++) {
    pinMode(trigPins[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);
}
void loop() {
  // Take Samples:
  for (int i = 0; i < sizeof(trigPins) - 3; i++) {
    Serial.println(i);
    digitalWrite(trigPins[i], LOW);
    delayMicroseconds(2);
    digitalWrite(trigPins[i], HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPins[i], LOW);
    duration = pulseIn(echoPins[i], HIGH);
    distance = duration*0.034/2;
    int coord = distance / 15;
    if (coord == 0) {
      noTone(buzzerPin);
    }
    else if (coord < 7) {
      tone(buzzerPin, C[i][coord - 1]);
    }
  }
  delay(80);
}
