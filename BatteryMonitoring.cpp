#include <cassert>
#include <iostream>
#include "Translation.h"
#include "BatteryParameterCheck.h"

using namespace std;

// Function to dynamically change the language
void setLanguage(preferredLanguage lang) {
    selectedLanguage = lang;
}

int main() {
    setLanguage(preferredLanguage::German);

    // Test cases with different combinations of temperature, SOC, and charge rate
    assert(verifyBatteryStatus(25, 70, 0.7) == true); // All within range
    assert(verifyBatteryStatus(46, 70, 0.7) == false); // Temperature out of range
    assert(verifyBatteryStatus(25, 81, 0.7) == false); // SOC out of range
    assert(verifyBatteryStatus(25, 70, 0.9) == false); // Charge rate out of range
    assert(verifyBatteryStatus(0, 20, 0.8) == true); // Edge case: all on lower limits
    assert(verifyBatteryStatus(45, 80, 0.8) == true); // Edge case: all on upper limits
    assert(verifyBatteryStatus(-0.1, 70, 0.7) == false); // Temperature slightly below lower limit
    assert(verifyBatteryStatus(25, 19.9, 0.7) == false); // SOC slightly below lower limit
    assert(verifyBatteryStatus(25, 70, -0.1) == false); // Charge rate slightly below lower limit
    assert(verifyBatteryStatus(25, 70, 0.81) == false); // Charge rate slightly above upper limit

    cout << "All tests passed!" << endl;
    return 0;
}
