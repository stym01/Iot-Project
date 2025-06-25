# 🔋 Battery Health Optimization Using IoT and Machine Learning

A smart IoT-based system designed to **monitor and predict the Remaining Useful Life (RUL)** of a car battery using real-time sensor data and machine learning (Random Forest Regression). The solution not only gathers live battery metrics but also offers **proactive maintenance insights** to optimize performance and extend battery lifespan.

> 🛠️ Built with: ESP32 · Real-time IoT Sensors · Arduino IoT Cloud · Jupyter ML

---

## 📌 Project Objectives

- Measure car battery health using key indicators (Voltage, Current, Temperature, Humidity)
- Predict **Remaining Useful Life (RUL)** using a trained ML model (R² score = 99.89%)
- Enable **real-time monitoring** via Arduino IoT Cloud
- Promote **preventive maintenance** to reduce battery failure risks

---

## 🧠 How It Works

1. **Sensor Integration**  
   ESP32 board collects real-time values from:
   - Voltage Sensor
   - Current Sensor
   - Humidity Sensor
   - Temperature Sensor

2. **Data Transmission**  
   The ESP32 sends sensor data to the **Arduino IoT Cloud dashboard** using MQTT.

3. **Machine Learning Model**  
   - Jupyter Notebook (`iot_ml.ipynb`) loads sensor data (`Iot.csv`)
   - Random Forest Regressor is trained to estimate battery health/RUL
   - Achieves **R² score of 99.89%**, ensuring highly reliable predictions

4. **Insight Delivery**  
   Based on predictions, the system provides actionable insights for battery replacement/servicing.

---

## 📁 Repository Overview

```
├── Untitled_oct01a.ino       # Arduino code for ESP32 sensor reading + cloud publishing
├── arduino_secrets.h         # WiFi + device credentials (excluded in GitHub for security)
├── thingProperties.h         # AWS/Arduino IoT Thing setup & configuration
├── Iot.csv                   # Labeled sensor data for ML training
├── iot_ml.ipynb              # Jupyter notebook for ML training & predictions
├── sketch.json               # Arduino Cloud metadata
```

---

## 🛠️ Hardware & Software Stack

- **Hardware:**
  - ESP32 microcontroller
  - Voltage & Current sensors
  - DHT11 (Humidity + Temperature)
- **Software:**
  - Arduino IDE
  - Arduino IoT Cloud
  - Python (Jupyter Notebook)
  - Random Forest Regression (via Scikit-learn)

---

## 🚀 Setup & Deployment

### 🔌 ESP32 Setup

1. Connect all sensors to the ESP32 board.
2. Open `Untitled_oct01a.ino` in Arduino IDE.
3. Update WiFi credentials in `arduino_secrets.h`.
4. Configure your device in Arduino IoT Cloud and copy the credentials to `thingProperties.h`.
5. Upload the sketch to ESP32 and verify data flow in the Arduino IoT Cloud dashboard.

### 📊 Machine Learning Setup

1. Open `iot_ml.ipynb` using Jupyter Notebook.
2. Install dependencies:  
   ```bash
   pip install pandas numpy scikit-learn matplotlib
   ```
3. Load `Iot.csv`, explore trends, and train the Random Forest model.
4. Get predicted RUL and health score visualizations.

---

## ✅ Model Performance

- **Algorithm**: Random Forest Regressor
- **Feature Inputs**: Voltage, Current, Humidity, Temperature
- **Target Output**: Battery Health (Remaining Useful Life)
- **R² Score**: **0.9989** (99.89%)  
  → Indicates **very strong correlation** between sensor data and predicted battery life

---

## 💡 Future Improvements

- Deploy ML model directly on the ESP32 using TinyML
- Add mobile app dashboard using Flutter or React Native
- Store long-term logs in Firebase / AWS for trend analysis
- Add alert system (email/SMS) for low battery warnings

---

## 🤝 Contributing

Pull requests and feedback are always welcome! If you'd like to suggest new features or fixes, feel free to fork the repo or open an issue.

---

## 🙌 Closing Note

Thank you for exploring this project! If you found it insightful or inspiring, feel free to ⭐ the repo and share your thoughts. Let’s keep building cool tech that makes everyday things smarter!
