//bluetooth
#include <SoftwareSerial.h>
//dht
#include <DHT.h>
#include <DHT_U.h>

//bluetooth
SoftwareSerial bt(0, 1);
//leds
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
//ultrasonico
int trig = 13; 
int echo = 12;
int led = 11;
int duration;
int distance;
//dht
#define Type DHT11 //tipo de sensor (sin ";")
int dhtPin = 10; //pin en el arduino del sensor
DHT HT(dhtPin, Type); //forma de lectura
int humidity; //tempreatura y humedad se lee en float
float tempC;
float tempF;
int dt (1000);
//bluetooth
char val;

void setup() {
  //bluetooth
  bt.begin(38400);
  Serial.begin(9600);
  //leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  //ultrasonico
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  //dht
  HT.begin(); //inicializar el sensor
}

void loop() {
  //bluetooth leds
  if(Serial.available())
    val = Serial.read();
  switch(val){
    //led1
    case 'A':
    digitalWrite(led1, HIGH);
    break;
    case 'B':
    digitalWrite(led1, LOW);
    break;
    //led2
    case 'C':
    digitalWrite(led2, HIGH);
    break;
    case 'D':
    digitalWrite(led2, LOW);
    break;
    //led3
    case 'E':
    digitalWrite(led3, HIGH);
    break;
    case 'F':
    digitalWrite(led3, LOW);
    break;
    //led4
    case 'G':
    digitalWrite(led4, HIGH);
    break;
    case 'H':
    digitalWrite(led4, LOW);
    break;
    //led5
    case 'I':
    digitalWrite(led5, HIGH);
    break;
    case 'J':
    digitalWrite(led5, LOW);
    break;
    //led6
    case 'K':
    digitalWrite(led6, HIGH);
    break;
    case 'L':
    digitalWrite(led6, LOW);
    break;
    //led7
    case 'M':
    digitalWrite(led7, HIGH);
    break;
    case 'N':
    digitalWrite(led7, LOW);
    break;
    //led8
    case 'O':
    digitalWrite(led8, HIGH);
    break;
    case 'P':
    digitalWrite(led8, LOW);
    break;
  }
  //dht
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  delay(dt);
  //ultrasonico
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;
  if(Serial.available())
    val = Serial.read();
  //X es de la pantalla de cameras
  if(val == 'X'){
    Serial.print("Distancia del objeto más cercano: ");
    Serial.print(distance);
    Serial.println("cm");
  }
  //Y es de la pantalla de thermostate
  if(val == 'Y'){
    Serial.print("Humedad Relativa: ");
    Serial.print(humidity);
    Serial.println("%");
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.print("ºC / ");
    Serial.print(tempF);
    Serial.println("°F");
  }
  delay(500);
  if(distance <= 15 && distance >= 0){
    digitalWrite(led, HIGH);
  }else if(distance > 15){
    digitalWrite(led, LOW);
  }
}
