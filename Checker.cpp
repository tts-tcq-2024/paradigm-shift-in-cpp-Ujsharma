#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

const float TEMPERATURE_LOWER_LIMIT = 0.0;
const float TEMPERATURE_UPPER_LIMIT = 45.0;
const float SOC_LOWER_LIMIT = 20.0;
const float SOC_UPPER_LIMIT = 80.0;
const float CHARGE_RATE_UPPER_LIMIT = 0.8;

// Warning tolerance (5% of upper limit)
const float TEMPERATURE_WARNING_TOLERANCE = 0.05 * TEMPERATURE_UPPER_LIMIT;
const float SOC_WARNING_TOLERANCE = 0.05 * SOC_UPPER_LIMIT;
const float CHARGE_RATE_WARNING_TOLERANCE = 0.05 * CHARGE_RATE_UPPER_LIMIT;

bool isWithinRange(float value, float lowerLimit, float upperLimit, const string& parameterName) {
    if (value < lowerLimit || value > upperLimit) {
        cout << parameterName << " out of range!\n";
        return false;
    }
    return true;
}

void checkWarnings(float value, float lowerLimit, float upperLimit, float warningTolerance, const string& lowerWarningMsg, const string& upperWarningMsg) {
    if (value <= lowerLimit + warningTolerance) {
        cout << lowerWarningMsg << "\n";
    }
    if (value >= upperLimit - warningTolerance) {
        cout << upperWarningMsg << "\n";
    }
}

bool temperaturecheck(float temperature) {
    bool inRange = isWithinRange(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, "Temperature");
    if (inRange) {
        checkWarnings(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_WARNING_TOLERANCE, "Warning: Approaching temperature discharge!", "Warning: Approaching temperature peak!");
    }
    return inRange;
}

bool soccheck(float soc) {
    bool inRange = isWithinRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge");
    if (inRange) {
        checkWarnings(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, SOC_WARNING_TOLERANCE, "Warning: Approaching SoC discharge!", "Warning: Approaching SoC peak!");
    }
    return inRange;
}

bool chargeRatecheck(float chargeRate) {
    bool inRange = isWithinRange(chargeRate, 0, CHARGE_RATE_UPPER_LIMIT, "Charge Rate");
    if (inRange && chargeRate >= CHARGE_RATE_UPPER_LIMIT - CHARGE_RATE_WARNING_TOLERANCE) {
        cout << "Warning: Approaching charge rate peak!\n";
    }
    return inRange;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempIsOk = temperaturecheck(temperature);
    bool socIsOk = soccheck(soc);
    bool chargeRateIsOk = chargeRatecheck(chargeRate);
    return tempIsOk && socIsOk && chargeRateIsOk;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
    assert(batteryIsOk(1, 21, 0.75) == true); // Added tests to trigger warnings
}
