#ifndef BATTERYMONITORING_H
#define BATTERYMONITORING_H

#include <string>
#include <tuple>
#include "Language.h"

// Constants
extern const float SOC_LOW_LIMIT;
extern const float SOC_HIGH_LIMIT;
extern const float TEMPERATURE_LOW_LIMIT;
extern const float TEMPERATURE_HIGH_LIMIT;
extern const float CHARGE_RATE_LOW_LIMIT;
extern const float CHARGE_RATE_HIGH_LIMIT;
extern const float TOLERANCE_PERCENTAGE;

// Function declarations for warning handling
std::string mapSocToMessage(float soc, preferredLanguage lang);
std::string mapTemperatureToMessage(float temperature, preferredLanguage lang);
std::string mapChargeRateToMessage(float chargeRate, preferredLanguage lang);
std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, preferredLanguage lang);

// Function declarations for battery checks
bool isTemperatureOk(float temperature, preferredLanguage lang);
bool isSocOk(float soc, preferredLanguage lang);
bool isChargeRateOk(float chargeRate, preferredLanguage lang);
bool isBatteryOk(float temperature, float soc, float chargeRate, preferredLanguage lang);

// Function declarations for language transitions
std::string Translate(const std::string& key, preferredLanguage lang);
void initializeTranslations();
void setLanguage(preferredLanguage lang);

#endif // BATTERYMONITORING_H
