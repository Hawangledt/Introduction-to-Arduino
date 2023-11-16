int potenciometro = A0;
int pinLed = 10;

void setup(){
    Serial.begin(9600);
      pinMode(pinLed, OUTPUT);
}

void loop(){
    int valorPotenciometro = analogRead(potenciometro);
    Serial.println(valorPotenciometro);
      digitalWrite(pinLed, HIGH);
      delay(0+valorPotenciometro);
      digitalWrite(pinLed, LOW);
      delay(1023-valorPotenciometro);
}