#include <iostream>
#include <cassert>
#include "BatteryMonitoring.h"

void testBatteryMonitoring() {
    // Initialize translations
    initializeTranslations();

    // Test inputs
    float soc = 22.0;
    float temperature = 46.0;
    float chargeRate = 0.81;
    std::string language = "de";

    // Expected outputs in German
    std::string expectedSocMessage = "Warnung: Batterie nähert sich der Entladung";
    std::string expectedTemperatureMessage = "Warnung: Batterie nähert sich dem Temperaturhöchstwert";
    std::string expectedChargeRateMessage = "Warnung: Batterie nähert sich der Laderate";

    // Call the function
    auto [socMessage, temperatureMessage, chargeRateMessage] = monitorBattery(soc, temperature, chargeRate, language);

    // Assert the outputs
    assert(socMessage == expectedSocMessage);
    assert(temperatureMessage == expectedTemperatureMessage);
    assert(chargeRateMessage == expectedChargeRateMessage);

    // Repeat the test for English
    language = "en";
    expectedSocMessage = "Warning: Approaching discharge";
    expectedTemperatureMessage = "Warning: Approaching temperature peak";
    expectedChargeRateMessage = "Warning: Approaching charge rate";

    std::tie(socMessage, temperatureMessage, chargeRateMessage) = monitorBattery(soc, temperature, chargeRate, language);

    assert(socMessage == expectedSocMessage);
    assert(temperatureMessage == expectedTemperatureMessage);
    assert(chargeRateMessage == expectedChargeRateMessage);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testBatteryMonitoring();
    return 0;
}
