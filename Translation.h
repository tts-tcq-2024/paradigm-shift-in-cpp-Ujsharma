#ifndef LANGUAGETRANSLATE_H
#define LANGUAGETRANSLATE_H

#include <string>

// Enum class for supported languages
enum class preferredLanguage {
    English,
    German
};

// Function to translate messages
std::string messageTranslate(const std::string& key, preferredLanguage lang);

#endif // LANGUAGETRANSLATE_H
