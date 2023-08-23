bool greenLed = 0;
long interval;
long start;
long count;
 
void setup() {
  Serial.begin(9600);
 
  pinMode(2, INPUT_PULLUP);
 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 
  interval = random(4, 11) * 1000;
  start = millis();
}
 
void loop() {
  if(greenLed) {
    // if buttton press, then show time and start over
    if(digitalRead(2) == 0) {
      double time = millis() - count;
      Serial.print(time / 1000.0);
      Serial.println(" sec");
      digitalWrite(8, LOW);
      greenLed = 0;
      start = millis();
      interval = random(4, 11) * 1000;
      delay(1000);
    }
  } else {
    // if button press, show red, then start over
    // if not button press and it is time, turn green on
 
    if(digitalRead(2) == 0) {
      digitalWrite(9, HIGH);
      delay(2000);
      digitalWrite(9, LOW);
      start = millis();
      interval = random(4, 11) * 1000;      
    }
 
    if(millis() - start >= interval) {
      greenLed = 1;
      digitalWrite(8, HIGH);
      count = millis();
    }
  }
}
