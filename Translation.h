#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <string>
using namespace std;

// Enum for supported languages
enum class preferredLanguage {
    English,
    German
};

// Function to translate messages
string translateMessage(const string& key, preferredLanguage lang);

// Global variable for selected language
extern preferredLanguage selectedLanguage;

#endif // TRANSLATION_H
