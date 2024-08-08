#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

// Enum class for supported languages
enum class preferredLanguage {
    English,
    German
};

// Function to translate messages
std::string Translate(const std::string& key, preferredLanguage lang);

#endif // LANGUAGE_H
