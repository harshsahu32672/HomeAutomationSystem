#define BLYNK_TEMPLATE_ID "TMPLxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <HardwareSerial.h>

char ssid[] = "homerouter";
char pass[] = "harshsahu32";

HardwareSerial sim900(2);

#define LIGHT 5
#define FAN 18
#define BULB 19

String message = "";

void setup() {
  Serial.begin(115200);

  pinMode(LIGHT, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(BULB, OUTPUT);

  digitalWrite(LIGHT, LOW);
  digitalWrite(FAN, LOW);
  digitalWrite(BULB, LOW);

  sim900.begin(9600, SERIAL_8N1, 16, 17);
  delay(1000);
  sim900.println("AT");
  delay(1000);
  sim900.println("AT+CMGF=1");
  delay(1000);
  sim900.println("AT+CNMI=1,2,0,0,0");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  readSMS();
}

BLYNK_WRITE(V0) {
  digitalWrite(LIGHT, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(FAN, param.asInt());
}

BLYNK_WRITE(V2) {
  digitalWrite(BULB, param.asInt());
}

void readSMS() {
  while (sim900.available()) {
    char c = sim900.read();
    message += c;
  }

  if (message.length() > 0) {

    if (message.indexOf("LIGHT ON") != -1) {
      digitalWrite(LIGHT, HIGH);
      sendSMS("Light ON");
    }
    else if (message.indexOf("LIGHT OFF") != -1) {
      digitalWrite(LIGHT, LOW);
      sendSMS("Light OFF");
    }
    else if (message.indexOf("FAN ON") != -1) {
      digitalWrite(FAN, HIGH);
      sendSMS("Fan ON");
    }
    else if (message.indexOf("FAN OFF") != -1) {
      digitalWrite(FAN, LOW);
      sendSMS("Fan OFF");
    }
    else if (message.indexOf("BULB ON") != -1) {
      digitalWrite(BULB, HIGH);
      sendSMS("Bulb ON");
    }
    else if (message.indexOf("BULB OFF") != -1) {
      digitalWrite(BULB, LOW);
      sendSMS("Bulb OFF");
    }

    message = "";
  }
}

void sendSMS(String text) {
  sim900.println("AT+CMGF=1");
  delay(500);
  sim900.println("AT+CMGS=\"+91XXXXXXXXXX\"");
  delay(500);
  sim900.print(text);
  delay(500);
  sim900.write(26);
}