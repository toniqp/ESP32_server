

String buffer  = "";
String current = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
}

void loop() {
  while (Serial1.available()) {
    char c = Serial1.read();

    if (c == '\r') continue;
    if (c == '\n') {
      if (current.length()) buffer = current;
      current = "";
    } else {
      current += c;
    }
  }

  static unsigned long t;
  if (millis() - t > 100) {
    t = millis();
    Serial.print("Текущее значение: ");
    Serial.println(buffer);
  }
}
