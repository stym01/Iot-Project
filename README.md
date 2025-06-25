# 🔋 Battery Health Optimization Using IoT and Machine Learning

A smart IoT-based system designed to **monitor and predict the Remaining Useful Life (RUL)** of a car battery using real-time sensor data and machine learning (Random Forest Regression). The solution not only gathers live battery metrics but also offers **proactive maintenance insights** to optimize performance and extend battery lifespan.

> 🛠️ Built with: ESP32 · Real-time IoT Sensors · Arduino IoT Cloud · Jupyter ML

---

## 📌 Project Objectives

- Measure car battery health using key indicators (Voltage, Current, Temperature, Humidity)
- Predict **Remaining Useful Life (RUL)** using a trained ML model
- Enable **real-time monitoring** via Arduino IoT Cloud
- Promote **preventive maintenance** to reduce battery failure risks

---

## 📁 Repository Overview


```
├── Iot Codes/
│   ├── Untitled_oct01a.ino        # Arduino code for ESP32 sensor reading + cloud publishing
│   ├── arduino_secrets.h          # WiFi + device credentials
│   ├── sketch.json                # Configuration file for Arduino sketch
│   └── thingProperties.h          # Arduino IoT Thing setup & configuration
├── Screenshots/
│   ├── Picture1.png               
│   ├── Picture2.jpg               
│   └── Picture3.jpg               
├── README.md                      # This overview document
└── iot_ml.ipynb                   # Jupyter Notebook for IoT data analysis and machine learning
```

---

## **Project Workflow**
1. **Dataset**:
   - Data includes features such as **temperature**, **discharge rate**, and **current**.
   - Historical battery performance metrics used for training and testing.

2. **Machine Learning Pipeline**:
   - **Data Preprocessing**: Cleaned and prepared the dataset for modeling.
   - **Model Building**: Trained a **Random Forest Regressor** to predict RUL.
   - **Evaluation**: Assessed model accuracy using metrics like **Mean Absolute Error (MAE)** and **R² Score**.

3. **Output**:
   - Predicts the RUL for a given set of battery parameters.
   - Provides predictions as a single output or batch.

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
