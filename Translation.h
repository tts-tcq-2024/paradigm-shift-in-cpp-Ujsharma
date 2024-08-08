// Translation.h
#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <string>

enum class preferredLanguage { English, German };

std::string Translate(const std::string& text, preferredLanguage lang);

#endif // TRANSLATION_H
