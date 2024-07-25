#ifndef BATTERYMONITORING_H
#define BATTERYMONITORING_H

#include <string>
#include <tuple>

// Constants
extern const float SOC_LOW_LIMIT;
extern const float SOC_HIGH_LIMIT;
extern const float TEMPERATURE_LOW_LIMIT;
extern const float TEMPERATURE_HIGH_LIMIT;
extern const float CHARGE_RATE_LOW_LIMIT;
extern const float CHARGE_RATE_HIGH_LIMIT;
extern const float TOLERANCE_PERCENTAGE;

// Function declarations for warning handling
std::string mapSocToMessage(float soc, const std::string& language);
std::string mapTemperatureToMessage(float temperature, const std::string& language);
std::string mapChargeRateToMessage(float chargeRate, const std::string& language);
std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, const std::string& language);

// Function declarations for language transitions
void initializeTranslations();
void setLanguage(const std::string& language);

#endif // BATTERYMONITORING_H
