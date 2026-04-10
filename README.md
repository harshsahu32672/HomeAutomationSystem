# 🏠 Home Automation System (ESP32 + GSM + Android App)

This project is a **smart home automation system** that allows control of electrical appliances like **Light, Fan, and Bulb** using both an **Android app (WiFi)** and **GSM (SMS)**.

It is designed to work in both scenarios:
- 🌐 With internet (via mobile app)
- 📡 Without internet (via SMS using GSM module)

---

## 🧠 Overview
- Built using **ESP32 microcontroller**
- Dual control system: **WiFi (Blynk App) + GSM (SIM900L)**
- Controls multiple home appliances using **relay module**
- Provides real-time control and remote accessibility

---

## ⚙️ Features
- 📱 Android app control using Blynk  
- 📩 SMS-based control using GSM module  
- 🔌 Control Light, Fan, and Bulb  
- 🌍 Works from anywhere (internet or GSM network)  
- ⚡ Real-time response and switching  

---

## 🛠️ Components Used
- ESP32  
- SIM900L GSM Module  
- Relay Module (3 Channel)  
- Power Supply (5V & 4V for GSM)  
- Connecting Wires  

---

## 🔌 Pin Configuration

| Device | ESP32 Pin |
|--------|----------|
| Light  | GPIO 5   |
| Fan    | GPIO 18  |
| Bulb   | GPIO 19  |
| GSM TX | GPIO 16  |
| GSM RX | GPIO 17  |

---

## 📱 Mobile App Control

Using **Blynk App**:

- Button V0 → Light  
- Button V1 → Fan  
- Button V2 → Bulb  

---

## 📩 SMS Commands

| Command     | Action        |
|------------|--------------|
| LIGHT ON   | Turn ON Light |
| LIGHT OFF  | Turn OFF Light|
| FAN ON     | Turn ON Fan   |
| FAN OFF    | Turn OFF Fan  |
| BULB ON    | Turn ON Bulb  |
| BULB OFF   | Turn OFF Bulb |

---

## ⚙️ Working Principle
1. User sends command via **mobile app or SMS**
2. ESP32 processes the command
3. Relay module switches the appliance
4. GSM sends confirmation SMS (if used)

---

## 📷 Project Preview

<img width="1919" height="1075" alt="Screenshot 2026-04-10 204212" src="https://github.com/user-attachments/assets/fd5e85ed-656e-4980-baaf-8679f1e7f7db" />


---

## 🚀 Future Improvements
- Energy monitoring system  
- Timer-based automation  
- Custom Android app  

---

---

⭐ *This project demonstrates practical implementation of IoT, embedded systems, and wireless communication.*
