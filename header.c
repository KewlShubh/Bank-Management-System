#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
// #include <windows.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void encdec(int i)
{
    char ch;
    FILE *fpts, *fptt;

    fpts = fopen("accounts.dat", "r");
    if (fpts == NULL)
    {
        exit(1);
    }
    fptt = fopen("temp.dat", "w");
    if (fptt == NULL)
    {
        fclose(fpts);
        exit(2);
    }
    while (1)
    {
        ch = fgetc(fpts);
        if (ch == EOF)
        {
            break;
        }
        else if (i == 0)
        {
            ch = ch + 100;
            fputc(ch, fptt);
        }
        else if (i == 1)
        {
            ch = ch - 100;
            fputc(ch, fptt);
        }
    }
    fclose(fpts);
    fclose(fptt);
    fpts = fopen("accounts.dat", "w");
    if (fpts == NULL)
    {
        exit(3);
    }
    fptt = fopen("temp.dat", "r");
    if (fptt == NULL)
    {
        fclose(fpts);
        exit(4);
    }
    while (1)
    {
        ch = fgetc(fptt);
        if (ch == EOF)
        {
            break;
        }
        else
        {
            fputc(ch, fpts);
        }
    }
    fclose(fpts);
    fclose(fptt);
}

int Create_acc(Account_details *Acc_det)
{
    srand(time(0));
    ++i;
    printf("Enter Account holder's name:\n");
    fflush(stdin);
    scanf("%s", Acc_det[i].name);
    fflush(stdin);
    printf("Enter contact number:\n");
    scanf(" %ld", &Acc_det[i].contact_number);
    fflush(stdin);
    printf("Enter the amount you want to credit (minimum 1000 Rs):\n");
    scanf(" %f", &Acc_det[i].balance);
    fflush(stdin);
    strcpy(Acc_det[i].IFSC, "DHAN0456728");
    // Acc_det[i].IFSC = "DHAN0456728";
    Acc_det[i].acc_num = (rand() % (9999999999 - 1000000000 + 1)) + 1000000000;
    printf("Enter your login password:\n");
    fflush(stdin);
    scanf("%s", Acc_det[i].login_pass);

    FILE *fp;
    fp = fopen("accounts.dat", "a");
    unsigned long len = (unsigned long)ftell(fp);
    if (len > 0)
    {
        encdec(1);
    }
    fwrite(&Acc_det[i], sizeof(Account_details), 1, fp);
    fclose(fp);
    system("clear");
    char c1 = getchar();
    printf("Thank you for creating an account!!\n");
    printf("Your account number is:%ld\n", Acc_det[i].acc_num);
    char c = getchar();
    system("clear");
    encdec(0);
    return 1;
}

int Show_acc_det(Account_details *Acc_det)
{
    encdec(1);
    Account_details acc[100];
    FILE *fr;
    long int ac_num;
    int m = 0, r = 2, flag = 1;
    char pass[20];
    fr = fopen("accounts.dat", "r");
    int k = 0;
    fseek(fr, 0, SEEK_SET);
    while (fread(&acc[k], sizeof(Account_details), 1, fr))
    {
        k++;
    }
    fclose(fr);

    printf("Enter ur account number:\n");
    fflush(stdin);
    scanf("%ld", &ac_num);
    printf("Enter password:\n");
    fflush(stdin);
    scanf("%s", pass);

    Account_details *ptr, *endptr;
    ptr = &acc[0];
    endptr = acc + (((sizeof(acc) / sizeof(acc[0])) * k));
    while (ptr <= endptr)
    {

        if (acc[m].acc_num == ac_num)
        {
            flag = 0;
            while (r)
            {
                if (!(strcmp(pass, acc[m].login_pass)))
                {
                    system("clear");
                    printf("Account holder name:%s\n", acc[m].name);
                    printf("Account number:%ld\n", acc[m].acc_num);
                    printf("Contact number:%ld\n", acc[m].contact_number);
                    printf("Balance:%.2f\n", acc[m].balance);
                    printf("IFSC code:%s\n", acc[m].IFSC);
                    m++;
                    break;
                }
                else
                {
                    printf("you have entered wrong password :(\nKindly enter the password again\n");
                    printf("Enter password:\n");
                    fflush(stdin);
                    scanf("%s", pass);
                    if (!(strcmp(pass, acc[m].login_pass)))
                    {
                        system("clear");
                        printf("Account holder name:%s\n", acc[m].name);
                        printf("Account number:%ld\n", acc[m].acc_num);
                        printf("Contact number:%ld\n", acc[m].contact_number);
                        printf("Balance:%.2f\n", acc[m].balance);
                        printf("IFSC code:%s\n", acc[m].IFSC);
                        m++;
                        break;
                    }
                    --r;
                }
            }
        }
        else
        {
            m++;
        }
        ptr += sizeof(acc[0]);
    }
    if (flag)
        printf("account number not found!\n");
    char c = getchar();
    c = getchar();
    system("clear");
    encdec(0);
    return 1;
}

