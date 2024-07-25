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

bool temperaturecheck(float temperature) {
    if (temperature < TEMPERATURE_LOWER_LIMIT || temperature > TEMPERATURE_UPPER_LIMIT) {
        cout << "Temperature out of range!\n";
        return false;
    }
    if (temperature <= TEMPERATURE_LOWER_LIMIT + TEMPERATURE_WARNING_TOLERANCE) {
        cout << "Warning: Approaching temperature discharge!\n";
    }
    if (temperature >= TEMPERATURE_UPPER_LIMIT - TEMPERATURE_WARNING_TOLERANCE) {
        cout << "Warning: Approaching temperature peak!\n";
    }
    return true;
}

bool soccheck(float soc) {
    if (soc < SOC_LOWER_LIMIT || soc > SOC_UPPER_LIMIT) {
        cout << "State of Charge out of range!\n";
        return false;
    }
    if (soc <= SOC_LOWER_LIMIT + SOC_WARNING_TOLERANCE) {
        cout << "Warning: Approaching SoC discharge!\n";
    }
    if (soc >= SOC_UPPER_LIMIT - SOC_WARNING_TOLERANCE) {
        cout << "Warning: Approaching SoC peak!\n";
    }
    return true;
}

bool chargeRatecheck(float chargeRate) {
    if (chargeRate > CHARGE_RATE_UPPER_LIMIT) {
        cout << "Charge Rate out of range!\n";
        return false;
    }
    if (chargeRate >= CHARGE_RATE_UPPER_LIMIT - CHARGE_RATE_WARNING_TOLERANCE) {
        cout << "Warning: Approaching charge rate peak!\n";
    }
    return true;
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
