# Obstacle Avoidance & Auto Parking System

## ![WhatsApp Image 2025-08-08 at 18 44 21_33975ec5](https://github.com/user-attachments/assets/0fa71fdd-db06-4578-bdd8-fc298f14263c) [WhatsApp Image 2025-08-08 at 18 44 21_c7622443](https://github.com/user-attachments/assets/4595b351-10c1-48d4-8c79-7f83617e5702)

verview
The **Obstacle Avoidance & Auto Parking System** is an embedded systems project designed to autonomously detect and avoid obstacles while also providing automatic parking capabilities.  
The system is powered by an **ESP32 microcontroller** and utilizes ultrasonic sensors for distance measurement, motor drivers for motion control, and additional electronic components to enhance safety and functionality.

This project was developed as part of an **Embedded Systems** course to demonstrate practical applications of sensor integration, motor control, and real-time decision-making in robotics.

---

## Contributors
- **Mahmoud Reda** – ID: 2205139  
- **Diaa Ahmed** – ID: 2205103  
- **Mohamed Mohab** – ID: 2205083  
- **Mohamed Mostafa** – ID: 2205051  
- **Youssef Mahmoud** – ID: 2205071  

Prepared for: **Dr. Mohamed Elhabrook**  
Additional review: **Daniel Gallego**  

---

## Features
- 🚗 **Obstacle Avoidance** — detects and steers away from obstacles using ultrasonic sensors  
- 🅿️ **Automatic Parking** — assists or performs full parking maneuvers  
- 🔔 **Buzzer Alarm** — alerts when obstacles are detected in close proximity  
- ⚡ **Low-Power Operation** — efficient energy management via voltage regulators  
- 🔌 **Manual Control Switch** — for safe on/off operation  

---

## Components Used
| Component                          | Qty | Price (EGP) | Total (EGP) |
|------------------------------------|-----|-------------|-------------|
| Ultrasonic Sensor                  | 3   | 135         | 405         |
| Battery Case Holder                | 1   | 30          | 30          |
| Li-ion Battery 3.7V                 | 4   | 50          | 200         |
| Positive Voltage Regulator 5V-7805 | 1   | 6.5         | 6.5         |
| L293D Motor Driver IC               | 1   | 17          | 17          |
| Robot Platform 2WD                  | 1   | 110         | 110         |
| NodeMCU ESP32-S (38-pin)            | 1   | 425         | 425         |
| Buzzer Alarm                        | 1   | 25          | 25          |
| ON/OFF Switch                       | 1   | 2.5         | 2.5         |
| Breadboard                          | 1   | 40          | 40          |
| LED                                 | 2   | 0.5         | 1           |
| Jumper Wires                        | 35  | 0.75        | 26.25       |
| **Total**                           |     |             | **1288.25** |

---

## System Architecture
1. **Sensor Layer** — Ultrasonic sensors measure distances in multiple directions.  
2. **Control Layer** — ESP32 processes data and decides actions based on obstacle detection and parking requirements.  
3. **Actuation Layer** — L293D motor driver controls the motors to adjust movement and steering.  
4. **Feedback Layer** — Buzzer and LED indicators provide status updates to the user.

---

## How It Works
1. **Power On** — System initializes sensors and motors.  
2. **Obstacle Detection** — Ultrasonic sensors continuously monitor distances.  
3. **Decision Making** — Microcontroller decides to move forward, stop, turn, or park.  
4. **Parking Mode** — Engages when the system detects a parking slot within range.  
5. **Alerts** — Buzzer and LEDs signal proximity warnings.  

---

## Requirements
- NodeMCU ESP32-S board
- Arduino IDE or PlatformIO
- ESP32 board drivers
- Basic electronics knowledge for wiring and soldering

---

## Setup Instructions
1. **Clone the Repository**
   ```bash
   git clone https://github.com/<your-username>/Obstacle-Avoidance-and-Auto-Parking-System.git
   cd Obstacle-Avoidance-and-Auto-Parking-System
