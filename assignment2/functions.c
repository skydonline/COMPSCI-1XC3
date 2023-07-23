#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#include "constants.h"
#include "functions.h"

// Function to clear input buffer, cleans up code
void clearInputBuffer() {
    while (getchar() != '\n') {
        continue;
    }
}

// Part A
// Function to play the game
// Returns true if the word is correctly guessed
// Returns false if they have not guessed it and has ran out of attempts
bool playWordGuessingGame(const char *randomWord) {
    
    // Initalize variables
    int attempts = 1;   // # of user attempts
    char guess;     // The user letter guess
    bool correctGuess = false;  // Used to check if we should increment attempt
    char guessedLetters[MAX_WORD_LENGTH] = {0};     // Store previously guessed letters

    // If attempts is greater than max attempts, exit the loop and return false
    while (attempts <= MAX_ATTEMPTS) {

        // Prompt user for their guess
        printf("Attempt %d: ", attempts);
        scanf("%c", &guess);


        // Store the correctly guessed letters
        // Change correctGuess variable to true, so later in the while loop it doesn't increment attempt
        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (randomWord[i] == guess) {
                guessedLetters[i] = guess;
                correctGuess = true; 
            }
        }


        // Display word with correct and incorrect letters
        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (guessedLetters[i] != 0) {
                printf("%c ", guessedLetters[i]);
            } else {
                printf("- ");
            }
        }


        // Add an attempt if they gave an incorrect guess, and display the appropiate message
        if (!correctGuess) {
            // Prevent from printing incorrect guess again, since the user will be out of attempts
            if (attempts == MAX_ATTEMPTS) {
                printf("\n");
                break;
            }
            attempts++;
            printf("\nIncorrect guess. Try again.\n");
        } else {
            printf("\nCorrect guess!\n");
        }


        // Check if word is entirely guessed, if so, return true
        if (strcmp(guessedLetters, randomWord) == 0) {
            return true;
            clearInputBuffer();     // Clear input buffer
        }
        clearInputBuffer();     // Clear input buffer
        correctGuess = false;   // Reset correctGuess variable to false
    }
    clearInputBuffer();     // Clear input buffer
    return false;   // Return false if user failed to guess word
}


// Part B
bool playWordGuessingGameAutomatic(const char *randomWord, 
char **words, int numWords, int numSuggestion) {

    // Initalize variables
    int attempts = 1;
    char guess;
    bool correctGuess = false;
    char guessedLetters[MAX_WORD_LENGTH] = {0};


    // If attempts is greater than max attempts, exit the loop and return false
    while (attempts <= MAX_ATTEMPTS) {

        // Prompt user for their guess
        printf("Attempt %d: ", attempts);
        scanf("%c", &guess);


        // Change correctGuess variable to true, so later in the while loop it doesn't add an attempt
        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (randomWord[i] == guess) {
                guessedLetters[i] = guess;
                correctGuess = true;
            }
        }


        // Display word with correct and incorrect letters
        for (int i = 0; randomWord[i] != '\0'; i++) {
            if (guessedLetters[i] != 0) {
                printf("%c ", guessedLetters[i]);
            } else {
                printf("- ");
            }
        }


        // Add an attempt if they gave an incorrect guess, and display the appropiate message
        if (!correctGuess) {
            

            // Checks if user has 1 attempt left
            if (attempts == MAX_ATTEMPTS - 1) {

                int possibleWords = 0;
            for (int i = 0; i < numWords; i++) {
                // Check if the word has the same length as the randomWord
                if (strlen(words[i]) != strlen(randomWord)) {
                    continue;
                }

                int j;
                for (j = 0; randomWord[j] != '\0'; j++) {
                    if (guessedLetters[j] != 0 && guessedLetters[j] != words[i][j]) {
                        break;
                    }
                }
                if (randomWord[j] == '\0') {
                    // The word matches the guessed letters
                    possibleWords++;
                }
            }

            // Print the number of possible words and the first 'numSuggestion' words
            printf("\nThe number of possible words = %d\nHere are up to the first %d possible words:\n", possibleWords, numSuggestion);
            for (int index = 0; index < numWords && numSuggestion > 0; index++) {
                // Check if the word has the same length as the randomWord
                if (strlen(words[index]) != strlen(randomWord)) {
                    continue;
                }

                int j;
                for (j = 0; randomWord[j] != '\0'; j++) {
                    if (guessedLetters[j] != 0 && guessedLetters[j] != words[index][j]) {
                        break;
                    }
                }
                if (randomWord[j] == '\0') {
                    printf("%s,\n", words[index]);
                    numSuggestion--;
                }
            }
        }


            // Prevent from printing incorrect guess again, since the user will be out of attempts
            if (attempts == MAX_ATTEMPTS) {
                printf("\n");
                break;
            }
            attempts++;
            printf("\nIncorrect guess. Try again.\n");
        } else {
            printf("\nCorrect guess!\n");
        }


        // Check if word is entirely guessed, if so, return true
        if (strcmp(guessedLetters, randomWord) == 0) {
            return true;
        }
        clearInputBuffer();     // Clear input buffer
        correctGuess = false;   // Reset correctGuess variable to false
    }
    return false;   // Return false if user failed to guess word
}