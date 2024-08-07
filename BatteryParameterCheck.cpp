#include <iostream>
#include <vector>
#include <tuple>
#include "BatteryParameterCheck.h"
#include "Translation.h"

using namespace std;

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
    bool result = isWithinRange(temperature, 0, 45);
    cout << "Temperature Check: " << temperature << " -> " << (result ? "in range" : "out of range") << endl;
    return result;
}

// Function to check if State of Charge (SOC) is within the allowed range
bool checkSoc(float soc) {
    bool result = isWithinRange(soc, 20, 80);
    cout << "SOC Check: " << soc << " -> " << (result ? "in range" : "out of range") << endl;
    return result;
}

// Function to check if charge rate is within the allowed range
bool checkChargeRate(float chargeRate) {
    bool result = isWithinRange(chargeRate, 0, 0.8);
    cout << "Charge Rate Check: " << chargeRate << " -> " << (result ? "in range" : "out of range") << endl;
    return result;
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
