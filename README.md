# 🎯 Ping Pong Turret – Arduino Project

A fun and precise **Arduino-powered automated turret** that detects, loads, and fires ping pong balls using servos, stepper motors, and a manual aiming system.

---

## 🚀 Overview

The Ping Pong Turret combines electronics and mechanics to deliver a functional launcher system:

- Rotary encoder for **manual aiming**
- Servo-based **ball loading**
- Stepper motor for **ball positioning**
- Dual DC motors for **controlled shooting**

---

## 🔧 Features

- 🏹 **Manual Aiming System** (Rotary Encoder + Servo)  
- ⚙️ **Motorized Firing Mechanism** (Stepper + DC Motors)  
- 🎯 **Precise Stepper Motor Control**  
- 🛠 **Servo-Based Ball Loading & Firing**  
- 🔄 **Adjustable Firing Speed & Direction**  

---

## 📦 Components Used

| Component                          | Quantity    |
|-----------------------------------|-------------|
| Arduino Board (Uno/Nano)          | 1           |
| Servo Motors (SG90/MG995)         | 2           |
| Stepper Motor (28BYJ-48) + ULN2003| 1           |
| Rotary Encoder                    | 1           |
| Digital Potentiometer (with Button)| 1          |
| DC Motors for Shooting            | 2           |
| Power Supply (Battery Pack)       | 1           |
| Wires & Connectors                | As needed   |

---

## 🏗️ Circuit Connections

### Stepper Motor (28BYJ-48 + ULN2003 Driver)

- IN1 → D8  
- IN2 → D10  
- IN3 → D9  
- IN4 → D11  

### Servo Motors

- Aiming Servo → D6  
- Loader Servo → D7  

### Rotary Encoder

- CLK → A0  
- DT → A1  

### Digital Potentiometer Button

- SW → A2  

### DC Motors for Shooting

- Motor 1 → D2 & D3  
- Motor 2 → D4 & D5  

---

## 🎮 Controls & Functionality

### 1️⃣ Manual Aiming

- Turn the **rotary encoder** left/right to adjust turret aim  
- Angle is displayed via the **Serial Monitor**

### 2️⃣ Shooting Sequence

- Press the **potentiometer button** to initiate the firing sequence:
  - Stepper motor rotates to load a ball
  - Firing motors engage
  - Servo pushes ball into the launcher
  - Stepper returns to reload position
  - Repeats 3× for burst fire

---

## ⚙️ How to Upload & Run

1. Install **Arduino IDE** and required libraries:
   - `Stepper.h`
   - `Servo.h`
2. Connect your Arduino via USB
3. Upload the sketch
4. Power motors separately (recommended)
5. Use the encoder to aim, and press the button to shoot!

---

## 🛠 Code Breakdown

- `Stepper` → Ball positioning  
- `Servo` → Aiming & loader movement  
- `DC Motors` → Firing mechanism  
- `Rotary Encoder` → Manual aim control  
- `Potentiometer Button` → Initiates firing sequence  

---

## 📜 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

Feel free to fork, improve, and submit pull requests. Contributions are welcome!

---

> 🚀 **Built with Arduino for fun & precision!** 🏹
