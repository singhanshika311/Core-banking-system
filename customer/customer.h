 struct{
    char acc_no[20];
    char customerId[10];
    char name[50];
    char accType[50];
    char addres1[50];
    char addres2[50];       //customer structure
    char addres3[50];
    char city[50];
    char state[50];
    char country[50];
    char pinCode[50];
    char number[15];
    char email[50];
    char pan[50];
}cust, Add;

struct{
    char accountno[20];     //passbook structure
    char name[50];
    char type[10];
    int transactionId;
    char status[10];
    double balance;
    char transactionDate[15];
}AddAcc,srcDetail,destDetail;


struct{
    int userid;
    char custid[50];
    char pass[20];            // customer structure
    char usertype[20];
    int loginstatus;
}customerdetail,trans;

struct{
    int TransID;        //customer transaction structure
    char type[10];
    char src[15];
    char dst[15];
    double amount;
    char accountno[15];
}transactionn,temp;
 

void logout();
int customerlogin(char *username,char *password);       // function prototype

void getcustomerlogindetails(char *username,char *password);