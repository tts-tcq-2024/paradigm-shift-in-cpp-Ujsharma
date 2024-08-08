#include "Translation.h"
#include <map>
#include <string>

preferredLanguage selectedLanguage = preferredLanguage::English;

// Translation dictionary
const map<string, map<string, string>> translations = {
    {"english", {
        {"Temperature", "Temperature"},
        {"State of Charge", "State of Charge"},
        {"Charge Rate", "Charge Rate"},
        {"out", "is out of range"},
        {"in", "is in range"}
    }},
    {"german", {
        {"Temperature", "Temperatur"},
        {"State of Charge", "Ladezustand"},
        {"Charge Rate", "Laderate"},
        {"out", "liegt außerhalb des Bereichs"},
        {"in", "liegt im Bereich"}
    }}
};

// Convert preferredLanguage enum to string
string getLanguageString(preferredLanguage lang) {
    switch (lang) {
        case preferredLanguage::English: return "english";
        case preferredLanguage::German: return "german";
        default: return "english";
    }
}

// Function to translate messages
string translateMessage(const string& key, preferredLanguage lang) {
    string language = getLanguageString(lang);

    if (translations.count(language) > 0) {
        const auto& langTranslations = translations.at(language);
        if (langTranslations.count(key) > 0) {
            return langTranslations.at(key);
        }
    }
    return key;
}
