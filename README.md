# PROJECT RUBI — Rubik’s Cube Solving Robot

<div align="center">

### Autonomous High-Speed Rubik’s Cube Solving Robot

A robotics and embedded systems project integrating computer vision, distributed control systems, algorithmic solving, and mechanical automation.

Achieved a final optimized solve time of **~1.2 seconds**

[View Solve Demo](https://youtube.com/shorts/CW7xnSQYXt8?si=d9477-OS-hAz1O44)

</div>

---

## Table of Contents

* [About The Project](#about-the-project)
* [Features](#features)
* [System Architecture](#system-architecture)
* [Built With](#built-with)
* [Components](#components)
* [Getting Started](#getting-started)
* [Installation](#installation)
* [Usage](#usage)
* [Engineering Challenges & Iteration](#engineering-challenges--iteration)
* [CAD Files](#cad-files)
* [Roadmap](#roadmap)
* [Contributing](#contributing)

---

## About The Project

PROJECT RUBI is an autonomous Rubik’s Cube solving robot designed to demonstrate the integration of:

* Computer Vision
* Embedded Systems
* Robotics
* Mechanical Design
* Real-Time Motor Control
* Algorithmic Problem Solving
* Automation

The system captures cube colors using a Pixy2 camera, reconstructs the cube state, computes an optimized solution using Kociemba’s two-phase algorithm, and executes precise mechanical rotations through six independently controlled stepper motors.

The project was fully CAD designed, prototyped, assembled, tuned, and iterated, resulting in a final optimized solve time of approximately **~1.2 seconds**.

This project showcases:

* Iterative engineering
* Tuning and optimization
* Multidisciplinary integration
* Creative problem-solving with limited hardware

---

## Features

* Autonomous 3x3 Rubik’s Cube solving
* ~1.2 second optimized solve time
* Distributed Raspberry Pi + ESP32 architecture
* Pixy2-based RGB color detection
* Kociemba two-phase solving algorithm
* UART communication pipeline
* Flask-based control interface
* Fully custom CAD-designed structure
* Stepper motor face rotation system
* Real-time solve execution
* Cube scrambling functionality
* Modular software architecture

---

## System Architecture

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

### Raspberry Pi Responsibilities

* Vision processing
* RGB extraction
* Cube state reconstruction
* Running Kociemba algorithm
* Flask web interface
* Serial communication with ESP32

### ESP32 Responsibilities

* UART communication handling
* Parsing cube move strings
* Deterministic motor control
* Stepper timing execution
* Face rotation coordination

---

## Built With

### Hardware

* Raspberry Pi
* ESP32
* Pixy2 Camera
* NEMA17 Stepper Motors
* Stepper Motor Drivers
* 3D Printed Components
* 12V Power Supply

### Software

* Python
* Flask
* OpenCV
* Kociemba
* PySerial
* C++
* Arduino Framework
* UART Serial Communication

---

## Components

* Raspberry Pi
* ESP32
* Pixy2 Camera
* 6x Stepper Motors
* Stepper Drivers
* Bearings
* Couplers
* Power Supply
* Screws / Fasteners
* 3D Printed Parts
* Wiring & Connectors

---

## Getting Started

### 1. Clone the Repository

```
git clone https://github.com/ejaduwari/PROJECT-RUBI-Rubiks-Cube-Solving-Robot.git
cd PROJECT-RUBI-Rubiks-Cube-Solving-Robot
```

### 2. Raspberry Pi Setup

```
ssh pi@192.168.x.xxx
cd ~/rubi
```

### 3. Create Virtual Environment

```
python3 -m venv rubi-env
source rubi-env/bin/activate
```

### 4. Install Dependencies

```
pip install pyserial kociemba opencv-python flask
```

### 5. Pixy2 Setup

Resources:

* https://docs.pixycam.com/wiki/doku.php
* https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:video_api
* https://github.com/charmedlabs/pixy2/tree/master/src/host/libpixyusb2_examples/get_rgb_demo

### Important Notes

* Tile positions were manually calibrated using PixyMon2
* RGB values were extracted from fixed coordinates
* Lighting significantly affects detection quality

---

## Installation

### Python Environment

```
pip install pyserial kociemba opencv-python flask
```

### ESP32 Firmware

Upload via Arduino IDE or PlatformIO

⚠️ Disconnect 12V motor power while flashing

### UART Communication

Example device:

```
/dev/serial0
```

### Flask Interface

```
python app.py
```

---

## Usage

### Starting the System

```
source rubi-env/bin/activate
python rubi_main.py
```

### Cube Scanning

* Pixy2 captures RGB values
* Single camera required manual repositioning
* Introduced alignment challenges but improved engineering adaptability

### Future Improvement

* Dual-camera setup
* Faster scans
* Better consistency
* Easier calibration

### Solve Execution

1. Kociemba generates solution
2. Raspberry Pi sends moves via UART
3. ESP32 parses commands
4. Motors execute rotations
5. Cube is solved

---

## Engineering Challenges & Iteration

### Mechanical Challenges

* Cube slipping
* Misalignment
* Stepper synchronization
* Structural rigidity

### Vision Challenges

* Lighting inconsistency
* RGB instability
* Red/orange differentiation
* White/yellow detection

### Software Challenges

* UART synchronization
* Timing optimization
* Move parsing reliability
* Dependency conflicts

### RGB Optimization

```
gb_delta = G - B
```

Improved:

* Red vs Orange
* Yellow vs White

### Performance Progression

**Initial:** ~4 seconds
**Final:** ~1.2 seconds

---

## CAD Files

Includes:

* Chassis
* Motor mounts
* Cube holders
* Structural assemblies

### Recommended Workflow

1. Download files
2. 3D print
3. Gather hardware
4. Assemble frame
5. Install electronics
6. Wire system
7. Upload firmware
8. Configure Pi
9. Test & calibrate

---

## Roadmap

* [x] Autonomous solving
* [x] UART pipeline
* [x] Pixy2 RGB detection
* [x] Flask interface
* [x] Kociemba integration
* [x] High-speed optimization
* [ ] Dual-camera system
* [ ] Auto lighting calibration
* [ ] Improved enclosure
* [ ] Full assembly guide
* [ ] Wireless control
* [ ] Multi-cube support

---

## Contributing

Contributions are welcome.

Areas:

* Vision improvements
* Motor control optimization
* CAD redesign
* Firmware tuning
* Solve-time optimization
* UI improvements
* Documentation

### Steps

1. Fork the repo
2. Create branch

```
git checkout -b feature/AmazingFeature
```

3. Commit

```
git commit -m "Add AmazingFeature"
```

4. Push

```
git push origin feature/AmazingFeature
```

5. Open Pull Request

---

<div align="center">

### PROJECT RUBI

Robotics • Embedded Systems • Automation • Computer Vision

Built with engineering curiosity, persistence, and iteration.

</div>
