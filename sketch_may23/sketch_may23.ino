void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);

  Serial.println("Type commands: 5 on, 5 off, 7 on, 7 off, 9 on, 9 off, all on, all off");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toLowerCase();

    if (command == "5 on") {
      digitalWrite(5, HIGH);
      Serial.println("LED 5 is ON");
    } else if (command == "5 off") {
      digitalWrite(5, LOW);
      Serial.println("LED 5 is OFF");
    } else if (command == "7 on") {
      digitalWrite(7, HIGH);
      Serial.println("LED 7 is ON");
    } else if (command == "7 off") {
      digitalWrite(7, LOW);
      Serial.println("LED 7 is OFF");
    } else if (command == "9 on") {
      digitalWrite(9, HIGH);
      Serial.println("LED 9 is ON");
    } else if (command == "9 off") {
      digitalWrite(9, LOW);
      Serial.println("LED 9 is OFF");
    } else if (command == "all on") {
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(9, HIGH);
      Serial.println("All LEDs are ON");
    } else if (command == "all off") {
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(9, LOW);
      Serial.println("All LEDs are OFF");
    } else {
      Serial.println("Unknown command");
    }
  }
}
