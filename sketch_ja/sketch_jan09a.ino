#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "moamel";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.setHostname("ESP32_LAB");

  ArduinoOTA
    .onStart([]() {
      Serial.println("Start OTA");
    })
    .onEnd([]() {
      Serial.println("\nEnd OTA");
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]\n", error);
    });

  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();

  // مثال: وميض LED
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
