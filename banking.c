#include <stdio.h>
#include "header.h"
#include <stdlib.h>
// #include <windows.h>

int main()
{
    char x;
    static Account_details Acc_det[100];
    char ch;
    system("clear");
    printf("*************************WELCOME TO DHANI BANK**************************\n");

    while (1)
    {
        printf("Please enter one of the option number:\n1. Create A New Account\n2. Check Account Details\n3. NEFT\n4. Apply for Physical Card\n5. Exit\n");
        scanf("%c", &ch);

        switch (ch)
        {
        case '1':
            system("clear");
            Create_acc(Acc_det);
            break;
        case '2':
            system("clear");
            Show_acc_det(Acc_det);
            break;
        case '3':
            system("clear");
            neft();
            break;
        case '4':
            system("clear");
            printf("Physical card will be delivered to your nearest branch in 2-3 business working days\nKindly contact your branch manager for tracking status\n");
            x = getchar();
            x = getchar();
            system("clear");
            break;
        case '5':
            exit(0);
            break;
        case '6':
            system("clear");
            printaccs();
            x = getchar();
            x = getchar();
            break;
        default:
            printf("Enter a valid number\n");
            x = getchar();
            x = getchar();
            system("clear");
        }
    }
}