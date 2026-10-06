const int FWD  = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int STOP = 6;

void setup() {
  pinMode(FWD, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(STOP, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(STOP) == LOW)
    Serial.write('S');

  else if (digitalRead(FWD) == LOW)
    Serial.write('F');

  else if (digitalRead(BACK) == LOW)
    Serial.write('B');

  else if (digitalRead(LEFT) == LOW)
    Serial.write('L');

  else if (digitalRead(RIGHT) == LOW)
    Serial.write('R');

  else
    Serial.write('S');

  delay(50);
}
