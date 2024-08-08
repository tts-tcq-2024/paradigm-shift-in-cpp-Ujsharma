#include "Language.h"
#include <map>
#include <string>

// Defining the translation map
const std::map<std::string, std::map<std::string, std::string>> translateMessage{
    {"English", {{"Temperature", "Temperature"}, {"State of Charge", "State Of Charge"}, {"Charge Rate", "Charge Rate"}, {"out", "is out of range"}, {"in", "is in range"}}},
    {"German", {{"Temperature", "Temperatur"}, {"State of Charge", "Ladezustand"}, {"Charge Rate", "Laderate"}, {"out", "liegt außerhalb des Bereichs"}, {"in", "liegt im Bereich"}}}
};

// Helper function to convert preferredLanguage enum to string
std::string languageToString(preferredLanguage lang) {
    switch (lang) {
        case preferredLanguage::English: return "English";
        case preferredLanguage::German: return "German";
        default: return "English"; // Default to English if unknown
    }
}

// Function to translate messages
std::string Translate(const std::string& key, preferredLanguage lang) {
    std::string langStr = languageToString(lang);

    // Check if the current language has a translation for the given key
    auto it = translateMessage.find(langStr);
    if (it != translateMessage.end()) {
        const auto& translations = it->second;
        auto keyIt = translations.find(key);
        if (keyIt != translations.end()) {
            return keyIt->second;
        }
    }
    // If no translation is found, return the key itself
    return key;
}
