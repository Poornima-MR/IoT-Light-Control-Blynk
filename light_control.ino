#define BLYNK_TEMPLATE_ID "TMPL3frrCPhqZ"
#define BLYNK_TEMPLATE_NAME "Light Control"
#define BLYNK_AUTH_TOKEN "iv6dwYYpR3EAMgM9_cJtqHGR4OidMME2"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = "Airtel_Krishna";
char pass[] = "Poornima_13";
#define LED_PIN D1
int ledStatus = 0;
BLYNK_WRITE(V0) {
  ledStatus = param.asInt();
  digitalWrite(LED_PIN, ledStatus);

  if (ledStatus == 1)
    Serial.println("LED is ON");
  else
    Serial.println("LED is OFF");
}
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.print("Connecting to Blynk");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println(" Connected!");
}
void loop() {
  Blynk.run();

  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 5000) {
    Serial.print("LED Status: ");
    Serial.println(ledStatus == 1 ? "ON" : "OFF");
    lastPrint = millis();
  }
}
