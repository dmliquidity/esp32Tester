#include <Arduino.h>

// Define the LED pin
const int ledPin = 4;  // Change this if your LED is connected to a different pin
// Define the PWM channel (0-15 are valid channels)
const int pwmChannel = 0;

// Define the PWM frequency in Hz
const int freq = 5000;

// Define the PWM resolution in bits (1-16 bits)
// 8-bit resolution gives us values from 0-255
const int pwmResolution = 8;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
    // Configure PWM properties
  ledcSetup(pwmChannel, freq, pwmResolution);
  
  // Attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, pwmChannel);

  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}

void loop() {
  // Send a message to the serial monitor
  Serial.println("LED on, flashing...");

  // Set the PWM signal to half brightness
  // 255 / 2 = 127.5 (approximately 128 for integer value)
  ledcWrite(pwmChannel, 5);

  // Wait for 2 seconds
  delay(2000);

  // Turn the LED off by setting the duty cycle to 0
  ledcWrite(pwmChannel, 0);

  // Wait for 2 seconds
  delay(2000);
}