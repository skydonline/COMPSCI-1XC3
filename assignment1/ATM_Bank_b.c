#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;
    float interest;
    int years;


    printf("Enter interest rate (enter percentage without the symbol): ");
    scanf("%f", &interest);


    while (choice != 0)
    {


        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Future Balance Using Interest Rate\n 0. exit\nEnter operation number: ");
        scanf("%d", &choice);


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
    }
}