void printaccs()
{
    encdec(1);
    Account_details acc[100];
    FILE *fr;
    fr = fopen("accounts.dat", "r");
    int k = 0;
    while (fread(&acc[k], sizeof(Account_details), 1, fr))
    {
        k++;
    }
    fclose(fr);

    Account_details *ptr, *endptr;
    ptr = acc;
    endptr = acc + (((sizeof(acc) / sizeof(acc[0])) * k) - sizeof(acc) / sizeof(acc[0]));
    k = 0;
    while (ptr <= endptr)
    {
        printf("Account holder name:%s\n", acc[k].name);
        printf("Account number:%ld\n", acc[k].acc_num);
        printf("Contact number:%ld\n", acc[k].contact_number);
        printf("Balance:%.2f\n", acc[k].balance);
        printf("IFSC code:%s\n", acc[k].IFSC);
        k++;
        ptr += sizeof(acc[0]);
    }
    encdec(0);
}

void neft()
{
    encdec(1);
    Account_details acc[100];
    FILE *fr;
    long int ac_num;
    int m = 0, r = 2, flag = 1, l = 0;
    char pass[20];
    fr = fopen("accounts.dat", "r");
    int k = 0;
    fseek(fr, 0, SEEK_SET);
    while (fread(&acc[k], sizeof(Account_details), 1, fr))
    {
        k++;
    }
    fclose(fr);

    printf("Enter ur account number:\n");
    fflush(stdin);
    scanf("%ld", &ac_num);
    printf("Enter password:\n");
    fflush(stdin);
    scanf("%s", pass);
    printf("Enter the amount for transfer:\n");
    fflush(stdin);
    float amount_trans;
    scanf("%f", &amount_trans);

    printf("Enter receiver account number:\n");
    fflush(stdin);
    int ac_rec_num;
    scanf("%d", &ac_rec_num);

    Account_details *ptr, *endptr, *ptr1, *endptr1;
    ptr = &acc[0];
    ptr1 = &acc[0];
    endptr = acc + (((sizeof(acc) / sizeof(acc[0])) * k));
    endptr1 = acc + (((sizeof(acc) / sizeof(acc[0])) * k));
    while (ptr <= endptr)
    {

        if (acc[m].acc_num == ac_num)
        {
            flag = 0;
            while (r)
            {
                if (!(strcmp(pass, acc[m].login_pass)) && amount_trans < acc[m].balance)
                {
                    printf("\nAmount transferd successfully\n");
                    printf("\nAmount before transaction %.2f\n", acc[m].balance);
                    acc[m].balance -= amount_trans;
                    printf("\nAmount left %.2f\n\n", acc[m].balance);
                    while (ptr1 <= endptr1)
                    {
                        if (acc[l].acc_num == ac_rec_num)
                        {
                            acc[l].balance += amount_trans;
                            FILE *fw;
                            fw = fopen("accounts.dat", "w");
                            for (int i = 0; i < k; i++)
                            {
                                fwrite(&acc[i], sizeof(Account_details), 1, fw);
                            }
                            fclose(fw);
                            break;
                        }
                        else
                        {
                            l++;
                            ptr1 += sizeof(acc[0]);
                        }
                        m++;
                    }

                    break;
                }
                else
                {
                    if (!(strcmp(pass, acc[m].login_pass)))
                    {
                        printf("Not sufficient balance :(\nEnter the amount again:\n");
                        fflush(stdin);
                        scanf("%f", &amount_trans);
                        if (amount_trans < acc[m].balance)
                        {
                            printf("\nAmount transfered successfully\n");
                            printf("\nAmount before transaction %f\n", acc[m].balance);
                            acc[m].balance -= amount_trans;
                            printf("\nAmount left %f\n", acc[m].balance);
                            while (ptr1 <= endptr1)
                            {
                                if (acc[l].acc_num == ac_num)
                                {
                                    acc[l].balance += amount_trans;
                                    FILE *ffw;
                                    ffw = fopen("accounts.dat", "w");
                                    for (int i = 0; i < k; i++)
                                    {
                                        fwrite(&acc[i], sizeof(Account_details), 1, ffw);
                                    }
                                    fclose(ffw);
                                    break;
                                }
                                else
                                {
                                    l++;
                                    ptr1 += sizeof(acc[0]);
                                }
                                m++;
                            }
                            break;
                        }

                        r--;
                    }
                    else
                    {
                        printf("you have entered wrong password:\n");
                        printf("Enter password:\n");
                        fflush(stdin);
                        scanf("%s", pass);
                        if (!(strcmp(pass, acc[m].login_pass)))
                        {
                            // m++;
                            printf("\namt transferd successfully\n");
                            printf("\namt before transaction %f\n", acc[m].balance);
                            acc[m].balance -= amount_trans;
                            printf("\namt left %f\n\n", acc[m].balance);
                            while (ptr1 <= endptr1)
                            {
                                if (acc[l].acc_num == ac_rec_num)
                                {
                                    acc[l].balance += amount_trans;
                                    FILE *fw;
                                    fw = fopen("accounts.dat", "w");
                                    for (int i = 0; i < k; i++)
                                    {
                                        fwrite(&acc[i], sizeof(Account_details), 1, fw);
                                    }
                                    fclose(fw);
                                    break;
                                }
                                else
                                {
                                    l++;
                                    ptr1 += sizeof(acc[0]);
                                }
                                m++;
                            }
                            break;
                        }
                    }
                    --r;
                }
            }
        }
        else
        {
            m++;
        }
        ptr += sizeof(acc[0]);
    }
    if (flag)
        printf("account number not found!\n");
    char c = getchar();
    c = getchar();
    system("clear");
    encdec(0);
}
