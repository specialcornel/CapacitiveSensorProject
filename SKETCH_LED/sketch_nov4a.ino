#include <CapacitiveSensor.h>

// Define sensor and LED pin constants
CapacitiveSensor sensor = CapacitiveSensor(4, 2);  // 2MΩ resistor between pins 4 & 2
const int ledPin = 9;  // Pin for the LED
const int threshold = 200;  // Adjust this value based on your sensor readings

void setup() {
  Serial.begin(115200);  // Begin Serial Monitor
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  // Measure capacitance
  long measurement = sensor.capacitiveSensor(30);  // Take 30 samples for accuracy
  Serial.print("Measurement: ");
  Serial.println(measurement);
  // Turn LED on if measurement exceeds the threshold
  if (measurement > threshold) {
    digitalWrite(ledPin, HIGH);
    //Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW);
    //Serial.println("LED OFF");
  }

  delay(10);  // Small delay for readability
}


