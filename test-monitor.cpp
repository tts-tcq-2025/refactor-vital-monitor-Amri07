#include <gtest/gtest.h>
#include "./monitor.h"

TEST_Temperature_out_of_Range(Monitor, TemperatureOutOfRange) {
    EXPECT_FALSE(vitalsOk(103, 80, 95));
    EXPECT_FALSE(vitalsOk(94, 80, 95));
}

TEST_PulseRate_out_of_Range(Monitor, PulseRateOutOfRange) {
    EXPECT_FALSE(vitalsOk(98, 59, 95));
    EXPECT_FALSE(vitalsOk(98, 101, 95));
}

TEST_Spo2_out_of_Range(Monitor, Spo2OutOfRange) {
    EXPECT_FALSE(vitalsOk(98, 80, 89));
}

TEST_all_vitals_in_range(Monitor, AllVitalsOk) {
    EXPECT_TRUE(vitalsOk(98.1, 70, 98));
    EXPECT_TRUE(vitalsOk(95, 60, 90));
    EXPECT_TRUE(vitalsOk(102, 100, 90));
}



