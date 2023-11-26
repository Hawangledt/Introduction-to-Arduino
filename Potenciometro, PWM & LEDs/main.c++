const int buttonPin = 4;
const int motorPin = 3;
const int potPin = A5;
const int leds[] = {7, 8, 9, 10, 11, 12, 13};
const int numLeds = 7;



int motorSpeed = 0;
bool motorOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  delay(1000);
  Serial.println("Inicio do Programa!");
}

void loop() {

  if (digitalRead(buttonPin) == HIGH) {
    while(digitalRead(buttonPin) == HIGH) {
        delay(10);
    }
    
    Serial.println("Botão pressionado!");
    // Se o botão for pressionado, alterne o estado do motor
    motorOn = !motorOn;
    delay(500);  // Debouncing
  }

  // Se o motor estiver ligado, leia o potenciômetro e ajuste a velocidade
  if (motorOn) {
    motorSpeed = map(analogRead(potPin), 0, 1023, 0, 255);
  } else {
    motorSpeed = 0;  // Se o motor estiver desligado, a velocidade é zero
  }

  analogWrite(motorPin, motorSpeed);

  updateLeds();

  delay(50);
}

void updateLeds() {
  int ledLevel = map(motorSpeed, 0, 255, 0, numLeds);

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
  }

  for (int i = 0; i < ledLevel; i++) {
    digitalWrite(leds[i], HIGH);
  }
}
