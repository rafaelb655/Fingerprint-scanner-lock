 **Major Moving Parts**
   * **Motor/servo Mechanism**: This is a physical mechanism responsible for locking and unlocking the door. it will activiate a deadbolt mechanism
   * **Microcontroller Unit**: Arduino Uno for core processing that handles fingerprint data procesing and communication with other components. it also manages power consumption and handles the inputs from external interfaces
   * **Fingerprint Sensor**: Scans and reads user's fingerprint, it is responisble for authenticating the user by comparing the scanned data to a stored database of authorized fingerprints. optical finerscanner will be used
   * **Power Supply**: This will power the finger sensor, microcontroller, motor, and any other components such as LED lights and screen. 12v 4000 mAh Li-ion battery

**Priorities and Dependencies**
   * **High Priority Tasks**

     * Fingerprint scanning and comparison
     * Actuating the deadbolt lock and unlock mechanism
     * Power management and ensuring lock functionality without connectivity
       
   * **Medium Priority Tasks**
     * Log data and finger print storage funnctionality
       
   * **Low Priority Tasks**
     * Aesthetic design for housing
  
   * **Dependencies**
     *  Fingerprint sensor requires a reliable connection with the microcontroller. The system cannot operate without this functioning.
     *  Motor needs the micorcontroller to send control signals for locking and unlocking
     *  The power supply is depended on by the motor and microcontroller for uninterrupted power to maintain the locks functionnality

 **Design approaches for major moving parts**    
   * **Fingerscanner**: the optical sensor fingerscanner is affordable and must water and dust-resistant since it will be used in outdoor enviroments
   * **Microcontroller unit**: Arduino microcontroller so that it will be able to communicate with all the components and allow the fingerscanner to operate accordingly
   * **Motor/servo Mechanism**: high-torque servo capable of reliably moving the deadbolt which requires more torque than usual. should be quick and reliable, with low-energy consumption to maxamize battery life
   * **Power Supply**: rechargable 12v 4000mAh Li-ion battery for long periods of operation. ensure power supply is sufficient to drive both the motor and the microcontroller.
   * **User Interface**: Implement a minimalistic interface, like an LED indicator

 **Major Components Selection**
   * **Servo Motor**: MG996R Servo Motor
   * **Power Supply**: 12V 4000mAh 18650 lithium ion DC 12.6V super rechargeable battery pack
   * **Microcontroller**: Arduino Mega
   * **User Interface**: 16x2 LCD
   * **Fingerprint Sensor**: R307 Optical Fingerprint Module
   * **Door Lock**: Door Latch Sliding Lock
