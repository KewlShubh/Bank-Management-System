typedef struct Account_details
{
    char name[30];
    char IFSC[20];
    int acc_num;
    double contact_number;
    float balance;
    char login_pass[20];
} Account_details;

static int i;

int Create_acc(Account_details *);
int Show_acc_det(Account_details *);