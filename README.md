# Low-Cost IoT Sensor Node for Agricultural and Environmental Monitoring

## Objective
Develop a low-cost IoT sensor node to enable real-time monitoring of environmental parameters, including pressure, temperature, humidity, altitude, and soil characteristics (moisture, NPK levels), with wireless data transmission capabilities. The total manufacturing cost should be below ₹2000.

## Components
### 1. Microcontroller
- **NodeMCU (ESP8266):** A cost-effective microcontroller with built-in Wi-Fi for seamless wireless data transmission.

### 2. Sensors
- **BMP280:** Measures pressure, temperature, and altitude with high accuracy.
- **DHT11:** Monitors temperature and humidity.
- **Soil Moisture Sensor:** Determines soil water content.

### 3. Power Supply
- **Two TP4056 Charging Modules:** For safe and efficient lithium battery charging.
- **2200 mAh Lithium Battery:** Provides an uninterrupted power supply for extended operation.

### 4. NPK Sensor
- **Ion-Sensitive Electrodes:** Detect nitrogen (N), phosphorus (P), and potassium (K) levels in the soil.
- **LM393 IC:** Converts analog signals into digital outputs based on threshold values.
- **LM358 IC:** Amplifies weak electrode signals for accurate measurement.
- **Resistors:** 10kΩ and 100Ω for signal conditioning.
- **Capacitors:** 10nF and 100μF for noise filtering and stabilization.

### 5. Additional Components
- **Jumper Wires:** For connecting components and establishing circuits.

## Functional Requirements

### Environmental Monitoring
1. **Pressure, Temperature, and Altitude:**
   - The BMP280 sensor provides real-time, accurate measurements of these parameters.
2. **Temperature and Humidity:**
   - The DHT11 sensor ensures reliable temperature and humidity readings, complementing the BMP280 sensor.

### Soil Monitoring
1. **Moisture:**
   - The soil moisture sensor continuously monitors soil water content, helping optimize irrigation schedules.
2. **NPK Levels:**
   - A custom-built NPK sensor integrates ion-sensitive electrodes, LM393, and LM358 ICs for accurate soil nutrient analysis.

### Wireless Data Transmission
- The NodeMCU microcontroller enables real-time wireless data transmission over Wi-Fi, allowing seamless integration with cloud platforms or local servers.

### Power Management
- Dual TP4056 charging modules and a 2200 mAh lithium battery ensure a steady and reliable power supply for uninterrupted operation.

## NPK Sensor Details
1. **Electrodes:**
   - Ion-sensitive electrodes detect specific soil nutrients (N, P, K).
2. **Amplification:**
   - LM358 operational amplifier boosts weak electrode signals, ensuring accurate nutrient detection.
3. **Comparators:**
   - LM393 IC processes amplified signals, converting them into digital outputs.
4. **Resistors and Capacitors:**
   - 10kΩ and 100Ω resistors condition the signal.
   - 10nF and 100μF capacitors filter noise and stabilize the signal.
5. **Integration:**
   - Outputs from the NPK sensor are fed into the ADS1115 ADC module, which interfaces with the NodeMCU.
   - Calibration is performed using soil samples with known NPK concentrations to ensure precise readings.

## Summary
This IoT sensor node integrates a variety of sensors and electronic components into a single, cohesive system designed for agricultural and environmental monitoring. The NodeMCU microcontroller facilitates efficient data collection and wireless transmission, while the custom-built NPK sensor offers precise soil nutrient analysis. With a total manufacturing cost under ₹2000, this solution provides farmers and researchers with real-time insights into environmental conditions, empowering them to optimize agricultural practices and improve crop yields.

