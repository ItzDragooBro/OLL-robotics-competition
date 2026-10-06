#include <SoftwareSerial.h>

// Software Serial pins for HC-05 Bluetooth module
// RX = Pin 2 (connects to HC-05 TX)
// TX = Pin 3 (connects to HC-05 RX through potential divider)
SoftwareSerial bluetooth(2, 3); 

// Motor A Driver Pins (Left Motor)
const int IN1 = 5;
const int IN2 = 6;

// Motor B Driver Pins (Right Motor)
const int IN3 = 9;
const int IN4 = 10;

char command;

void setup() {
  // Initialize Motor Pins as Outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start Serial Communications
  bluetooth.begin(9600);
  stopCar();
}

void loop() {
  // Check if data is coming from the Bluetooth module
  if (bluetooth.available() > 0) {
    command = bluetooth.read();
    
    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'S':
        stopCar();
        break;
    }
  }
}

// Helper Functions for Directional Movement

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
