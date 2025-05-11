// Пины TX и RX можно задать через HardwareSerial (например, Serial1)
//HardwareSerial MotorSerial(1);

void setup() {
  Serial.begin(115200);           // Отладочный порт
  Serial2.begin(9600, SERIAL_8N1, 17, 16); // TX=17, RX=16 (проверь свои пины)
}

void loop() {
  int speedLeft = 150;
  bool forwardLeft = true;
  bool backwardLeft = false;
  int speedRight = 150;
  bool forwardRight = true;
  bool backwardRight = false;

  // Формируем строку: "150,1,0,150,1,0\n"
  String packet = String(speedLeft) + "," + forwardLeft + "," + backwardLeft + "," +
                  speedRight + "," + forwardRight + "," + backwardRight + "\n";
  Serial.println(packet);

  Serial2.print(packet);

  delay(100); // Отправка раз в 100 мс
}
