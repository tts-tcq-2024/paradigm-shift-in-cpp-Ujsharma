#include "BatteryMonitoring.h"
#include <map>

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

void setLanguage(const std::string& language) {
    if (translations.find(language) == translations.end()) {
        // Handle error: language not initialized
    }
}
