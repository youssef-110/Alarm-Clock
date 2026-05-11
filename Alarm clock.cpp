#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

class AlarmSystem {
private:
    int targetHour, targetMinute;
    bool isActive;

    void triggerAlert() {
        system("color 0C"); // Futuristic Magenta alert
        cout << "\n\n  ###########################################" << endl;
        cout << "  # [!] ALERT: TIME PARAMETERS REACHED      #" << endl;
        cout << "  ###########################################" << endl;
        cout << "\n  >> PRESS ANY KEY TO STOP..." << endl;

        while (!_kbhit()) {
            // High-tech shimmering pulse
            for (int i = 0; i < 3; i++) {
                Beep(2000 + (i * 300), 50);
                Beep(3000 - (i * 300), 50);
            }
            // Rhythmic digital chirps
            for (int i = 0; i < 2; i++) { Beep(1500, 60); Sleep(20); }
            Sleep(200);
        }

        _getch(); 
        system("color 0A"); // Reset to Cyan
        cout << "\n  [SUCCESS] Alarm Stopped. System Standby." << endl;
            Beep(1000, 100);
            Beep(1500, 100);
            Beep(2500, 400);
        isActive = false;
    }

public:
    AlarmSystem() : targetHour(0), targetMinute(0), isActive(false) {}

    void configureSchedule() {
        system("cls");
        cout << "  ________________________________________________" << endl;
        cout << " |            ALARM CLOCK CLI (CLASS)             |" << endl;
        cout << " |________________________________________________|" << endl;
        cout << "\n  [CONFIG] Enter Target Hour (0-23): "; cin >> targetHour;
        cout << "  [CONFIG] Enter Target Minute (0-59): "; cin >> targetMinute;
        isActive = true;
        system("cls");
    }

    void monitor() {
        while (isActive) {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            cout << "\r  [ MONITORING ]  TIME: " << setfill('0') 
                 << setw(2) << ltm->tm_hour << ":" << setw(2) << ltm->tm_min << ":" << setw(2) << ltm->tm_sec 
                 << "  |  TARGET: " << setw(2) << targetHour << ":" << setw(2) << targetMinute << flush;

            if (ltm->tm_hour == targetHour && ltm->tm_min == targetMinute) {
                triggerAlert();
            }
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main() {
    system("color 0B"); 
    AlarmSystem scheduler;
    scheduler.configureSchedule();
    scheduler.monitor();
    return 0;
}