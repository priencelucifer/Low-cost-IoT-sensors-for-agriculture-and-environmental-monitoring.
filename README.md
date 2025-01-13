### Detailed Report: Low-Cost IoT Sensor Node for Agricultural and Environmental Monitoring

#### Objective
To develop a low-cost IoT sensor node that enables real-time monitoring of environmental parameters including pressure, temperature, humidity, altitude, and soil characteristics (moisture, NPK levels), with wireless data transmission capabilities. The total manufacturing cost should be below ₹2000.

---

### Components Overview

1. **Microcontroller:** NodeMCU (ESP8266)
2. **Environmental Sensors:**
   - BMP280 (Pressure, Temperature, Altitude)
   - DHT11 (Temperature, Humidity)
   - Soil Moisture Sensor
3. **NPK Sensor Setup:**
   - Ion Sensitive Electrodes
   - LM393 Comparator IC
   - LM358 Operational Amplifier IC
   - Resistors: 10kΩ, 100Ω
   - Capacitors: 10nF, 100μF
4. **Power Supply:**
   - Two TP4056 Charging Modules
   - 2200mAh Lithium Battery
5. **Additional Components:**
   - Jumper Wires

---

### Project Requirements

#### Environmental Monitoring

- **BMP280:** Provides accurate measurements of pressure, temperature, and altitude.
- **DHT11:** Ensures reliable readings of temperature and humidity.
- **Soil Moisture Sensor:** Monitors soil water content.

#### NPK Sensor Development

The NPK sensor is the critical component of this project, designed to measure the concentrations of Nitrogen (N), Phosphorus (P), and Potassium (K) in the soil. This section will cover 60% of the report, detailing the components, design, calibration, and implementation of the NPK sensor.

---

### NPK Sensor Details

1. **Electrodes:**
   - *Ion Sensitive Electrodes:* These electrodes are selected for their ability to measure the ionic concentration of N, P, and K in the soil. Electrodes are corrosion-resistant and provide consistent readings.

2. **Amplification and Signal Conditioning:**
   - *LM358 Operational Amplifier:* Used to amplify the weak voltage signals from the electrodes. The LM358 has two input pins for differential measurement and one output pin.
   - *LM393 Comparator IC:* Converts the amplified analog signals to digital outputs. The LM393 has two input pins and one output pin that interfaces with the ADC module.
   - *Resistors and Capacitors:*
     - Resistors: 10kΩ and 100Ω resistors are used for setting gain and voltage levels.
     - Capacitors: 10nF and 100μF capacitors are used for noise filtering and signal stabilization.

3. **ADC Integration:**
   - *ADS1115 ADC Module:* Reads the analog signals from the NPK sensor and converts them to digital signals. The ADS1115 provides high-precision measurements and communicates with the NodeMCU via I2C.

4. **Circuit Design:**
   - *Electrode Connections:* Connect the ion-sensitive electrodes to the input pins of the LM358 operational amplifier.
   - *Amplification:* The output pins of the LM358 are connected to the input pins of the LM393 comparator IC.
   - *Signal Conditioning:* Resistors and capacitors are used for setting the appropriate gain and filtering noise.
   - *ADC Interface:* The digital output from the LM393 is fed into the analog input pins (A0, A1, A2) of the ADS1115 ADC module.
   - *Microcontroller Connection:* The ADS1115 is connected to the NodeMCU via I2C using D4 (SDA) and D5 (SCL).

5. **Calibration:**
   - Calibration is essential to ensure accurate NPK measurements. Use known soil samples with specific NPK concentrations to map the sensor readings to actual NPK values.
   - Calibration factors are determined and implemented in the software to adjust the raw sensor readings.

6. **Implementation:**
   - The NodeMCU reads the digital signals from the ADS1115, processes the data to calculate NPK values, and transmits the data wirelessly to a monitoring system.
   - The system is calibrated and tested in various soil conditions to validate accuracy and reliability.

---

### Wireless Data Transmission and User Interface

1. **Wi-Fi Access Point:**
   - The NodeMCU will be configured to act as a Wi-Fi Access Point (AP). This means it will create its own Wi-Fi network that users can connect to with their smartphones.
   - When the NodeMCU is powered on, it will broadcast its SSID (network name) and allow devices to connect to it directly.

2. **User Interface:**
   - Once connected to the NodeMCU's Wi-Fi network, users can access the sensor data through a web-based interface.
   - A simple web server will be set up on the NodeMCU, hosting an HTML page that displays the real-time data from the sensors.
   - The data will be refreshed at regular intervals to ensure up-to-date monitoring.

3. **Data Display:**
   - The HTML page will display the readings from the BMP280 (pressure, temperature, altitude), DHT11 (temperature, humidity), soil moisture sensor, and the NPK sensor (Nitrogen, Phosphorus, Potassium levels).
   - Users can view this data on any device with a web browser (e.g., smartphones, tablets, laptops) connected to the NodeMCU's Wi-Fi network.
   - To connect to the device, scan the Wi-Fi network and connect to **NodeMCU_AP**, with the password **password123**, then open a browser and navigate to the URL **192.168.4.1** to access the webpage.

---

### Power Management

- **TP4056 Charging Modules and 2200mAh Lithium Battery:** Provide a reliable power source for the NodeMCU and sensors, ensuring uninterrupted operation. The TP4056 modules manage charging and battery protection.

---

### Implementation and Deployment

1. **Component Assembly:** Gather all required components and ensure compatibility.
2. **Circuit Construction:** Assemble the NPK sensor circuit, connecting electrodes, amplifiers, comparators, and ADC module as per the design.
3. **Power Configuration:** Connect the TP4056 charging modules and lithium battery for a stable power supply.
4. **Programming and Calibration:**
   - Upload the software to the NodeMCU to process sensor data and transmit it wirelessly.
   - Perform calibration using known soil samples to determine accurate calibration factors.
5. **Testing:** Validate sensor readings against standard soil test results and make necessary adjustments.
6. **Field Deployment:** Assemble the system in a weather-resistant enclosure for real-time soil monitoring.
