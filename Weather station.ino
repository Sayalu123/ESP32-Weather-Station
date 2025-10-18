#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

// OLED Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT Settings
#define DHTPIN 4       
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// RGB LED Pins
#define RED_PIN   25
#define GREEN_PIN 26
#define BLUE_PIN  27

void setup() {
  Serial.begin(115200);
  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ESP32 Smart Weather");
  display.display();
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Temp: " + String(temp) + " °C");
  display.println("Hum:  " + String(hum) + " %");

  // Determine condition based on both temp and humidity
  String condition = "";
  if (temp > 32 && hum < 50) {
    condition = "🔥 Hot & Dry";
    setRGBColor(HIGH, LOW, LOW);  // Red
  } 
  else if (temp < 30 && hum > 70) {
    condition = "🌧️ Rainy / Humid";
    setRGBColor(LOW, LOW, HIGH);  // Blue
  } 
  else if (temp >= 24 && temp <= 32 && hum >= 40 && hum <= 70) {
    condition = "🌤️ Pleasant";
    setRGBColor(LOW, HIGH, LOW);  // Green
  } 
  else if (temp < 24 && hum >= 50 && hum <= 80) {
    condition = "❄️ Cool & Moist";
    setRGBColor(HIGH, HIGH, HIGH);  // White
  } 
  else {
    condition = "🌫️ Unstable";
    setRGBColor(LOW, LOW, LOW);  // LED off
  }

  display.println("Condition:");
  display.println(condition);
  display.display();

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" °C, Humidity: "); Serial.print(hum);
  Serial.print("% → "); Serial.println(condition);

  delay(3000);
}

// RGB LED Color Setter
void setRGBColor(bool r, bool g, bool b) {
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}
