#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

bool isPulseRateOk(float pulseRate) {
    return pulseRate >= 60 && pulseRate <= 100;
}

bool isSpo2Ok(float spo2) {
    return spo2 >= 90;
}

void alert(const char* message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool vitalsOk(float temperature, float pulseRate, float spo2) {
    if (!isTemperatureOk(temperature)) {
        alert("Temperature is critical!");
        return false;
    }
    if (!isPulseRateOk(pulseRate)) {
        alert("Pulse Rate is out of range!");
        return false;
    }
    if (!isSpo2Ok(spo2)) {
        alert("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}
