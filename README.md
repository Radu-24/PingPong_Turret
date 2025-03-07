🎯 Ping Pong Turret - Arduino Project

🚀 Overview

The Ping Pong Turret is an Arduino-powered automated turret designed to detect and launch ping pong balls at a target. It integrates a stepper motor, servo motors, and rotating shooter mechanism to ensure precision aiming and controlled firing. A rotary encoder is used for manual control of aiming, while a digital potentiometer button initiates the shooting sequence.

🔧 Features

🏹 Manual Aiming System (Rotary Encoder + Servo)

⚙️ Motorized Firing Mechanism (Stepper + DC motors)

🎯 Precise Stepper Motor Control

🛠 Servo-Based Ball Loading & Firing

🔄 Adjustable Firing Speed & Direction

📦 Components Used

Component

Quantity

Arduino Board (Uno/Nano)

1

Servo Motors (SG90/MG995)

2

Stepper Motor (28BYJ-48) + ULN2003 Driver

1

Rotary Encoder

1

Digital Potentiometer (with Button)

1

DC Motors for Shooting

2

Power Supply (Battery Pack)

1

Wires & Connectors

As needed

🏗️ Circuit Connections

Stepper Motor (28BYJ-48) + ULN2003 Driver

IN1 → D8

IN2 → D10

IN3 → D9

IN4 → D11

Servo Motors

Aiming Servo → D6

Rotating Loader Servo → D7

Rotary Encoder

CLK → A0

DT  → A1

Digital Potentiometer Button

SW  → A2

Shooting DC Motors

Motor 1: D2 & D3

Motor 2: D4 & D5

🎮 Controls & Functionality

1️⃣ Manual Aiming (Rotary Encoder + Servo)

Turning the rotary encoder left/right adjusts the turret's aim angle.

Angle is displayed in the Serial Monitor.

2️⃣ Shooting Mechanism

Pressing the digital potentiometer button initiates a ball loading & firing sequence.

The stepper motor rotates to load a ball.

The firing motors engage for precise shooting.

A servo moves to push the ball into the launcher.

The stepper rotates back for reloading.

This process repeats 3 times for rapid firing.

🚀 How to Upload & Run

Install the Arduino IDE & required libraries:

Stepper.h

Servo.h

Connect the Arduino to your PC via USB.

Upload the Sketch to the board.

Power the motors separately (recommended).

Use the encoder to aim & press the potentiometer button to shoot!

🛠️ Code Breakdown

Stepper Motor Control → Adjusts ball positioning before shooting.

Servo Control → Aims & rotates the loading system.

DC Motors → Engages the shooting mechanism.

Rotary Encoder → Provides manual aiming functionality.

Digital Potentiometer Button → Triggers the full shooting sequence.

📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

🤝 Contributing

Want to improve this project? Feel free to fork, modify, and submit pull requests!

🚀 Built with Arduino for fun & precision! 🏹

