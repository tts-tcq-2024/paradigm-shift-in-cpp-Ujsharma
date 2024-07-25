#include "BatteryMonitoring.h"

// Initialize translations
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

// Tolerance Calculation Function
float calculateTolerance(float limit) {
    return limit * TOLERANCE_PERCENTAGE / 100.0;
}

// Tolerance Values (Global or within functions)
float SOC_TOLERANCE = calculateTolerance(SOC_HIGH_LIMIT);
float TEMPERATURE_TOLERANCE = calculateTolerance(TEMPERATURE_HIGH_LIMIT);
float CHARGE_RATE_TOLERANCE = calculateTolerance(CHARGE_RATE_HIGH_LIMIT);

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

std::tuple<std::string, std::string, std::string> monitorBattery(float soc, float temperature, float chargeRate, const std::string& language) {
    std::string socMessage = mapSocToMessage(soc, language);
    std::string temperatureMessage = mapTemperatureToMessage(temperature, language);
    std::string chargeRateMessage = mapChargeRateToMessage(chargeRate, language);
    return std::make_tuple(socMessage, temperatureMessage, chargeRateMessage);
}
