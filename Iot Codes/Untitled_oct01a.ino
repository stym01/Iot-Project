#include "arduino_secrets.h"
/* 

  float current;
  float voltage;
  CloudTemperatureSensor temp;
  CloudRelativeHumidity humidity;

*/

#include "thingProperties.h"
#include "DHT.h"
#define DHTPIN 33
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

//for soc
// Define lead-acid battery voltage limits
float maxVoltage = 12.6;  // Fully charged battery voltage
float minVoltage = 10.5;  // Fully discharged battery voltage


//for voltage
#define VOLTAGE_SENSOR_PIN 35  // voltage sensor pin...
const float ADC_VOLTAGE_REF = 3.3;  // Reference voltage of the ESP32 (3.3V)
const int ADC_RESOLUTION = 4095;    // ADC resolution for ESP32 (12-bit)


// Resistor values in the voltage divider
const float R1 = 30000.0;  // R1 = 30k ohm...
const float R2 = 7500.0;   // R2 = 7.5k ohm...

// Scaling factor for the voltage divider (R1 + R2) / R2
const float SCALING_FACTOR = (R1 + R2) / R2;  // Should be 5.0

// Calibration factor based on comparison with multimeter reading
const float CALIBRATION_FACTOR = 1.122;  // You can adjust this if necessary


//for current
#define CURRENT_SENSOR_PIN 34  // GPIO 34 (ADC1)

const float ACS712_OFFSET_VOLTAGE = 2.335;
const float ACS712_SENSITIVITY = 0.100;  // 100mV per amp

const int NUM_READINGS = 100;  // Number of samples for averaging


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  dht.begin();


  // Defined in thingProperties.h
  initProperties();

  // Connecting to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  analogReadResolution(12);  // Set ADC resolution to 12-bit (it is default for ESP32...)
}

void loop() 
{
  ArduinoCloud.update();
  // Your code here 
  dhtSensorRead();
  float curr=currentt();
  current=curr;
  float measuredVoltage=volt();
  voltage=measuredVoltage;
  Serial.println();
}


void onLedChange()  {
  if(led==1) digitalWrite(2,HIGH);
  else digitalWrite(2,LOW);
}


void dhtSensorRead(){
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  temp=t;
  humidity=h;
  // Serial.print("Temperature => ");
  Serial.print(t);
  Serial.print(", ");
  // Serial.print("Humidity => ");
  Serial.print(h);
  Serial.print(", ");
}

float volt(){
  int adcValue = analogRead(VOLTAGE_SENSOR_PIN);
  
  // Converting ADC value to voltage
  float vOut = (adcValue * ADC_VOLTAGE_REF) / ADC_RESOLUTION;

  // Calculate the actual input voltage using the voltage divider formula
  float measuredVoltage = vOut * SCALING_FACTOR;  // V_in = V_out * (R1 + R2) / R2
  
  // Apply the calibration factor if necessary
  measuredVoltage *= CALIBRATION_FACTOR;

  // Calculate percentage based on voltage
  float batteryPercentage = mapBatteryPercentage(measuredVoltage, minVoltage, maxVoltage);
  
  // Print the measured voltage to the Serial Monitor
  // Serial.print("Measured Voltage: ");
  Serial.print(measuredVoltage, 2);  // Print with 2 decimal places
  Serial.print(", ");
  // Serial.print("  Battery Percentage: ");
  Serial.print(batteryPercentage);

  return measuredVoltage;
}

float currentt(){
  
  long sum = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    sum += analogRead(CURRENT_SENSOR_PIN);
  }

  // Take the average
  int analogValue = sum / NUM_READINGS;

  // Convert to voltage
  float voltagee = (analogValue * ADC_VOLTAGE_REF) / ADC_RESOLUTION;

  // Calculate current
  float curr = abs((voltagee - ACS712_OFFSET_VOLTAGE) / ACS712_SENSITIVITY)-.025;
  // Serial.print("Current: ");
  Serial.print(curr, 3);
  Serial.print(", ");
  return curr;

}


// Function to map battery voltage to percentage (linear approximation)
float mapBatteryPercentage(float voltagee, float minVoltage, float maxVoltage) {
  if (voltagee >= maxVoltage) return 100.0;
  if (voltagee <= minVoltage) return 0.0;
  return ((voltagee - minVoltage)/(maxVoltage - minVoltage))*100.0;
}

