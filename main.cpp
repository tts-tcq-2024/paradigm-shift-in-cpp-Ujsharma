#include "BatteryMonitoring.h"
#include "Language.h"
#include <iostream>
#include <cassert>

bool isBatteryOk(float temperature, float soc, float chargeRate, preferredLanguage lang) {
    auto [socMessage, temperatureMessage, chargeRateMessage] = monitorBattery(soc, temperature, chargeRate, lang);

    bool temperatureOk = temperature >= TEMPERATURE_LOW_LIMIT && temperature <= TEMPERATURE_HIGH_LIMIT;
    bool socOk = soc >= SOC_LOW_LIMIT && soc <= SOC_HIGH_LIMIT;
    bool chargeRateOk = chargeRate >= CHARGE_RATE_LOW_LIMIT && chargeRate <= CHARGE_RATE_HIGH_LIMIT;

    std::cout << Translate("Temperature", lang) << " " << (temperatureOk ? Translate("in", lang) : Translate("out", lang)) << ": " << temperatureMessage << std::endl;
    std::cout << Translate("State of Charge", lang) << " " << (socOk ? Translate("in", lang) : Translate("out", lang)) << ": " << socMessage << std::endl;
    std::cout << Translate("Charge Rate", lang) << " " << (chargeRateOk ? Translate("in", lang) : Translate("out", lang)) << ": " << chargeRateMessage << std::endl;

    return temperatureOk && socOk && chargeRateOk;
}

int main() {
    preferredLanguage lang = preferredLanguage::German;

    assert(isBatteryOk(25, 70, 0.7, lang) == true);
    assert(isBatteryOk(50, 85, 0, lang) == false);
    assert(isBatteryOk(0, 20, 0.8, lang) == false);
    assert(isBatteryOk(-1, 70, 0.5, lang) == false);
    assert(isBatteryOk(25, 10, 0.5, lang) == false);
    assert(isBatteryOk(25, 70, 0.9, lang) == false);
    assert(isBatteryOk(45, 80, 0.8, lang) == false);
    assert(isBatteryOk(0, 20, 0, lang) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
