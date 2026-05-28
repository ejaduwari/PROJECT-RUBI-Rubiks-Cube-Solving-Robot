# 🧠 PROJECT RUBI — Rubik’s Cube Solving Robot

### ⚡ Autonomous High-Speed Rubik’s Cube Solving Robot

A robotics and embedded systems project integrating computer vision, distributed control systems, algorithmic solving, and mechanical automation.

🚀 Achieved a final optimized solve time of **~1.2 seconds**

🎥 [View Solve Demo](https://youtube.com/shorts/CW7xnSQYXt8?si=d9477-OS-hAz1O44)

---

### 🛠️ Tech Stack
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge\&logo=python\&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge\&logo=cplusplus\&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge\&logo=Arduino\&logoColor=white)
![Flask](https://img.shields.io/badge/Flask-000000?style=for-the-badge\&logo=flask)
![OpenCV](https://img.shields.io/badge/OpenCV-5C3EE8?style=for-the-badge\&logo=opencv\&logoColor=white)
![Raspberry Pi](https://img.shields.io/badge/Raspberry%20Pi-A22846?style=for-the-badge\&logo=raspberrypi\&logoColor=white)
![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge\&logo=espressif\&logoColor=white)

---

## 📑 Table of Contents

* [📖 About The Project](#-about-the-project)
* [✨ Features](#-features)
* [🏗️ System Architecture](#-system-architecture)
* [🧰 Built With](#-built-with)
* [🔩 Components](#-components)
* [🚀 Getting Started](#-getting-started)
* [⚙️ Installation](#-installation)
* [🎮 Usage](#-usage)
* [🧪 Engineering Challenges & Iteration](#-engineering-challenges--iteration)
* [📐 CAD Files](#-cad-files)
* [🗺️ Roadmap](#-roadmap)
* [⚙️ Software & Control Deep Dive](#️-software--control-deep-dive)

---

## 📖 About The Project

PROJECT RUBI is an autonomous Rubik’s Cube solving robot designed to demonstrate the integration of:

* 👁️ Computer Vision
* 🔌 Embedded Systems
* 🤖 Robotics
* 🧩 Mechanical Design
* ⚙️ Real-Time Motor Control
* 🧠 Algorithmic Problem Solving
* 🔄 Automation

The system captures cube colors using a Pixy2 camera, reconstructs the cube state, computes an optimized solution using Kociemba’s two-phase algorithm, and executes precise rotations using six independently controlled stepper motors.

⏱️ Final optimized solve time: **~1.2 seconds**

---

## ✨ Features

* 🤖 Autonomous 3x3 solving
* ⚡ ~1.2 second solve time
* 🧠 Distributed Raspberry Pi + ESP32 system
* 🎨 Pixy2 RGB detection
* 🔍 Kociemba solving algorithm
* 🔌 UART communication pipeline
* 🌐 Flask control interface
* 🧱 Custom CAD mechanical system
* 🔄 Real-time solve execution
* 🔀 Cube scrambling
* 🧩 Modular architecture

---

## 🏗️ System Architecture

```
Pixy2 Camera
      ↓
RGB Extraction
      ↓
Cube State Reconstruction
      ↓
Kociemba Solver
      ↓
Move String Generation
      ↓
UART Communication
      ↓
ESP32 Firmware
      ↓
Stepper Motor Execution
```

---

## 🧰 Built With

### 🔩 Hardware

* Raspberry Pi
* ESP32
* Pixy2 Camera
* NEMA17 Stepper Motors
* Motor Drivers
* 3D Printed Parts
* 12V Power Supply

### 💻 Software

* Python
* Flask
* OpenCV
* Kociemba
* PySerial
* C++
* Arduino Framework

---

## 🔩 Components

* Raspberry Pi
* ESP32
* Pixy2 Camera
* 6x Stepper Motors
* Drivers
* Bearings
* Couplers
* Power Supply
* Fasteners
* 3D Printed Parts
* Wiring

---

## 🚀 Getting Started

```
git clone https://github.com/ejaduwari/PROJECT-RUBI-Rubiks-Cube-Solving-Robot.git
cd PROJECT-RUBI-Rubiks-Cube-Solving-Robot
```

---

## ⚙️ Installation

```
pip install pyserial kociemba opencv-python flask
```

---

## 🎮 Usage

```
source rubi-env/bin/activate
python rubi_main.py
```

---

## 🧪 Engineering Challenges & Iteration

### 🔩 Mechanical

* Cube slipping
* Misalignment
* Synchronization

### 👁️ Vision

* Lighting inconsistency
* RGB instability

### 💻 Software

* UART timing
* Parsing reliability

### 📈 Performance

* Initial: ~4s
* Final: **~1.2s**

---

## 📐 CAD Files

Includes chassis, mounts, and structural components.

---

## ✅ Recommended Workflow

To run and test the full RUBI system reliably:

1. **Power Setup**

   * Ensure Raspberry Pi and ESP32 are powered
   * Disconnect 12V motor supply during flashing or debugging

2. **Start Raspberry Pi Program**

   ```
   source rubi-env/bin/activate
   python rubi_main.py
   ```

3. **Verify Camera Output**

   * Confirm Pixy2 is returning RGB values
   * Ensure tile detection is consistent

4. **Generate Cube State**

   * Validate cube string format before solving

5. **Run Solver**

   * Kociemba generates move sequence

6. **Send Moves via UART**

   * Confirm ESP32 receives full string

7. **Monitor Execution**

   * Observe parsed moves in Serial Monitor
   * Verify correct motor actuation

8. **Reconnect Motor Power**

   * Execute full solve

---

## ✅ Recommended Workflow 2

Download files -
3D print -
Gather hardware -
Assemble frame -
Install electronics -
Wire system -
Upload firmware -
Configure Pi -
Test & calibrate 

---

## Contributing

Contributions are welcome. Some Ares worth improving upon are:

Vision improvements,
Motor control optimization,
CAD redesign,
Firmware tuning,
Solve-time optimization,
UI improvements,
Documentation

---

# ⚙️ RUBI — Software & Control System Deep Dive

---

## 🧠 ESP32 Motor Control Architecture

The ESP32 is responsible for translating high-level cube-solving instructions into precise physical motor movements across six stepper motors.

### 📡 Input: Move String from Raspberry Pi

The ESP32 receives a serialized move string over UART, generated by the Kociemba solving algorithm running on the Raspberry Pi.

Example:

```
D2 U' R2 U F2 D2 U' R2 U' B' L2 R'
```

Each token represents a cube move:

* **Face Identifier**

  * `F` (Front), `B` (Back), `L` (Left), `R` (Right), `U` (Up), `D` (Down)

* **Turn Type**

  * `2` → 180° turn (double turn)
  * No number → 90° turn

* **Direction**

  * `'` (prime) → counterclockwise
  * none → clockwise

---

### 🔍 Parsing Pipeline

#### 1. `parseMoves()`

* Splits the input string by whitespace
* Produces an array of individual move tokens

  * Example: `"D2"`, `"U'"`, `"R2"`

---

#### 2. `processMove(move)`

Each token is analyzed in three stages:

**Face Detection**

* First character determines which motor to activate

**Turn Detection**

* Checks for `2` → sets turn count = 2
* Otherwise defaults to 1

> Note:
>
> * 3 clockwise turns = 1 counterclockwise turn
> * Redundant rotations are eliminated in optimal solutions

**Direction Detection**

* `'` present → counterclockwise
* otherwise → clockwise

---

### ⚙️ Motor Execution Layer

Each move is mapped to a dedicated motor function:

```
face_U(clockwise, turns)
face_R(clockwise, turns)
...
```

Parameters:

* `clockwise` → boolean
* `turns` → integer (1 or 2)

---

### 🔄 Execution Flow Summary

```
UART Input → parseMoves → processMove → face_X() → Stepper Control
```

---

### ⚠️ Important Hardware Note

> Always disconnect 12V motor power before flashing the ESP32
> to prevent unintended motor activation or electrical damage.

---

## 🍓 Raspberry Pi Control System

The Raspberry Pi acts as the **central controller** of the RUBI system.

### 🎯 Objective

* Generate cube solutions using Kociemba
* Send move sequences to ESP32
* Serve as integration point for vision + control

---

### ⚙️ System Setup

* OS: Raspbian
* Access: SSH
* Language: Python 3

Libraries:

* `kociemba` → solver
* `pyserial` → UART communication

---

### 🧪 Kociemba Solver Testing

#### ✔️ Valid Cube Input

```
UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB
```

---

### 🧾 Python Test Flow

1. Define cube string
2. Run Kociemba solver
3. Send solution via UART
4. Print solution for verification

---

### 📡 UART Communication

* Interface: `/dev/serial0`
* Direction: Raspberry Pi → ESP32

---

## 👁️ Computer Vision & RGB Processing

RUBI uses a **Pixy2 camera + C++ pipeline** for real-time color detection.

---

### 🎯 Tile Detection Strategy

* Pixy2 captures **3 faces simultaneously**
* Tile coordinates are manually calibrated and hardcoded

Each tile is sampled using:

```
video.getRGB(x, y)
```

---

## 🎨 RGB Classification System

### 🔴 Red vs 🟠 Orange

```
gb_delta = G - B
```

* Orange → positive
* Red → negative

---

### 🟡 Yellow vs ⚪ White

* `gb_delta > 60` → Yellow
* small `gb_delta` → White

---

### 🔵 Blue vs 🟢 Green

* Blue → high B
* Green → high G

---

## 🔗 Full System Pipeline

```
Pixy2 → RGB Extraction → Color Classification
      → Cube String → Kociemba Solver
      → UART → ESP32 → Motors → Solved Cube
```

---

## 🚀 System Status

✅ Solver working
✅ UART communication verified
✅ ESP32 parsing + motor control functional
🚧 Vision integration ongoing

---

## 🔐 RUBI Pi Details

* Username: `rubi`
* Password: `rubiPi`
* IP: `192.168.166.220` *(find yours)*

---

## 🧠 Key Insight

This system works because of **clear abstraction layers**:

* Vision → perception
* Pi → computation
* ESP32 → execution

Each layer is independent but tightly coordinated — enabling both **high speed** and **high reliability**.
