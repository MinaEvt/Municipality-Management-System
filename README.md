# Municipality-Management-System
<div align="center">
 
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/Paradigm-Object--Oriented-4CAF50?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)
 
<br/>
 
> **A console-based C++ application for managing municipal services, citizens, employees, and administrative operations — built with a strong focus on OOP principles.**
 
<br/>
 
</div>
 
---
 
## Table of Contents
 
- [About the Project](#about-the-project)
- [Features](#features)
- [OOP Concepts Used](#oop-concepts-used)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Team](#team)
 
---
 
## About the Project
 
The **Municipality Management System** is an academic project developed for the Object-Oriented Programming course. It simulates the core administrative functions of a local municipality office — including citizen registration, service requests, employee management, and record keeping.
 
The system is designed to demonstrate clean OOP architecture in C++, with a focus on code reusability, encapsulation, and maintainability.
 
---
 
## Features
 
| Module | Description |
|---|---|
| **Citizen Registry** | Register, update, and search citizens by ID or name |
| **Employee Management** | Add and manage municipality staff and their roles |
| **Service Requests** | Submit, track, and resolve administrative requests |
| **Reports** | Generate summaries of registered citizens and services |
| **File Persistence** | Save and load data from files between sessions |
 
---
 
## OOP Concepts Used
 
- **Encapsulation** — All class data is private with controlled access via getters/setters
- **Inheritance** — Base `Person` class extended by `Citizen` and `Employee`
- **Polymorphism** — Virtual methods for role-specific behavior
- **Abstraction** — Abstract interfaces for service handlers
- **Operator Overloading** — For comparison and output of objects
- **Templates** — Generic data structures for collections
- **File I/O** — Persistent storage using `fstream`
 
---
 
## Project Structure
 
```
municipality-system/
│
├── src/
│   ├── main.cpp
│   ├── Person.cpp / Person.h
│   ├── Citizen.cpp / Citizen.h
│   ├── Employee.cpp / Employee.h
│   ├── ServiceRequest.cpp / ServiceRequest.h
│   ├── Registry.cpp / Registry.h
│   └── Utils.cpp / Utils.h
│
├── data/
│   ├── citizens.txt
│   ├── employees.txt
│   └── requests.txt
│
├── docs/
│   └── class-diagram.png
│
├── README.md
└── Makefile
```
 
---
 
## Getting Started
 
### Prerequisites
 
- A C++17-compatible compiler (`g++`, `clang++`, or MSVC)
- `make` (optional, for Makefile builds)
 
### Build & Run
 
**Using g++ directly:**
```bash
g++ -std=c++17 -Wall src/*.cpp -o municipality
./municipality
```
 
**Using Makefile:**
```bash
make
./municipality
```
 
---
 
## Usage
 
On launch, the program presents an interactive menu:
 
```
╔══════════════════════════════════╗
║   Municipality Management System ║
╠══════════════════════════════════╣
║  [1] Citizen Registry            ║
║  [2] Employee Management         ║
║  [3] Service Requests            ║
║  [4] Generate Report             ║
║  [5] Exit                        ║
╚══════════════════════════════════╝
```
 
Navigate using number keys. All data is automatically saved on exit.
 
---
 
## Team
 
This project was developed by a team of three students as part of the **Object-Oriented Programming** course.
 
| Name | GitHub | Role |
|---|---|---|
| **Dimitar Ivanov** | @dimitar0315 | Role |
| **Mina Evtimova** | @MinaEvt | Role |
| **Miroslava Kostova** | @mirskk | Role |
 
---
 
## License
 
This project is licensed under the MIT License. See [`LICENSE`](LICENSE) for details.
 
---
 
<div align="center">
  <sub>Built for the OOP course · NBU, Sofia, Bulgaria</sub>
</div>
