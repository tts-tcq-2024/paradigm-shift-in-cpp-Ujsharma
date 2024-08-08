#include "Translation.h"

std::string Translate(const std::string& key, preferredLanguage lang) {
    // Example implementation (update according to your translation logic)
    if (lang == preferredLanguage::English) {
        if (key == "Temperature") return "Temperature";
        if (key == "State of Charge") return "State of Charge";
        if (key == "Charge Rate") return "Charge Rate";
        if (key == "in") return "in";
        if (key == "out") return "out";
    } else if (lang == preferredLanguage::German) {
        if (key == "Temperature") return "Temperatur";
        if (key == "State of Charge") return "Ladezustand";
        if (key == "Charge Rate") return "Ladegeschwindigkeit";
        if (key == "in") return "drin";
        if (key == "out") return "raus";
    }
    return key; // Default case if no translation found
}
