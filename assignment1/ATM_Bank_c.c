#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Made a clear input buffer function to clean up code, since it is used multiple times in the code
// Purpose: incase the user inputs excess characters/symbols that are not accepted by scanf, they are cleared from the input buffer
// The program will continue to run as expected, and there will be no misoperations
// Without clearing the input buffer, the unexpected characters/symbols will continue to be read by scanf
// This results in an infinite loop, endlessly printing messages as the output
void clearInputBuffer() {
    while (getchar() != '\n') {
        continue;
    }
}


int main()
{
    // Create variables
    int choice;
    float deposit;
    float withdraw;
    float interest_rate;
    int years;
    int num_accounts;
    int current_account;


    // While loop checks if the number of accounts entered is valid
    while (1) {
        printf("Enter the number of accounts: ");
        // Checks if input is a integer, is greater than 0 and less than or equal to 10
        if (scanf("%d", &num_accounts) == 1 && num_accounts > 0 && num_accounts <= 10) {
                break;
        } 
        // Prints error message and clears input buffer
        else {
            printf("Error: Invalid input. Enter a valid number of accounts, an integer greater than 0 and less than or equal to 10, without any symbols.\n");
            clearInputBuffer();
            }
        }
    clearInputBuffer();


    // Creating the array for account balances
    float balances[num_accounts-1];
    for (int i = 0; i < num_accounts; i++) {
        while (1) {
            // Checks if the input is a float and is greater than 0
            printf("Enter the balance for account %d: $", i);
            if (scanf("%f", &balances[i]) == 1 && balances[i] >= 0) {
                break;
            } 
            // Prints error message and clears input buffer
            else {
                printf("Error: Invalid input. Enter a valid balance, an integer greater than 0, without any symbols.\n");
                clearInputBuffer();
            }
        }
        clearInputBuffer();
    }


    // While loops prompts user for the account they want to enter
    while (1) {
        printf("Enter the account number you would like to enter: ");
        // Checks if the input is a valid account number
        if (scanf("%d", &current_account) == 1 && current_account >= 0 && current_account <= num_accounts-1) {
            break;
        } 
        // Prints error message and clears input buffer
        else {
            printf("Error: Invalid input. Enter a valid account number, from 0 to %d without any symbols.\n", (num_accounts-1));
            clearInputBuffer();
        }
    }
    clearInputBuffer();


    // While loop checks if interest rate entered is valid
    while (1) {
        printf("Enter interest rate: ");
        // Checks if the input is a float, is greater than or equal to 0 and is less than or equal to 100
        if (scanf("%f", &interest_rate) == 1 && interest_rate <= 100 && interest_rate >= 0) {
                break;
        } 
        // Prints error message and clears input buffer
        else {
            printf("Error: Invalid input. Enter a valid interest rate between 0 and 100, without any symbols.\n");
            clearInputBuffer();
        }
    }
    clearInputBuffer();



    // While loop prompts user for their desired operation
    while (1) {
        printf("Current Account: %d\nSelect an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Future Balance Using Interest Rate\n 5. Switch Account\n 6. Display All Balances\n 0. exit\nEnter operation number: ", current_account);
        // Checks if the input is a valid operation
        if (scanf("%d", &choice) == 1 && choice >= 0 && choice <= 6) {
            // Clear input buffer incase user inputs invalid input that is left in input buffer
            clearInputBuffer();

            switch (choice) {
                // Deposit
                case 1:
                    while (1) {
                        printf("Enter the amount you would like to deposit: ");
                        // Checks if input is a valid deposit
                        if (scanf("%f", &deposit) == 1 && deposit >= 0) {
                            balances[current_account] += deposit;
                            break;
                        } 
                        // Prints error message and clears input buffer
                        else {
                            printf("Error: Invalid input. Enter a valid deposit, a number greater than 0 without any symbols.\n");
                            clearInputBuffer();
                        }
                    }
                    break;

                // Withdraw
                case 2:
                    while (1) {
                        printf("Enter the amount you would like to withdraw: ");
                        // Checks if input is a valid withdrawl
                        if (scanf("%f", &withdraw) == 1 && withdraw >= 0 && withdraw <= balances[current_account]) {
                            balances[current_account] -= withdraw;
                            break;
                        }
                        // Prints error message and clears input buffer
                        else {
                            printf("Error: Invalid input. Enter a valid withdrawl, a number greater than 0 and less than your total balance without any symbols.\n");
                            clearInputBuffer();
                        }
                    }
                    break;

                // Prints current balance
                case 3:
                    printf("Current balance: $%.2f\n", balances[current_account]);
                    break;

                // Prints future balance based on given interest rate and years
                case 4:
                    while (1) {
                        printf("Enter the amount of years: ");
                        // Checks if input is a valid number of years
                        if (scanf("%d", &years) == 1 && years >= 0) {
                            float interest_amount = balances[current_account]*pow((1+interest_rate/100),years);
                            printf("Future Balance (%.2f%% interest rate in %d years): $%.2f\n", interest_rate, years, interest_amount);
                            break;
                        }
                        // Prints error message and clears input buffer
                        else {
                            printf("Error: Invalid input. Enter a valid number of years greater than 0 without any symbols.\n");
                            clearInputBuffer();
                        }
                    }
                    break;
                
                // Switches user account
                case 5:
                    while (1) {
                        printf("Enter the account number to switch to: ");
                        // Checks if input is a valid acount number
                        if (scanf("%d", &current_account) == 1 && current_account >= 0 && current_account <= num_accounts-1) {
                            break;
                        }
                        // Prints error message and clears input buffer
                        else {
                            printf("Error: Invalid input. Enter a valid account number, from 0 to %d without any symbols.\n", (num_accounts-1));
                            clearInputBuffer();
                        }
                    }
                    break;

                // Displays all user balances
                case 6:
                    for (int b = 0; b < num_accounts; b++) {
                        printf("Account %d: $%.2f\n", b, balances[b]);
                    }
                    break;

                // Break switch loop
                case 0:
                    break;
            }

        } else {
            // Prints error message and clears input buffer
            printf("Error: Invalid input. Enter a valid operation number between 0 and 6, without any symbols.\n");
            clearInputBuffer();
        }
        
        // Exits program
        if (choice == 0) {
            break;
        }

        // Clear input buffer incase user inputs invalid input that is left in input buffer
        // Note: if the user just checked the balance(s), there will be nothing in the input buffer
        // Therefore, it is not necessary to clear the input buffer, and this needs to be checked
        // Otherwise the function will not continue
        if (choice != 3 && choice != 6) {
            clearInputBuffer();
        }
    }
}