#include "Translation.h"

// Helper function to translate keys to English
std::string TranslateToEnglish(const std::string& key) {
    if (key == "Temperature") return "Temperature";
    if (key == "State of Charge") return "State of Charge";
    if (key == "Charge Rate") return "Charge Rate";
    if (key == "in") return "in";
    if (key == "out") return "out";
    return key; // Default case if no translation found
}

// Helper function to translate keys to German
std::string TranslateToGerman(const std::string& key) {
    if (key == "Temperature") return "Temperatur";
    if (key == "State of Charge") return "Ladezustand";
    if (key == "Charge Rate") return "Ladegeschwindigkeit";
    if (key == "in") return "drin";
    if (key == "out") return "raus";
    return key; // Default case if no translation found
}

// Main Translate function that selects the appropriate language function
std::string Translate(const std::string& key, preferredLanguage lang) {
    if (lang == preferredLanguage::English) {
        return TranslateToEnglish(key);
    } else if (lang == preferredLanguage::German) {
        return TranslateToGerman(key);
    }
    return key; // Default case if language is unknown
}
