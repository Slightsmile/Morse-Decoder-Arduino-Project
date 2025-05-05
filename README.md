# 📡 IR-Based Morse Code Sender and Decoder

A low-cost and real-time embedded system to **send Morse code using an IR remote**, decode the infrared (IR) signals via an IR receiver, and display the translated text using an I2C LCD display. This project uses **Arduino Uno** and explores innovative applications of IR communication technology in education and low-bandwidth signaling.

---

## 📘 Project Overview

This system captures button presses from an IR remote, interprets them as Morse code (short press = dot, long press = dash), converts them into readable text, and displays the output on a 16x2 I2C LCD. It is designed to demonstrate how traditional Morse code can be implemented using modern embedded systems.

---

## 🎯 Objectives

- ✅ Use an IR remote to send Morse code
- ✅ Decode the IR signals using an IR receiver
- ✅ Translate Morse code into alphanumeric characters
- ✅ Display the result in real-time on an LCD
- ✅ Build a compact, low-cost, and educational system

---

## 🧰 Components Used

| Component         | Description                                        |
|------------------|----------------------------------------------------|
| Arduino Uno       | Microcontroller for signal decoding and display   |
| IR Remote         | Sends IR signals representing Morse code          |
| IR Receiver       | Receives IR signals from the remote               |
| I2C 16x2 LCD      | Displays the decoded message                      |
| Breadboard        | For circuit prototyping                           |
| Jumper Wires      | Connections between components                    |
| 5V DC Adapter     | Powers Arduino Uno and components externally      |

---

## ⚙️ System Architecture

### Hardware Flow:
``IR Remote → IR Receiver → Arduino Uno → I2C Display``

### Software Modules:
1. **Signal Decoding**: Reads button signal duration from IR remote to detect dots and dashes
2. **Morse Translator**: Maps Morse code to alphanumeric characters
3. **LCD Display Driver**: Outputs decoded message in real time

---

## 📷 Connection
![Screenshot 2025-05-05 114521](https://github.com/user-attachments/assets/b6cb72a3-d6fb-4281-bf78-666b745765fd)

---

## 🛠️ Implementation Steps

1. **Connect Hardware**:
   - IR Receiver to digital pin of Arduino
   - I2C LCD to A4 (SDA) and A5 (SCL)
2. **Develop Software**:
   - Detect signal durations from IR remote
   - Classify as dot or dash based on time
   - Map Morse to characters
   - Display on LCD
3. **Upload Code**:
   - Use Arduino IDE with necessary libraries
4. **Test & Debug**:
   - Press IR remote buttons in Morse sequences
   - Verify decoded text on display

---

## 🧩 Limitations

- IR signal may not work well in bright environments
- Short transmission range
- Limited by IR remote button press precision

---

## 📄 Project Report

For full technical details and performance results, see the [project report](IR-Based-Morse-Code-Sender.pdf).

---

## 📬 Authors

- Project developed by a student team as part of a learning activity in Arduino-based security systems.

---
> Developed as a part of the Embedded System and IOT Lab project at Daffodil International University.
