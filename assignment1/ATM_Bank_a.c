#include <stdio.h>

int main()
{
    int choice;
    float balance = 0;
    float deposit = 0;
    float withdraw = 0;


    while (choice != 0)
    {


        printf("Select an operation:\n 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 0. exit\n");
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

        case 0:
            break;
        }
    }
}