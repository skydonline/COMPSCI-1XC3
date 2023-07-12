#include <stdio.h>

int main()
{
    // Create variables
    int choice;
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;


    // While loop breaks when user enters 0
    while (choice != 0)
    {

        // Gets operation number from the user
        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 0. exit\nEnter operation number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        // Deposit
        case 1:
            printf("Enter the amount you would like to deposit: ");
            scanf("%f", &deposit);
            balance += deposit;
            break;

        // Withdraw
        case 2:
            printf("Enter the amount you would like to withdraw: ");
            scanf("%f", &withdraw);
            
            // Checks is user is trying to withdraw more than their balance
            if (withdraw > balance) {
                printf("You cannot withdraw more than your balance.\n");
            } else {
                balance -= withdraw;
            }
            break;

        // Prints balance
        case 3:
            printf("Current balance: $%.2f\n", balance);
            break;

        case 0:
            break;
        }
    }
}