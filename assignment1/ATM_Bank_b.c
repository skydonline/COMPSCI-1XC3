#include <stdio.h>
#include <math.h>

int main()
{
    // Create variables
    int choice;
    float balance;
    float deposit;
    float withdraw;
    float interest_rate;
    int years;


    // Gets interest rate from the user
    printf("Enter interest rate (enter amount without the symbol): ");
    scanf("%f", &interest_rate);


    // While loop breaks when user enters 0
    while (choice != 0)
    {

        // Gets operation number from the user
        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Future Balance Using Interest Rate\n 0. exit\nEnter operation number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        // Deposit
        case 1:
            printf("Enter the amount you would like to deposit: $");
            scanf("%f", &deposit);
            balance += deposit;
            break;

        // Withdraw
        case 2:
            printf("Enter the amount you would like to withdraw: $");
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

        // Prints future balance given years and interest rate
        case 4:
            printf("Enter the amount of years: ");
            scanf("%d", &years);
            float interest_amount = balance*pow((1+interest_rate/100),years);
            printf("Future Balance: $%.2f\n", interest_amount);
            break;

        case 0:
            break;
        }
    }
}