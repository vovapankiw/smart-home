const int ledPins[] = {13,12,11};
const int buttonPin = 3;
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);


void setup () {
    for(int i = 0; i < ledCount; i++) {
        pinMode(ledPins[i], OUTPUT);
    }

    pinMode(buttonPin, INPUT);
}

void loop () {
    bool button = digitalRead(buttonPin);

    while (digitalRead(buttonPin) == HIGH) {
        for (int i = 0; i < ledCount; i++) {
            digitalWrite(ledPins[i], HIGH);
            delay(200);
            digitalWrite(ledPins[i], LOW);
        }
    }
     for(int i = 0; i < ledCount; i++) {
            digitalWrite(ledPins[i], LOW);
        }

    delay(50);
}