void setup() {
  Serial.begin(9600);     // Прием от ESP32
  Serial1.begin(115200);  // Отладка
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  static String input = "";

  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processPacket(input);
      input = "";
    } else {
      input += c;
    }
  }
}

/*void processPacket(String data) {
  int speedLeft, speedRight;
  bool forwardLeft, backwardLeft, forwardRight, backwardRight;

  int parts[6];
  int index = 0;
  char *token = strtok(const_cast<char*>(data.c_str()), ",");

  while (token && index < 6) {
    parts[index++] = atoi(token);
    token = strtok(NULL, ",");
  }

  if (index == 6) {
    speedLeft = parts[0];
    forwardLeft = parts[1];
    backwardLeft = parts[2];
    speedRight = parts[3];
    forwardRight = parts[4];
    backwardRight = parts[5];

    // Управление моторами
    Serial.print("L: ");
    Serial.print(speedLeft);
    Serial.print(" F:");
    Serial.print(forwardLeft);
    Serial.print(" B:");
    Serial.print(backwardLeft);

    Serial.print(" | R: ");
    Serial.print(speedRight);
    Serial.print(" F:");
    Serial.print(forwardRight);
    Serial.print(" B:");
    Serial.println(backwardRight);

    digitalWrite(5, speedLeft);
    digitalWrite(6, forwardLeft);
    digitalWrite(7, backwardLeft);

    digitalWrite(8, speedRight);
    digitalWrite(9, forwardRight);
    digitalWrite(10, backwardRight);

    // Здесь добавьте управление моторами (например, через PWM + цифровые пины)
  } else {
    Serial1.println("Ошибка парсинга");
  }
}*/
