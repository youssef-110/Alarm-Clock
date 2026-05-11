# Alarm System CLI (C++)

A console-based alarm clock application built in C++ that continuously monitors system time and triggers a real-time alert when a user-defined target time is reached.

---

# Overview

This project simulates a digital alarm system using low-level C++ and Windows-specific libraries. It demonstrates real-time system monitoring, multithreading concepts, and interactive console UI behavior.

The alarm runs in the terminal and triggers an audio-visual alert when the set time is reached.

---

# Features

- User-defined alarm time (hour and minute)
- Real-time system clock monitoring
- Console-based UI with live time updates
- Sound alerts using system Beep
- Keyboard-controlled alarm stop (any key press)
- Dynamic terminal color changes for alert state
- Clean object-oriented design (class-based structure)

---

# Tech Stack

- C++
- Windows API (`windows.h`)
- Console I/O (`iostream`)
- Time functions (`ctime`)
- Threading (`thread`, `chrono`)
- Keyboard input detection (`conio.h`)

---

# How It Works

1. User sets target hour and minute
2. Program enters monitoring mode
3. System clock is checked every second
4. When current time matches target time:
   - Visual alert is triggered
   - Sound alarm starts (Beep sequence)
5. User can stop alarm by pressing any key

---

# Code Overview

## Alarm System Class

The main logic is handled inside the `AlarmSystem` class:

```cpp
class AlarmSystem {
private:
    int targetHour, targetMinute;
    bool isActive;

    void triggerAlert();
public:
    AlarmSystem();
    void configureSchedule();
    void monitor();
};
```

---

## Time Configuration

User sets the alarm time:

```cpp
void configureSchedule() {
    system("cls");
    cout << "Enter Target Hour (0-23): ";
    cin >> targetHour;

    cout << "Enter Target Minute (0-59): ";
    cin >> targetMinute;

    isActive = true;
}
```

---

## Real-Time Monitoring

Continuously checks system time:

```cpp
void monitor() {
    while (isActive) {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        cout << "\rTIME: "
             << setw(2) << ltm->tm_hour << ":"
             << setw(2) << ltm->tm_min << ":"
             << setw(2) << ltm->tm_sec << flush;

        if (ltm->tm_hour == targetHour &&
            ltm->tm_min == targetMinute) {
            triggerAlert();
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}
```

---

## Alarm Trigger System

When time matches, the alert system activates:

```cpp
void triggerAlert() {
    system("color 0C");

    cout << "\nALERT: TIME REACHED!" << endl;

    while (!_kbhit()) {
        Beep(2000, 50);
        Beep(3000, 50);
        Sleep(200);
    }

    _getch();
    system("color 0A");
    isActive = false;
}
```

---

## Main Function

Entry point:

```cpp
int main() {
    system("color 0B");

    AlarmSystem scheduler;
    scheduler.configureSchedule();
    scheduler.monitor();

    return 0;
}
```

---

# Example Output

```text
TIME: 14:32:10 | TARGET: 14:33
```

When triggered:

```text
ALERT: TIME PARAMETERS REACHED
PRESS ANY KEY TO STOP...
```

---

# Requirements

- Windows OS (uses Windows-specific headers)
- C++ compiler (MinGW / MSVC)

---

# Compilation

## Using g++

```bash
g++ main.cpp -o alarm
```

## Run

```bash
alarm.exe
```

---

# Concepts Demonstrated

- Object-Oriented Programming (OOP)
- Real-time system monitoring
- Console UI manipulation
- Multithreading (`sleep_for`)
- Event-driven input handling
- Windows system programming

---

# Future Improvements

- Multiple alarms support
- GUI version using Qt or WinAPI
- Persistent alarm storage (file/database)
- Snooze functionality
- Cross-platform version (Linux/macOS)
- Music file playback instead of Beep

---

# License

Educational use only.
