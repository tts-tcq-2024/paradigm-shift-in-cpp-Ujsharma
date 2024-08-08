#include "Language.h"
#include <map>
#include <string>

const std::map<std::string, std::map<std::string, std::string>> translateMessage{
    {"english", {
        {"high_temperature_warning", "Approaching upper limit"},
        {"low_temperature_warning", "Approaching lower limit"},
        {"high_soc_warning", "Approaching charge-peak"},
        {"low_soc_warning", "Approaching discharge"},
        // Add other messages
    }},
    {"german", {
        {"high_temperature_warning", "Annäherung an obere Grenze"},
        {"low_temperature_warning", "Annäherung an untere Grenze"},
        {"high_soc_warning", "Annäherung an Lade-Grenze"},
        {"low_soc_warning", "Annäherung an Entlade-Grenze"},
        // Add other messages
    }}
};
