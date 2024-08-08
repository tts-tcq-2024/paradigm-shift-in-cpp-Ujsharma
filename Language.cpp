#include "Language.h"
#include <map>
#include <string>

// Defining the translation map
const std::map<std::string, std::map<std::string, std::string>> translateMessage{
    {"english", {
        {"Temperature", "Temperature"},
        {"State of Charge", "State Of Charge"},
        {"Charge Rate", "Charge Rate"},
        {"out", "is out of range"},
        {"in", "is in range"},
        {"low_soc_warning", "Approaching discharge"},
        {"high_soc_warning", "Approaching charge-peak"},
        {"low_temperature_warning", "Approaching lower limit"},
        {"high_temperature_warning", "Approaching upper limit"},
        {"low_charge_rate_warning", "Approaching lower limit"},
        {"high_charge_rate_warning", "Approaching upper limit"}
    }},
    {"german", {
        {"Temperature", "Temperatur"},
        {"State of Charge", "Ladezustand"},
        {"Charge Rate", "Laderate"},
        {"out", "liegt außerhalb des Bereichs"},
        {"in", "liegt im Bereich"},
        {"low_soc_warning", "Annäherung an Entladung"},
        {"high_soc_warning", "Annäherung an Ladehöhepunkt"},
        {"low_temperature_warning", "Annäherung an untere Grenze"},
        {"high_temperature_warning", "Annäherung an obere Grenze"},
       
