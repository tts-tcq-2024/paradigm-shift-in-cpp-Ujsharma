#include "BatteryMonitoring.h"
#include "Language.h"
#include <iostream>
#include <cassert>

bool isBatteryOk(float temperature, float soc, float chargeRate) {
    auto [socMessage, temperatureMessage, chargeRateMessage] = monitorBattery(soc, temperature, chargeRate, messageLanguage);

    bool temperatureOk = temperature >= TEMPERATURE_LOW_LIMIT && temperature <= TEMPERATURE_HIGH_LIMIT;
    bool socOk = soc >= SOC_LOW_LIMIT && soc <= SOC_HIGH_LIMIT;
    bool chargeRateOk = chargeRate >= CHARGE_RATE_LOW_LIMIT && chargeRate <= CHARGE_RATE_HIGH_LIMIT;

    std::cout << Translate("Temperature", messageLanguage) << " " << (temperatureOk ? Translate("in", messageLanguage) : Translate("out", messageLanguage)) << ": " << temperatureMessage << std::endl;
    std::cout << Translate("State of Charge", messageLanguage) << " " << (socOk ? Translate("in", messageLanguage) : Translate("out", messageLanguage)) << ": " << socMessage << std::endl;
    std::cout << Translate("Charge Rate", messageLanguage) << " " << (chargeRateOk ? Translate("in", messageLanguage) : Translate("out", messageLanguage)) << ": " << chargeRateMessage << std::endl;

    return temperatureOk && socOk && chargeRateOk;
}

int main() {
    setLanguage(preferredLanguage::German);

    assert(isBatteryOk(25, 70, 0.7) == true);
    assert(isBatteryOk(50, 85, 0) == false);
    assert(isBatteryOk(0, 20, 0.8) == false);
    assert(isBatteryOk(-1, 70, 0.5) == false);
    assert(isBatteryOk(25, 10, 0.5) == false);
    assert(isBatteryOk(25, 70, 0.9) == false);
    assert(isBatteryOk(45, 80, 0.8) == false);
    assert(isBatteryOk(0, 20, 0) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
