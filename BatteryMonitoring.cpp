#include "BatteryMonitoring.h"
#include <tuple>

std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, const std::string& language) {
    std::string socMessage = mapSocToMessage(soc, language);
    std::string temperatureMessage = mapTemperatureToMessage(temperature, language);
    std::string chargeRateMessage = mapChargeRateToMessage(chargeRate, language);
    return std::make_tuple(socMessage, temperatureMessage, chargeRateMessage);
}
