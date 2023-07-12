#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Made a clear input buffer function to clean up code, since it is used multiple times in the code
void clearInputBuffer() {
    while (getchar() != '\n') {
        continue;
    }
}

int main()
{
    // Create variables
    int choice;
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;
    float interest = -1;
    int years;
    int num_accounts;



    // While loop checks if the number of accounts entered is valid
    while (1) {
        printf("Enter the number of accounts: ");

        // Checks if input is a integer, is greater than 0 and less than or equal to 10
        if (scanf("%d", &num_accounts) == 1 && num_accounts > 0 && num_accounts <= 10) {
                break;
        } 
        // Prints error message and clears input buffer
        else {
            printf("Error: Invalid input. Enter a valid number of accounts, an integer greater than 0, without any symbols.\n");
            clearInputBuffer();
            }
        }



    // Clear input buffer incase user inputs invalid input that is left in input buffer
    clearInputBuffer();



    // While loop checks if interest rate entered is valid
    while (1) {
        printf("Enter interest rate: ");

        // Checks if the input is a float, is greater than or equal to 0 and is less than or equal to 100
        if (scanf("%f", &interest) == 1 && interest <= 100 && interest >= 0) {
                break;
        } 
        // Prints error message and clears input buffer
        else {
            printf("Error: Invalid input. Enter a valid interest rate between 0 and 100, without any symbols.\n");
            clearInputBuffer();
        }
    }



    // Clear input buffer incase user inputs invalid input that is left in input buffer
    clearInputBuffer();



    // While loop prompts user for their desired operation
    while (1) {
        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Future Balance Using Interest Rate\n 5. Switch Account\n 6. Display All Balances\n 0. exit\nEnter operation number: ");
        
        // Checks if the input is a valid operation
        if (scanf("%d", &choice) == 1 && choice >= 0 && choice <= 6) {

            // Clear input buffer incase user inputs invalid input that is left in input buffer
            clearInputBuffer();

            switch (choice)
            {
            // Deposit
            case 1:
                while (1) {
                    // Checks if input is a valid deposit
                    printf("Enter the amount you would like to deposit: ");
                    if (scanf("%f", &deposit) == 1 && deposit >= 0) {
                        balance += deposit;
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
                    // Checks if input is a valid withdrawl
                    printf("Enter the amount you would like to withdraw: ");
                    if (scanf("%f", &withdraw) == 1 && withdraw >= 0 && withdraw <= balance) {
                        balance -= withdraw;
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
                printf("Current balance: $%.2f\n", balance);
                break;

            // Prints future balance based on given interest rate and years
            case 4:
                while (1) {
                    // Checks if input is a valid number of years
                    printf("Enter the amount of years: ");
                    if (scanf("%d", &years) == 1 && years >= 0) {
                        printf("Future Balance: %.2f\n", balance*pow((1+interest/100),years));
                        break;
                    }
                    // Prints error message and clears input buffer
                    else {
                        printf("Error: Invalid input. Enter a valid number of years greater than 0 without any symbols.\n");
                        clearInputBuffer();
                    }
                }
                break;

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
        // Note: if the user just checked the balance, there will be nothing in the input buffer
        // Therefore, it is not necessary to clear the input buffer, and this needs to be checked
        // Otherwise the function will not continue
        if (choice != 3) {
            clearInputBuffer();
        }
    }
}