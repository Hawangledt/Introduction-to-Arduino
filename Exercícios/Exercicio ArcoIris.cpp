/*
Elabore um código no arduino para ligar um led RGB, 
o programa deve simular as cores do arco íris usando o led.
*/

int ledVermelho = 6;
int ledVerde = 3;
int ledAzul = 5;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  arcoIris();
}

void arcoIris() {
  for (int i = 0; i < 255; i++) {
    setCor(i, 255 - i, 0);  // Vermelho para amarelo
    delay(10);
  }
  for (int i = 0; i < 255; i++) {
    setCor(0, i, 255 - i);  // Amarelo para verde
    delay(10);
  }
  for (int i = 0; i < 255; i++) {
    setCor(i, 0, 255 - i);  // Verde para azul
    delay(10);
  }
  for (int i = 0; i < 255; i++) {
    setCor(255 - i, i, 0);  // Azul para vermelho
    delay(10);
  }
}

void setCor(int vermelho, int verde, int azul) {
  analogWrite(ledVermelho, vermelho);
  analogWrite(ledVerde, verde);
  analogWrite(ledAzul, azul);
}