struct {
    char acc_no[20];
    char customerId[10];
    char name[50];
    char accType[50];
    char addres1[50];
    char addres2[50];
    char addres3[50];
    char city[50];              //customer information structure
    char state[50];
    char country[50];
    char pinCode[50];
    char number[15];
    char email[50];
    char pan[50];
}add,upd,check,rem,transaction;

struct{
    char accountno[20];
    char name[50];
    char type[10];                      //passbook
    int transactionId;
    char status[10];
    double balance;
    char transactionDate[15];
}addAcc,deposit,withdraw, transact, newacc;



struct{
    int userid;
    char custid[50];
    char pass[20];            // customer structure
    char usertype[20];
    int loginstatus;
}user;



void logout();
void clarkLogin();                          //function prototype
int login(char *username,char *password);
void getlogindetails(char *username,char *password);