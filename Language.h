// BatteryMonitoring.h
#ifndef BATTERY_MONITORING_H
#define BATTERY_MONITORING_H

#include <string>

enum class preferredLanguage { English, German };

std::string getWarningMessage(float value, float lowLimit, float highLimit, preferredLanguage lang);
std::string getLowLimitMessage(preferredLanguage lang);
std::string getHighLimitMessage(preferredLanguage lang);
std::string getNormalRangeMessage(preferredLanguage lang);

#endif // BATTERY_MONITORING_H
