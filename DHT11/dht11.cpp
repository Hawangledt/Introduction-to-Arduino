/*

     Especificações e características:

–    Tensão de operação: 3,5 a 5,5VDC
–   Corrente de operação: 0,3mA
–   Corrente de operação (em stand by): 60µA
–   Resolução: 16 bits
–   Faixa de medição (umidade): 20 a 90%
–   Faixa de medição (temperatura): 0º a 50º celsius
–   Precisão (umidade): ±5%
–   Precisão (temperatura): ±2º celsius
–   Tempo de resposta: 2s

*/

// Datasheet: https://blogmasterwalkershop.com.br/arquivos/datasheet/Datasheet%20DHT11.pdf

#include "dht.h" //Biblioteca de Funções para o módulo DHT11

const int pinoDHT11 = A2;

dht DHT; //Variável do tipo DHT, presente na biblioteca "dht.h"

void setup(){
  Serial.begin(9600);
  delay(2000);
}

void loop(){
  DHT.read11(pinoDHT11); //Lê os dados do sensor, com funções de conversão embutidas no tipo DHT
  Serial.print("Umidade: ");
  Serial.print(DHT.humidity);
  Serial.print("%")
  Serial.print(" / Temperatura: ")
  Serial.print(DHT.temperature, 0); //Imprime o valor na Serial porem removendo a parte decimal
  Serial.println("*C");
  delay(2000);
}