# Fingerprint Scanner Lock Tests

## Test 1: Fingerprint Enrollment

**Objective**: Verify that the system correctly enrolls a new fingerprint.

- **Given**: The system is powered on, and no fingerprint is currently stored in memory.
- **When**: The user attempts to enroll a new fingerprint by placing their finger on the scanner and following the enrollment process.
- **Then**: The fingerprint should be successfully stored in the system, and the system should provide feedback such as the LCD displaying or buzzers indicating the enrollment was successful.

---

## Test 2: Authorized Fingerprint Unlock

**Objective**: Ensure that an authorized fingerprint unlocks the lock mechanism.

- **Given**: A valid fingerprint has already been enrolled and stored in the system.
- **When**: The user places the authorized fingerprint on the scanner.
- **Then**: The system should recognize the fingerprint, and the lock mechanism should be triggered to open, which then activates the servo motor and displays on the LCD that the door has been unlocked.

---

## Test 3: Unauthorized Fingerprint Attempt

**Objective**: Confirm that an unauthorized fingerprint does not unlock the system.

- **Given**: The system has stored fingerprints but does not have the current user's fingerprint stored.
- **When**: A user places an unregistered fingerprint on the scanner.
- **Then**: The system should reject the fingerprint, providing feedback displaying that the fingerprint is unauthorized, and the lock mechanism should remain closed.

---

## Test 4: System Activation Based on Sensor Detection to Conserve Battery Life

**Objective**: Verify that the system turns on when a person approaches, using a sensor to conserve battery life, and turns off when no one is present.

- **Given**: The system is powered off to conserve battery, and a proximity sensor (e.g., an ultrasonic or PIR sensor) is installed on the device.
- **When**: The sensor detects a person approaching within a set range (e.g., 30 cm), the system should power on and be ready for fingerprint scanning.
- **Then**: The system should activate the fingerprint scanner and other components (e.g., LEDs) to allow the user to scan their fingerprint.
  
- **When**: The user leaves the sensor's detection range, or no one is detected for a specific timeout period (e.g., 10-15 seconds).
- **Then**: The system should automatically power down, turning off the fingerprint scanner and conserving battery life.
