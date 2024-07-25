#ifndef BATTERYMONITORING_H
#define BATTERYMONITORING_H

#include <string>
#include <map>

// Constants
const float SOC_LOW_LIMIT = 20.0;
const float SOC_HIGH_LIMIT = 80.0;
const float TEMPERATURE_LOW_LIMIT = 0.0;
const float TEMPERATURE_HIGH_LIMIT = 45.0;
const float CHARGE_RATE_LOW_LIMIT = 0.0;
const float CHARGE_RATE_HIGH_LIMIT = 0.8;
const float TOLERANCE_PERCENTAGE = 5.0;

// Translations
extern std::map<std::string, std::map<std::string, std::string>> translations;

void initializeTranslations();

// Function declarations
std::string mapSocToMessage(float soc, const std::string& language);
std::string mapTemperatureToMessage(float temperature, const std::string& language);
std::string mapChargeRateToMessage(float chargeRate, const std::string& language);

std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, const std::string& language);

#endif // BATTERYMONITORING_H
