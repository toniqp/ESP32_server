#include <WiFi.h>
#include <WebServer.h>
#define LED_PIN 2
const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";

WebServer server(80);

bool state = false;
void handleRoot();
void switchLed();

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, false);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led", switchLed);
  server.begin();
  Serial.println("Start Server!");
}

void loop()
{
  server.handleClient();
}

void handleRoot()
{
  String html = "<html>\
  <head><title>ESP32 LED</title></head>\
  <body>\
  <p> Светодиод сейчас: " +
                String(state ? "ВКЛ" : "ВЫКЛ") + " </p>\
  <a href=\"/led?state=on\"><button>LED ON</button></a>\
  <a href=\"/led?state=off\"><button>LED OFF</button></a>\
  </body>\
  </html>";

  server.send(200, "text/html", html);
}
void switchLed()
{
  if (server.hasArg("state"))
  {
    String value = server.arg("state");
    if (value == "on")
    {
      digitalWrite(LED_PIN, HIGH);
      state = true;
    }
    else if (value == "off")
    {
      digitalWrite(LED_PIN, LOW);
      state = false;
    }
  }
}