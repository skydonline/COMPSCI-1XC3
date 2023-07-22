#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

// Declare prototypes
bool playWordGuessingGame(const char *randomWord);
void clearInputBuffer();
bool playWordGuessingGameAutomatic(const char *randomWord, char **words, int numWords, int numSuggestion);

#endif