#include "BatteryMonitoring.h"

std::map<std::string, std::map<std::string, std::string>> translations;

void initializeTranslations() {
    translations["en"]["low_soc_warning"] = "Warning: Approaching discharge";
    translations["en"]["high_soc_warning"] = "Warning: Approaching charge-peak";
    translations["en"]["low_temperature_warning"] = "Warning: Approaching low temperature";
    translations["en"]["high_temperature_warning"] = "Warning: Approaching temperature peak";
    translations["en"]["low_charge_rate_warning"] = "Warning: Approaching low charge rate";
    translations["en"]["high_charge_rate_warning"] = "Warning: Approaching charge rate";
    
    translations["de"]["low_soc_warning"] = "Warnung: Batterie nähert sich der Entladung";
    translations["de"]["high_soc_warning"] = "Warnung: Batterie nähert sich dem Ladehöchstwert";
    translations["de"]["low_temperature_warning"] = "Warnung: Batterie nähert sich der niedrigen Temperatur";
    translations["de"]["high_temperature_warning"] = "Warnung: Batterie nähert sich dem Temperaturhöchstwert";
    translations["de"]["low_charge_rate_warning"] = "Warnung: Batterie nähert sich der niedrigen Laderate";
    translations["de"]["high_charge_rate_warning"] = "Warnung: Batterie nähert sich der Laderate";
}

float calculateTolerance(float limit) {
    return limit * TOLERANCE_PERCENTAGE / 100.0;
}

float SOC_TOLERANCE = calculateTolerance(SOC_HIGH_LIMIT);
float TEMPERATURE_TOLERANCE = calculateTolerance(TEMPERATURE_HIGH_LIMIT);
float CHARGE_RATE_TOLERANCE = calculateTolerance(CHARGE_RATE_HIGH_LIMIT);

std::string mapSocToMessage(float soc, const std::string& language) {
    if (SOC_LOW_LIMIT <= soc && soc < SOC_LOW_LIMIT + SOC_TOLERANCE) {
        return translations[language]["low_soc_warning"];
    }
    if (SOC_HIGH_LIMIT - SOC_TOLERANCE <= soc && soc <= SOC_HIGH_LIMIT) {
        return translations[language]["high_soc_warning"];
    }
    return "";
}

std::string mapTemperatureToMessage(float temperature, const std::string& language) {
    if (TEMPERATURE_LOW_LIMIT <= temperature && temperature < TEMPERATURE_LOW_LIMIT + TEMPERATURE_TOLERANCE) {
        return translations[language]["low_temperature_warning"];
    }
    if (TEMPERATURE_HIGH_LIMIT - TEMPERATURE_TOLERANCE <= temperature && temperature <= TEMPERATURE_HIGH_LIMIT) {
        return translations[language]["high_temperature_warning"];
    }
    return "";
}

std::string mapChargeRateToMessage(float chargeRate, const std::string& language) {
    if (CHARGE_RATE_LOW_LIMIT <= chargeRate && chargeRate < CHARGE_RATE_LOW_LIMIT + CHARGE_RATE_TOLERANCE) {
        return translations[language]["low_charge_rate_warning"];
    }
    if (CHARGE_RATE_HIGH_LIMIT - CHARGE_RATE_TOLERANCE <= chargeRate && chargeRate <= CHARGE_RATE_HIGH_LIMIT) {
        return translations[language]["high_charge_rate_warning"];
    }
    return "";
}

std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, const std::string& language) {
    std::string socMessage = mapSocToMessage(soc, language);
    std::string temperatureMessage = mapTemperatureToMessage(temperature, language);
    std::string chargeRateMessage = mapChargeRateToMessage(chargeRate, language);
    return std::make_tuple(socMessage, temperatureMessage, chargeRateMessage);
}
