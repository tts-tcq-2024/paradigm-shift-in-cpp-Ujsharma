#include "BatteryMonitoring.h"
#include "Language.h"
#include <iostream>
#include <cassert>

int main() {
    preferredLanguage lang = preferredLanguage::German;

    assert(isBatteryOk(25, 70, 0.7, lang) == true);
    assert(isBatteryOk(50, 85, 0, lang) == false);
    assert(isBatteryOk(-1, 70, 0.5, lang) == false);
    assert(isBatteryOk(25, 10, 0.5, lang) == false);
    assert(isBatteryOk(25, 70, 0.9, lang) == false);
    assert(isBatteryOk(45, 80, 0.8, lang) == false);
    assert(isBatteryOk(0, 20, 0, lang) == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
