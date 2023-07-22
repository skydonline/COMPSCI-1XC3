#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#include "constants.h"
#include "functions.h"

void clearInputBuffer() {
    while (getchar() != '\n') {
        continue;
    }
}

bool playWordGuessingGame(const char *randomWord) {
    int attempts = 1;
    char guess;
    bool correctGuess;
    char guessedLetters[MAX_WORD_LENGTH] = {0}; // Initialize the array to all zeros

    while (attempts <= MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts);
        scanf("%c", &guess);

        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (randomWord[i] == guess) {
                guessedLetters[i] = guess;
                correctGuess = true;
            }
        }

        // Display the word with correctly guessed letters
        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (guessedLetters[i] != 0) {
                printf("%c ", guessedLetters[i]);
            } else {
                printf("- ");
            }
        }

        if (!correctGuess) {
            // prevent from printing incorrect guess again, since the user will be out of attempts
            if (attempts == MAX_ATTEMPTS) {
                printf("\n");
                break;
            }
            attempts++;
            printf("\nIncorrect guess. Try again.\n");
        } else {
            printf("\nCorrect guess!\n");
        }

        // Check if the word is completely guessed
        if (strcmp(guessedLetters, randomWord) == 0) {
            return true;
        }
        correctGuess = false;

        clearInputBuffer();
    }

    return false;
}