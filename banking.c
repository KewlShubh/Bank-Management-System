#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main()
{
    static Account_details Acc_det[100];
    //Create_acc(Acc_det);
    Create_acc(Acc_det);

    // Create_acc(Acc_det);
    Show_acc_det(Acc_det);

}