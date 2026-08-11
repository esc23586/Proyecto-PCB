//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

//apilcado en Robot Sumo  23586
#include "BluetoothSerial.h"
#include "Arduino.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char command;

// Pines del puente H
const int IN1 = 7;  // Pin para controlar la dirección 1
const int IN2 = 8;  // Pin para controlar la dirección 2
const int IN3 = 9;  // Pin para controlar la dirección 1
const int IN4 = 10;  // Pin para controlar la dirección 2

// estos son los pines que van a mandar el pwm para el cambio de movimiento en los motores. 

void setup() {
  Serial.begin(115200);
  SerialBT.begin("GEscobedo"); //Bluetooth device name
  Serial.println("Listo");

  // Configuramos los pines como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(2, OUTPUT);
  
  // todas las salidas inician como apagado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(2, LOW);
}

//inicia la configuración de los datos recibidos y realiza la comparativa. 
// en caso de futuramente quere algun otro dato, pues se cambia en la aplicación de Arduino Car.
void loop() {
  while (SerialBT.available()) { // Si hay datos disponibles a través del Bluetooth
    command = SerialBT.read();  // Leemos el comando
    Serial.println(command);
    if (command == 'A'){
      forward();
    }
    else if(command == 'B'){
      backward();
    }
    else if(command == 'C'){
      left();
    }
    else if(command == 'D'){
      right();
    }
    else if(command == 'Q'){
      lf();
    }
    else if(command == 'E'){
      rf();
    }
    else if(command == 'Z'){
      lb();
    }
    else if(command == 'O'){
      rb();
    }


    else if(command == 'S'){
      stop();
    }
  }
}


void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(2, HIGH);
  Serial.println("Avanzando");
}
void backward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(2, HIGH);
  Serial.println("Retrocediendo");
}
void left(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(2, HIGH);
  Serial.println("Avanzando");
}
void right(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(2, HIGH);
  Serial.println("Avanzando");
}
void stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(2, LOW);
  Serial.println("parar");
}

void lf(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rf(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void lb(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rb(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
