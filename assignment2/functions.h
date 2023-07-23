#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

// Declare prototypes
void clearInputBuffer();
bool playWordGuessingGame(const char *randomWord);
bool playWordGuessingGameAutomatic(const char *randomWord, char **words, int numWords, int numSuggestion);

#endif