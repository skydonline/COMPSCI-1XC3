#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int choice;
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;
    float interest = -1;
    int years;
    int num_accounts;



    while (1) {
        printf("Enter the number of accounts: ");

        if (scanf("%d", &num_accounts) == 1 && num_accounts > 0 && num_accounts <= 10) {
                break;
        } 

        else {
            printf("Error: Invalid input. Enter a valid number of accounts, an integer greater than 0, without any symbols.\n");
            while (getchar() != '\n') {
                continue;
            }
        }
    }



    while (1) {
        printf("Enter interest rate: ");

        if (scanf("%f", &interest) == 1 && interest <= 100 && interest >= 0) {
                break;
        } 

        else {
            printf("Error: Invalid input. Enter a valid interest rate between 0 and 100, without any symbols.\n");
            while (getchar() != '\n') {
                continue;
            }
        }
    }



    while (1) {
        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Future Balance Using Interest Rate\n 5. Switch Account\n 6. Display All Balances\n 0. exit\nEnter operation number: ");
        
        if (scanf("%d", &choice) == 1 && choice >= 0 && choice <= 6) {
            switch (choice)
            {
            case 1:
                printf("Enter the amount you would like to deposit: ");
                scanf("%f", &deposit);
                balance += deposit;
                break;

            case 2:
                printf("Enter the amount you would like to deposit: ");
                scanf("%f", &withdraw);
                balance -= withdraw;
                break;

            case 3:
                printf("Current balance: $%.2f\n", balance);
                break;

            case 4:
                printf("Enter the amount of years: ");
                scanf("%d", &years);
                printf("Future Balance: %.2f\n", balance*pow((1+interest/100),years));
                break;

            case 0:
                break;
            }

        } else {
            printf("Error: Invalid input. Enter a number between 0 and 6, without any symbols.\n");
            while (getchar() != '\n') {
                continue;
            }
        }
        
        if (choice == 0) {
            break;
        }
    }
}