#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "Language.h"
#include <string>

// Declare the main Translate function
std::string Translate(const std::string& key, preferredLanguage lang);

// Function prototypes for handling translations
std::string TranslateToEnglish(const std::string& key);
std::string TranslateToGerman(const std::string& key);

#endif // TRANSLATION_H
