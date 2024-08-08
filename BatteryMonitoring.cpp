#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>
#include "Translation.h"

using namespace std;

preferredLanguage selectedLanguage = preferredLanguage::English;

// Function to print the range status of a parameter
void displayRangeStatus(const string& parameter, bool withinRange) {
    string status = withinRange ? "in" : "out";
    cout << translateMessage(parameter, selectedLanguage) << ": "
         << translateMessage(status, selectedLanguage) << endl;
}

// Function to check if a value is within specified limits
bool isWithinRange(float value, float lowerLimit, float upperLimit) {
    return (value >= lowerLimit && value <= upperLimit);
}

// Function to check if temperature is within the allowed range
bool checkTemperature(float temperature) {
    return isWithinRange(temperature, 0, 45);
}

// Function to check if State of Charge (SOC) is within the allowed range
bool checkSoc(float soc) {
    return isWithinRange(soc, 20, 80);
}

// Function to check if charge rate is within the allowed range
bool checkChargeRate(float chargeRate) {
    return (chargeRate <= 0.8);
}

// Function to verify if all battery parameters are within the specified ranges
bool verifyBatteryStatus(float temperature, float soc, float chargeRate) {
    vector<tuple<string, bool>> parameters = {
        {"Temperature", checkTemperature(temperature)},
        {"State of Charge", checkSoc(soc)},
        {"Charge Rate", checkChargeRate(chargeRate)}
    };

    bool allParametersValid = true;

    for (const auto& param : parameters) {
        const string& parameterName = get<0>(param);
        bool isValid = get<1>(param);
        displayRangeStatus(parameterName, isValid);
        allParametersValid = allParametersValid && isValid;
    }

    return allParametersValid;
}

int main() {
    selectedLanguage = preferredLanguage::German;

    assert(verifyBatteryStatus(25, 70, 0.7) == true);
    assert(verifyBatteryStatus(50, 85, 0) == false);
    assert(verifyBatteryStatus(0, 20, 0.8) == false);
    assert(verifyBatteryStatus(-1, 70, 0.5) == false);
    assert(verifyBatteryStatus(25, 10, 0.5) == false);
    assert(verifyBatteryStatus(25, 70, 0.9) == false);
    assert(verifyBatteryStatus(45, 80, 0.8) == false);
    assert(verifyBatteryStatus(0, 20, 0) == true);

    cout << "All tests passed!" << endl;
    return 0;
}
