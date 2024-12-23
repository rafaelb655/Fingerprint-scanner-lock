#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define pins for SoftwareSerial communication
SoftwareSerial mySerial(2, 3); // RX, TX

// Create an instance of the fingerprint sensor
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// Create an instance of the LCD (change the address if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27 for a 16x2 LCD

// Create an instance of the Servo
Servo doorServo;
const int servoPin = 9; // Define the pin the servo is connected to

// Define the PIR sensor pin
const int pirPin = 4; // Connect the PIR output to pin 4
bool systemActive = false;
unsigned long lastMotionDetected = 0;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Initialize the LCD and Servo
  lcd.init();
  lcd.clear();
  lcd.noBacklight(); // Start with the LCD backlight off
  doorServo.attach(servoPin);
  doorServo.write(0); // Set the servo to the locked position (0 degrees)

  // Initialize PIR sensor
  pinMode(pirPin, INPUT);

  // Initialize the fingerprint sensor but only enable it when motion is detected
  Serial.println("System initialized. Waiting for motion...");
}

void loop() {
  // Check if the PIR sensor detects motion
  if (digitalRead(pirPin) == HIGH) {
    if (!systemActive) {
      // Turn on the system
      systemActive = true;
      lcd.backlight(); // Turn on the LCD backlight
      lcd.clear();
      lcd.print("System Activated");
      delay(1000);
      
      // Initialize the fingerprint sensor
      finger.begin(57600);

      // Check if the fingerprint sensor is connected properly
      if (finger.verifyPassword()) {
        Serial.println("Fingerprint sensor detected!");
      } else {
        Serial.println("Fingerprint sensor not found, please check wiring.");
        lcd.clear();
        lcd.print("Sensor Error!");
        while (1); // Stop the program if the sensor is not found
      }
    }
    lastMotionDetected = millis(); // Update last motion detected time
  }

  // If system is active and no motion detected for 5 seconds, deactivate the system
  if (systemActive && millis() - lastMotionDetected > 5000) {
    systemActive = false;
    lcd.clear();
    lcd.print("System Deactivated");
    delay(1000);
    lcd.clear();
    lcd.noBacklight(); // Turn off the LCD backlight
    Serial.println("System is now off");
    return; // End the loop if system is off
  }

  // If the system is active, proceed with fingerprint operations
  if (systemActive) {
    // Print and display message to indicate waiting for a fingerprint scan
    Serial.println("Waiting for Scan...");
    lcd.clear();
    lcd.print("Waiting for Scan...");
    
    // Check for a fingerprint
    int result = finger.getImage();
    
    // If a finger is detected, process the fingerprint
    if (result == FINGERPRINT_OK) {
      result = finger.image2Tz();
      if (result != FINGERPRINT_OK) {
        Serial.println("Error capturing fingerprint image.");
        lcd.clear();
        lcd.print("Capture Error!");
        return;
      }

      result = finger.fingerSearch();
      if (result == FINGERPRINT_OK) {
        Serial.println("Door Unlocked, Welcome!");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Door Unlocked,");
        lcd.setCursor(4, 1);
        lcd.print("Welcome!");

        // Turn the servo to unlock position (45 degrees)
        doorServo.write(45);
        
        // Delay for 3 seconds to keep the door unlocked
        delay(3000);
        
        // Return the servo to the locked position (0 degrees)
        doorServo.write(0);
      } else {
        Serial.println("Unrecognized Fingerprint");
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Unrecognized");
        lcd.setCursor(5, 1);
        lcd.print("Scan!");
        delay(4000);
      }
    }
    // Delay before the next scan attempt
    delay(1000); // Wait for 1 second before the next loop iteration
  }
}
