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

struct VitalCheck {
    bool ok;
    const char* message;
};

bool vitalsOk(float temperature, float pulseRate, float spo2) {
    VitalCheck checks[] = {
        {isTemperatureOk(temperature), "Temperature is critical!"},
        {isPulseRateOk(pulseRate), "Pulse Rate is out of range!"},
        {isSpo2Ok(spo2), "Oxygen Saturation out of range!"}
    };
    for (const auto& check : checks) {
        if (!check.ok) {
            alert(check.message);
            return false;
        }
    }
    return true;
}
