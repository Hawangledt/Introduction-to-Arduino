#define PERFIL_GITHUB "https://github.com/Hawangledt"
const int ledPin = 9;
int brilhoCrescente;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  for(brilhoCrescente=0; brilhoCrescente<255; brilhoCrescente++){
  	analogWrite(pinLed, brilhoCrescente);
    delay(10);
  }
  Serial.println(PERFIL_GITHUB);
  
  for(int brilhoDescrente=255; brilhoDescrente>0; brilhoDescrente--){
  	analogWrite(pinLed, brilhoDescrente);
    delay(10);
  }
}