// Código Controlando o estado de um programa, via pushbotton:

int pinBotao = 8;
int pinLed = 9;
int estadoBotao = 0;
int programaAtivo = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pinBotao,INPUT);
  pinMode(pinLed,OUTPUT);
}

void piscarLed(){
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
  delay(1000);
}

void loop()
{
    estadoBotao = digitalRead(pinBotao); //Ler Botão

    if(estadoBotao==HIGH){
      delay(50);

      //Inverter o estado do programa
      programaAtivo = !programaAtivo;

      if(programaAtivo==1){
        Serial.println("Botao Pressionado, iniciando programa!");
      }
      else{
        Serial.println("Botao Pressionado, Encerrando programa!");
        digitalWrite(pinLed, LOW);
      }

      while(digitalRead(pinBotao) == 1) {
        delay(10);
      }

    }

    if(programaAtivo==1){
        piscarLed();
    }
}