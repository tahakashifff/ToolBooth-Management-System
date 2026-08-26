# Toll Booth Management System

A robust, console-based C++ application designed to simulate and manage multiple toll booths. This program tracks passing vehicles, calculates collected revenue, maintains a history of recent transactions, and generates comprehensive end-of-session audit reports.

## Features

* **Multiple Booth Management:** Dynamically create and manage any number of toll booths, each with a customizable location name.
* **Instant Keystroke Input:** Uses real-time keypress detection (`Y`, `N`, `ESC`, `BACKSPACE`) for quick and seamless vehicle logging without needing to press `Enter`.
* **Transaction History:** Maintains a rolling history of the last 10 transactions (paying or non-paying) for each booth, shifting older data out as new vehicles pass.
* **Session Auditing:** Generates a detailed final report upon exit, displaying total cars, paid/unpaid breakdowns, total revenue, transaction history, and an independent audit check for each booth.
* **Advanced Memory Management:** Utilizes dynamic memory allocation for location names and transaction histories, complete with deep copying (Copy Constructors) and safe destruction to prevent memory leaks.

## Object-Oriented Programming (OOP) Concepts Demonstrated

This project is a great showcase of several fundamental and advanced C++ OOP principles:
* **Classes and Objects:** Encapsulation of booth data and behaviors within the `TollBooth` class.
* **Dynamic Memory Allocation:** Use of `new` and `delete` for arrays and strings.
* **Constructors & Destructors:** Implementation of default, parameterized, and copy constructors, alongside memory-cleaning destructors.
* **Static Members:** Tracking the total number of booth objects created across the entire program.
* **Operator Overloading:** Overloading the `+` operator to theoretically combine the statistics of two separate toll booths.
* **Friend Functions:** Using `friend void auditBooth()` to securely access private data members for auditing purposes without exposing them publicly.

## Prerequisites

* A C++ Compiler (e.g., GCC, Clang, or MSVC).
* **Operating System:** Windows (The program relies on `<conio.h>` and `_getch()` for instant keystroke inputs, which is standard in Windows environments).

## Compilation and Execution

If you are using a standard command-line compiler like `g++`, navigate to the project directory and run:

```bash
# Compile the code
g++ main.cpp -o tollbooth

# Run the executable
tollbooth.exe
