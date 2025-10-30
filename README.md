# Joc "Simon Says" cu ESP32

Acest proiect reprezintă implementarea unui joc de memorie tip **„Simon Says”**, în care jucătorul trebuie să reproducă o secvență de culori afișată de LED-uri.  
Proiectul a fost realizat în cadrul cursului **Informatică Aplicată**, având ca scop aprofundarea cunoștințelor despre microcontrolere și interacțiunea cu componente electronice simple.

---

## 🔧 Componente utilizate
- **ESP32** – microcontroller principal care gestionează logica jocului  
- **4 LED-uri** (roșu, verde, albastru, galben)  
- **4 rezistențe de 220Ω** – pentru limitarea curentului prin LED-uri  
- **4 butoane** – folosite de jucător pentru reproducerea secvenței  
- **Fire de conexiune (jumper wires)**  
- **Breadboard**

---

## ⚙️ Schema de conectare

| Componentă | Pin ESP32 | Descriere |
|-------------|-----------|-----------|
| LED roșu | GPIO 19 | Output |
| LED verde | GPIO 18 | Output |
| LED albastru | GPIO 17 | Output |
| LED galben | GPIO 16 | Output |
| Buton 1 | GPIO 21 | Input pull-up |
| Buton 2 | GPIO 23 | Input pull-up |
| Buton 3 | GPIO 26 | Input pull-up |
| Buton 4 | GPIO 27 | Input pull-up |

Fiecare LED este conectat în serie cu o rezistență de 220Ω.

---

## 💡 Descriere funcționare
La pornirea sistemului, ESP32 afișează o secvență de culori folosind LED-urile.  
Jucătorul trebuie să reproducă această secvență apăsând butoanele corespunzătoare.  
Dacă secvența este corectă, se adaugă o nouă culoare, iar jocul continuă.  
Dacă jucătorul greșește, jocul se resetează și se afișează mesajul **„Game Over”** în consolă.

---

## 💻 Limbaj și platformă
- C++ (Arduino)
- ESP32 DevKit

---

## 🚀 Rulare
1. Deschide proiectul în **Arduino IDE**.  
2. Selectează placa **ESP32 Dev Module**.  
3. Conectează ESP32-ul la PC și selectează portul corespunzător.  
4. Încarcă codul în microcontroller.  
5. Urmărește secvența de LED-uri și începe jocul!

---

## 🏫 Informații proiect
Proiect realizat de **Dragotoniu Ionuț-Constantin**

Facultatea de Electronică, Telecomunicații și Tehnologia Informației – UPB

An universitar 2024–2025
