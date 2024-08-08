#include "BatteryMonitoring.h"
#include <map>
#include <vector>

// Tolerance Calculation Function
float calculateTolerance(float limit) {
    return limit * TOLERANCE_PERCENTAGE / 100.0;
}

// Tolerance Values
const float SOC_TOLERANCE = calculateTolerance(SOC_HIGH_LIMIT);
const float TEMPERATURE_TOLERANCE = calculateTolerance(TEMPERATURE_HIGH_LIMIT);
const float CHARGE_RATE_TOLERANCE = calculateTolerance(CHARGE_RATE_HIGH_LIMIT);

// Boundary structure
struct Boundary {
    float lowerLimit;
    float upperLimit;
    std::string lowerWarningKey;
    std::string upperWarningKey;
};

std::string getWarningMessage(float value, const Boundary& boundary, float tolerance, const std::string& language) {
    if (value >= boundary.lowerLimit && value < boundary.lowerLimit + tolerance) {
        return translations[language][boundary.lowerWarningKey];
    }
    if (value >= boundary.upperLimit - tolerance && value <= boundary.upperLimit) {
        return translations[language][boundary.upperWarningKey];
    }
    return "";
}

std::string mapSocToMessage(float soc, const std::string& language) {
    Boundary socBoundary = {SOC_LOW_LIMIT, SOC_HIGH_LIMIT, "low_soc_warning", "high_soc_warning"};
    return getWarningMessage(soc, socBoundary, SOC_TOLERANCE, language);
}

std::string mapTemperatureToMessage(float temperature, const std::string& language) {
    Boundary tempBoundary = {TEMPERATURE_LOW_LIMIT, TEMPERATURE_HIGH_LIMIT, "low_temperature_warning", "high_temperature_warning"};
    return getWarningMessage(temperature, tempBoundary, TEMPERATURE_TOLERANCE, language);
}

std::string mapChargeRateToMessage(float chargeRate, const std::string& language) {
    Boundary chargeBoundary = {CHARGE_RATE_LOW_LIMIT, CHARGE_RATE_HIGH_LIMIT, "low_charge_rate_warning", "high_charge_rate_warning"};
    return getWarningMessage(chargeRate, chargeBoundary, CHARGE_RATE_TOLERANCE, language);
}

int main() {
    messageLanguage = preferredLanguage::German;

    assert(isBatteryOk(25, 70, 0.7) == true);
    assert(isBatteryOk(50, 85, 0) == false);
    assert(isBatteryOk(0, 20, 0.8) == false);
    assert(isBatteryOk(-1, 70, 0.5) == false);
    assert(isBatteryOk(25, 10, 0.5) == false);
    assert(isBatteryOk(25, 70, 0.9) == false);
    assert(isBatteryOk(45, 80, 0.8) == false);
    assert(isBatteryOk(0, 20, 0) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
