//Bibliotecas

#include <Arduino.h> 

const int pinLed = 13;
const int pinMotor = 9;
const int pinSensor = A0; //Pino de sinal Analogico

// Estados da máquina de estados
enum Estados {
  ESTADO_LED,
  ESTADO_MOTOR,
  ESTADO_SENSOR
};

// Variável para armazenar o estado atual
Estados estadoAtual = ESTADO_LED;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinMotor, OUTPUT);
  pinMode(pinSensor, INPUT);
}

void loop() {

  switch (estadoAtual) {

    case ESTADO_LED:
      digitalWrite(pinLed, HIGH);
      analogWrite(pinMotor, 0);
      if (analogRead(pinSensor) > 500) {
        estadoAtual = ESTADO_MOTOR;
      }
      break;

    case ESTADO_MOTOR:
      digitalWrite(pinLed, LOW);
      analogWrite(pinMotor, 255);
      if (analogRead(pinSensor) < 100) {
        estadoAtual = ESTADO_SENSOR;
      }
      else {
        estadoAtual = ESTADO_LED;
      }
      break;

    case ESTADO_SENSOR:
      digitalWrite(pinLed, LOW);
      analogWrite(pinMotor, 0);
      if (analogRead(pinSensor) > 800) {
        estadoAtual = ESTADO_LED;
      }
      break;
  }
  delay(100);
}
