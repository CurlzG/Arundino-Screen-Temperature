#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
void setup() {
  Serial.begin(115200);

  Serial.println("OLED FeatherWing test");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  Serial.println("OLED begun");

  display.display();
  delay(1000);
sensors.begin();
  // Clear the buffer.
  display.clearDisplay();
  display.display();
  // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.display(); // actually display all of the above
}

void loop() {
  delay(1000);
  sensors.requestTemperatures(); 
   display.println(sensors.getTempCByIndex(0));
  yield();
  display.display();
}
