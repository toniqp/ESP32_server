#define rx2 16
#define tx2 17

void setup() {
  Serial2.begin(115200, SERIAL_8N1, rx2, tx2);

}

void loop() {
  Serial2.println("5");

}
