#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// BMP280 instance
Adafruit_BMP280 bmp;

// DHT11 setup
#define DHTPIN D3  // DHT11 data pin connected to D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Moisture sensor setup
#define MOISTURE_PIN A0  // Moisture sensor connected to A0
const int moistureDry = 1023; // Adjust based on your sensor's range (calibrated for dry)
const int moistureWet = 300;  // Adjust based on your sensor's range (calibrated for wet)

// Wi-Fi Access Point credentials
const char* ssid = "NodeMCU_AP";
const char* password = "password123";

// Web server instance
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Initialize DHT11
  dht.begin();

  // Initialize BMP280
  if (!bmp.begin(0x76)) {  // Use 0x77 if SDO is connected to 3.3V
    Serial.println("BMP280 sensor not found!");
    while (1);
  }

  // Optional: Configure BMP280 sampling
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,    // Temp oversampling
                  Adafruit_BMP280::SAMPLING_X16,   // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,     // Filtering
                  Adafruit_BMP280::STANDBY_MS_500  // Standby time
  );

  // Start Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  Serial.println("Access Point started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Configure web server routes
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  // Handle incoming HTTP requests
  server.handleClient();
}

// Function to get soil moisture percentage
int getMoistureLevel() {
  int moistureValue = analogRead(MOISTURE_PIN);
  int moisturePercent = map(moistureValue, moistureWet, moistureDry, 100, 0);
  moisturePercent = constrain(moisturePercent, 0, 100); // Keep percentage in 0-100 range
  return moisturePercent;
}

// Function to serve the root webpage
void handleRoot() {
  // Read data from DHT11
  float dhtTemp = dht.readTemperature();
  float dhtHumidity = dht.readHumidity();

  // Check if DHT11 readings are valid
  String dhtTempStr = isnan(dhtTemp) ? "N/A" : String(dhtTemp, 2) + " °C";
  String dhtHumidityStr = isnan(dhtHumidity) ? "N/A" : String(dhtHumidity, 2) + " %";

  // Read data from BMP280
  float bmpTemp = bmp.readTemperature();
  float bmpPressure = bmp.readPressure() / 100.0;  // Convert to hPa
  float bmpAltitude = bmp.readAltitude(1013.25);  // Adjust sea-level pressure as needed

  // Read moisture level
  int moisturePercent = getMoistureLevel();

  // Generate the webpage
  String html = "<!DOCTYPE html><html lang='en'><head>";
  html += "<meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Sensor Data</title>";
  html += "<style>body{font-family:Arial, sans-serif;margin:20px;}h1{color:#333;}p{margin:5px 0;}</style>";
  html += "</head><body>";
  html += "<h1>NodeMCU Sensor Data</h1>";

  // DHT11 data
  html += "<h2>DHT11 Readings</h2>";
  html += "<p><strong>Temperature:</strong> " + dhtTempStr + "</p>";
  html += "<p><strong>Humidity:</strong> " + dhtHumidityStr + "</p>";

  // BMP280 data
  html += "<h2>BMP280 Readings</h2>";
  html += "<p><strong>Temperature:</strong> " + String(bmpTemp, 2) + " °C</p>";
  html += "<p><strong>Pressure:</strong> " + String(bmpPressure, 2) + " hPa</p>";
  html += "<p><strong>Altitude:</strong> " + String(bmpAltitude, 2) + " m</p>";

  // Moisture sensor data
  html += "<h2>Soil Moisture Level</h2>";
  html += "<p><strong>Moisture:</strong> " + String(moisturePercent) + " %</p>";

  html += "<p>Refresh the page to get updated data.</p>";
  html += "</body></html>";

  // Send the response
  server.send(200, "text/html", html);
}
