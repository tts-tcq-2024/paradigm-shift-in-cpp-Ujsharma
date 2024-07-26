#include "BatteryMonitoring.h"
#include <map>

// Tolerance Calculation Function
float calculateTolerance(float limit) {
    return limit * TOLERANCE_PERCENTAGE / 100.0;
}

// Tolerance Values
const float SOC_TOLERANCE = calculateTolerance(SOC_HIGH_LIMIT);
const float TEMPERATURE_TOLERANCE = calculateTolerance(TEMPERATURE_HIGH_LIMIT);
const float CHARGE_RATE_TOLERANCE = calculateTolerance(CHARGE_RATE_HIGH_LIMIT);

// Helper function to get warning message based on the boundary conditions
std::string getWarningMessage(float value, float lowerLimit, float upperLimit, float tolerance, 
                              const std::string& lowerWarningKey, const std::string& upperWarningKey, 
                              const std::string& language) {
    if (value >= lowerLimit && value < lowerLimit + tolerance) {
        return translations[language][lowerWarningKey];
    }
    if (value >= upperLimit - tolerance && value <= upperLimit) {
        return translations[language][upperWarningKey];
    }
    return "";
}

std::string mapSocToMessage(float soc, const std::string& language) {
    return getWarningMessage(soc, SOC_LOW_LIMIT, SOC_HIGH_LIMIT, SOC_TOLERANCE, 
                             "low_soc_warning", "high_soc_warning", language);
}

std::string mapTemperatureToMessage(float temperature, const std::string& language) {
    return getWarningMessage(temperature, TEMPERATURE_LOW_LIMIT, TEMPERATURE_HIGH_LIMIT, 
                             TEMPERATURE_TOLERANCE, "low_temperature_warning", "high_temperature_warning", language);
}

std::string mapChargeRateToMessage(float chargeRate, const std::string& language) {
    return getWarningMessage(chargeRate, CHARGE_RATE_LOW_LIMIT, CHARGE_RATE_HIGH_LIMIT, 
                             CHARGE_RATE_TOLERANCE, "low_charge_rate_warning", "high_charge_rate_warning", language);
}
