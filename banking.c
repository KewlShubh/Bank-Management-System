#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <windows.h>

int main()
{
    static Account_details Acc_det[100];
    char ch;
    system("clear");
    printf("*************************WELCOME TO DHANI BANK**************************\n");
    printf("Please enter one of the option number:\n1.Create A New Account\n2. Check Account Details\n3. NEFT\n4. Apply for Physical Card\n5. Exit\n");
    scanf("%c",&ch);
    
    switch(ch)
    {
        case '1': Create_acc(Acc_det);break;
        case '2': Show_acc_det(Acc_det);break;
        case '3': printf("Work in Progress\n We'll get back soon :)");break;
        case '4': printf("Work in Progress\n We'll get back soon :)");break;
        case '5': exit(0);
        default: printf("Enter a valid number");
    }
}