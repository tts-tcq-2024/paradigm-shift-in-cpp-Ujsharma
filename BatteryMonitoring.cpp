#include "BatteryMonitoring.h"
#include "Language.h"
#include <iostream>
#include <string>

// Constants
const float SOC_LOW_LIMIT = 20.0;
const float SOC_HIGH_LIMIT = 80.0;
const float TEMPERATURE_LOW_LIMIT = 0.0;
const float TEMPERATURE_HIGH_LIMIT = 45.0;
const float CHARGE_RATE_LOW_LIMIT = 0.0;
const float CHARGE_RATE_HIGH_LIMIT = 0.8;
const float TOLERANCE_PERCENTAGE = 5.0;

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

std::string getWarningMessage(float value, const Boundary& boundary, float tolerance, preferredLanguage lang) {
    if (value >= boundary.lowerLimit && value < boundary.lowerLimit + tolerance) {
        return Translate(boundary.lowerWarningKey, lang);
    }
    if (value >= boundary.upperLimit - tolerance && value <= boundary.upperLimit) {
        return Translate(boundary.upperWarningKey, lang);
    }
    return "";
}

std::string mapSocToMessage(float soc, preferredLanguage lang) {
    Boundary socBoundary = {SOC_LOW_LIMIT, SOC_HIGH_LIMIT, "low_soc_warning", "high_soc_warning"};
    return getWarningMessage(soc, socBoundary, SOC_TOLERANCE, lang);
}

std::string mapTemperatureToMessage(float temperature, preferredLanguage lang) {
    Boundary tempBoundary = {TEMPERATURE_LOW_LIMIT, TEMPERATURE_HIGH_LIMIT, "low_temperature_warning", "high_temperature_warning"};
    return getWarningMessage(temperature, tempBoundary, TEMPERATURE_TOLERANCE, lang);
}

std::string mapChargeRateToMessage(float chargeRate, preferredLanguage lang) {
    Boundary chargeBoundary = {CHARGE_RATE_LOW_LIMIT, CHARGE_RATE_HIGH_LIMIT, "low_charge_rate_warning", "high_charge_rate_warning"};
    return getWarningMessage(chargeRate, chargeBoundary, CHARGE_RATE_TOLERANCE, lang);
}

std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, preferredLanguage lang) {
    return std::make_tuple(mapSocToMessage(soc, lang), mapTemperatureToMessage(temperature, lang), mapChargeRateToMessage(chargeRate, lang));
}

bool isTemperatureOk(float temperature, preferredLanguage lang) {
    bool temperatureOk = temperature >= TEMPERATURE_LOW_LIMIT && temperature <= TEMPERATURE_HIGH_LIMIT;
    std::string temperatureMessage = mapTemperatureToMessage(temperature, lang);
    std::cout << Translate("Temperature", lang) << " " << (temperatureOk ? Translate("in", lang) : Translate("out", lang)) << ": " << temperatureMessage << std::endl;
    return temperatureOk;
}

bool isSocOk(float soc, preferredLanguage lang) {
    bool socOk = soc >= SOC_LOW_LIMIT && soc <= SOC_HIGH_LIMIT;
    std::string socMessage = mapSocToMessage(soc, lang);
    std::cout << Translate("State of Charge", lang) << " " << (socOk ? Translate("in", lang) : Translate("out", lang)) << ": " << socMessage << std::endl;
    return socOk;
}

bool isChargeRateOk(float chargeRate, preferredLanguage lang) {
    bool chargeRateOk = chargeRate >= CHARGE_RATE_LOW_LIMIT && chargeRate <= CHARGE_RATE_HIGH_LIMIT;
    std::string chargeRateMessage = mapChargeRateToMessage(chargeRate, lang);
    std::cout << Translate("Charge Rate", lang) << " " << (chargeRateOk ? Translate("in", lang) : Translate("out", lang)) << ": " << chargeRateMessage << std::endl;
    return chargeRateOk;
}

bool isBatteryOk(float temperature, float soc, float chargeRate, preferredLanguage lang) {
    bool temperatureOk = isTemperatureOk(temperature, lang);
    bool socOk = isSocOk(soc, lang);
    bool chargeRateOk = isChargeRateOk(chargeRate, lang);
    return temperatureOk && socOk && chargeRateOk;
}
