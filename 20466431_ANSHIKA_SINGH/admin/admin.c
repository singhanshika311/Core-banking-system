#include <stdio.h>
#include "admin.h"    //admin header file
#include "../main.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>         // header files and MICROS
#include <termios.h>
#include <ctype.h>
#include <stdbool.h>

#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

void fordelay(int);
void logout();            // function prototype
void clarkLogin();

int sec=0;
clock_t stopclock=CLOCKS_PER_SEC;

int i,j;
int main_exit;

//admin can add customer

void addAccount(){
    system("clear");
    FILE *ptr;
    ptr=fopen("textfile/AccInfo.txt","a+");    // storing customer account information
    FILE *new;
    new=fopen("textfile/Customer.txt","a+");   // storing customer userid and password for customer login
    
    FILE* tmp = fopen("textfile/passbook.txt", "a+"); 
   
    long accno=9678456231;
    int userid=224003;
    char name[50];

    if(ftell(new)!=0)
    {
    rewind(new);
    while(fscanf(new,"%d %s %ld",&userid,name,&accno)!=EOF)
    {
        continue;
    }}
    system("clear");
    printf("\033[31m--------------Customer Resistration---------------  \033[0m");
    //srand(time(0));
    sprintf(add.acc_no,"%ld",accno+1);
    sprintf(add.customerId,"%d",userid+1);
    strcpy(user.custid,add.customerId);
    //user.userid=rand();
    
    label1:
    printf("\n\n\nEnter customer Name : ");
    scanf(" %[^\n]%*c",add.name);
    int i=0;
    while(add.name[i]!='\0')
    {
        if(!isalpha(add.name[i]) && !isspace(add.name[i]))
        {
            printf("invalid character found");
            goto label1;
            break;
        }
        i++;
    }


    label2:
    printf("\nEnter customer Password : ");
    scanf(" %[^\n]%*c",user.pass);
    if(strlen(user.pass)<8)
    {
        printf("password should be greater than 8");
        goto label2;
    }
    

    label3:
    printf("\nType of account:\n\t#saving\n\t#current\n\nEnter Account type : ");
    scanf(" %[^\n]%*c",add.accType);
    if((strcmp(add.accType,"saving")!=0) && (strcmp(add.accType,"current")!=0))
    {
        printf("invalid choice enter correct option");
        goto label3;
    }

    printf("\nEnter customer Address 1 : ");
    scanf(" %[^\n]%*c",add.addres1);
    printf("\nEnter customer Address 2 : ");
    scanf(" %[^\n]%*c",add.addres2);
    printf("\nEnter customer Address 3 : ");
    scanf(" %[^\n]%*c",add.addres3);
    printf("\nEnter city : ");
    scanf(" %[^\n]%*c",add.city);
    printf("\nEnter State : ");
    scanf(" %[^\n]%*c",add.state);
    printf("\nEnter Country : ");
    scanf(" %[^\n]%*c",add.country);


    label4:
    printf("\nEnter pincode: ");
    scanf(" %[^\n]%*c",add.pinCode);
    int j=0;
    while(add.pinCode[j]!='\0')
    {
        if(!isdigit(add.pinCode[j]))
        {
            printf("invalid character found");
            goto label4;
            break;
        }
        j++;
    }


    label5:
    printf("\nEnter phone number : ");
    scanf(" %[^\n]%*c",add.number);
    if((strlen(add.number)>10) || (strlen(add.number)<10))
    {
        printf("phone number length should be 10 digits!!!!!");
        goto label5;
    }
    int z=0;
    while(add.number[z]!='\0')
    {
        if(!isdigit(add.number[z]))
        {
            printf("invalid character found it should be digitt!!!!");
            goto label5;
            break;
        }
        z++;
    }


    label6:
    printf("\nEnter Email : ");
    scanf(" %[^\n]%*c",add.email);
    int symbol= -1;
    for(int k=0;add.email[k] !='\0';k++)
    {
        if(add.email[k] == '@')
        {
            symbol=k;
            break;
        }
    }
    if(symbol == -1)
    {
        printf("plz give valid email!!!!");
        goto label6;
    }

    int dotsymbol= -1;
    for(int k=0;add.email[k] !='\0';k++)
    {
        if(add.email[k] == '.')
        {
            dotsymbol=k;
            break;
        }
    }
    if(dotsymbol == -1)
    {
        printf("plz give valid email!!!!");
        goto label6;
    }
    
    label7:
    printf("\nEnter Pan : ");
    scanf(" %[^\n]%*c",add.pan);
    if(strlen(add.pan)!=10)
    {
        printf("enter valid pan number");
        goto label7;
    }
    for(int i=0;i<5;i++)
    {
        if(!isalpha(add.pan[i]) || islower(add.pan[i])) 
        {
            printf("enter valid pan number");
            goto label7;
        }
    }
    for(int i=5;i<9;i++)
    {
        if(!isdigit(add.pan[i]))
        {
            printf("enter valid pan number");
            goto label7;
        }
    }
    if(!isalpha(add.pan[9]) || islower(add.pan[9]))
    {
        printf("enter valid pan number");
        goto label7;
    }



    // storing custoner details in AccInfo file
    fprintf(ptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan);
    
    // storing custoner id passward in customer.txt file so that customer can login.
    fprintf(new,"%s %s %s\n", user.custid, user.pass, add.acc_no);

    time_t currentTime=time(NULL);
    struct tm*localTime=localtime(&currentTime);
    char date[11];
    int flag=0;
    strftime(date,sizeof(date) , "%Y-%m-%d" , localTime);
    rewind(tmp);

    // reading passbook file so that we can fetch transaction id.
    while(fscanf(tmp,"%s %s %s %s %d %s %lf \n",newacc.accountno, newacc.transactionDate, newacc.name, newacc.type, &newacc.transactionId, newacc.status, &newacc.balance)!=EOF)
    {
        flag=1;
        continue;
    }
    if(flag==0)
    {
        newacc.transactionId=999;
    }
    strcpy(newacc.transactionDate,date);

    // entering new account cretion data in passbook file.

    fprintf(tmp,"%s %s %s %s %d %s %.2lf \n",add.acc_no, newacc.transactionDate, add.name, add.accType, newacc.transactionId+1, "A/C", 0.0);
    

    fclose(ptr);

    fclose(new);

    fclose(tmp);
    
    printf("\033[33m\nAccount created successfully!\033[0m");
    printf("\n\n\nYour Account number is : %s",add.acc_no);
    printf("\n\nYour Customer ID is : %s\n\n",add.customerId);

    add_invalid :
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("clear");
    if (main_exit==1)
        clarkLogin();
    else if(main_exit==0)
        logout();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }  
}

// admin can delete customer account

void deleteAccount(){
    system("clear");
    FILE *old, *newrec,*oldCred,*newCred;
    int test=0;

    // deleation from AccInfo file
    old=fopen("textfile/AccInfo.txt","r");  //reading account information of customers which is store by admin
    newrec=fopen("textfile/newFile.txt","w"); // storing updated information of customer after deletion
    
    // deleation from customer.txt file
    oldCred=fopen("textfile/Customer.txt","r");  // reading customer login details 
    newCred=fopen("textfile/newCustomer.txt","w"); // storing updated customer login details after deletion
    char userId[100],password[100],accountNo[100];

    printf("\033[31m Enter account number of the customer you want to delete : \033[0m");
    scanf("%s",rem.acc_no);   //storing account number which is to be deleted

    while(fscanf(old, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan) != EOF)
    {   
        fscanf(oldCred,"%s %s %s ",userId,password,accountNo);

        if(strcmp(add.acc_no,rem.acc_no)!=0){

            fprintf(newrec, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan);
            fprintf(newCred,"%s %s %s \n",userId,password,accountNo);
        }else{

            test++;
            printf("\033[33m\n Record deleted successfully !! \033[0m \n");
        }
    }
    fclose(old);
    fclose(newrec);
    fclose(oldCred);
    fclose(newCred);
    remove("textfile/AccInfo.txt");
    rename("textfile/newFile.txt", "textfile/AccInfo.txt");  //updating customer information file
    remove("textfile/Customer.txt");
    rename("textfile/newCustomer.txt", "textfile/Customer.txt");  //updating customer login details file

    if(test == 0){
        printf("\n Record not found!!!");
        delete_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            clarkLogin();
        else if (main_exit==2)
            logout();
        else if(main_exit==0)
            deleteAccount();
        else
        {
            printf("\nInvalid!\a");
            goto delete_invalid;
        }
    }
    else
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("clear");
        if (main_exit==1)
            clarkLogin();
        else
        {
            logout();
        }     
    }

}

//admin can modify customer details

void modifyDetails(){
    system("clear");
    FILE* fp = fopen("textfile/AccInfo.txt", "r");   // reading customer information which is stored by admin
   // temporary file
    FILE* tmp = fopen("textfile/temp.txt", "w");   // storing modifed customer information
    int found = 0;
    printf("\nEnter customer accountno : ");
    scanf(" %[^\n]%*c",upd.acc_no);
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan)!=EOF) {
        if(strcmp(upd.acc_no,add.acc_no)==0) {
            found = 1;
            printf("enter choice");
            printf("enter 1 for name update 2 for address update 3 for number update 4 for email update");
            int ch;
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
            {
            printf("\nEnter Updated Name: ");
            scanf("%[^\n]%*c", add.name);
            break;
            }
            case 2:
            {
            printf("Enter Address: ");
            scanf("%[^\n]%*c", add.addres1);
            break;
            }
            case 3:
            {
            printf("Enter Phone Number: ");
            scanf("%[^\n]%*c", add.number);
            break;
            }
            case 4:
            {
            printf("Enter Email: ");
            scanf("%[^\n]%*c", add.email);  
            }
            }
            found = 1;
        }
        fprintf(tmp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan);
    
    }
    fclose(fp);
    fclose(tmp);

   if(found) {
        remove("textfile/AccInfo.txt");
        rename("textfile/temp.txt", "textfile/AccInfo.txt");  //updating modified customer details file
        printf("\033[33mCustomer modified successfully!\033[0m\n");
    } 
    else {
        remove("textfile/temp.txt");
        printf("Customer not found!\n");
    }
}

//admin can credit money into customer account by his account number

void creditMoney()
{
    system("clear");
    double amt;
    FILE* fp = fopen("textfile/AccInfo.txt", "r");
    FILE* tmp = fopen("textfile/passbook.txt", "a+");   //storing all transaction details done by admin(clerk)
    printf("\033[31m---------------DEPOSITING MONEY--------------------\033[0m");

    printf("\n\nEnter your account number : ");
    scanf(" %s", deposit.accountno);
    int flag=0;

    time_t currentTime=time(NULL);
    struct tm*localTime=localtime(&currentTime);
    char date[11];
    strftime(date,sizeof(date) , "%Y-%m-%d" , localTime);
    strcpy(deposit.transactionDate,date);


    //checking in AccInfo if account exist or not

    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan)!=EOF) {
        if(strcmp(deposit.accountno, add.acc_no)==0) 
        {
            flag=1;
            strcpy(deposit.name,add.name);
            strcpy(deposit.type,add.accType);
        }
    }
    if(!flag)
    {
        printf("account doest exits!!!!!");
        return;
    }

    lable:
    printf("Enter amount you want to deposit : ");
    scanf(" %lf", &amt);
    if(amt<0)
    {
        printf("invalid amount!!! please enter valid amount \n");
        goto lable;
    }
    flag=0;
    if(ftell(tmp)==0)
    {
        deposit.transactionId=1000;
    }

    rewind(tmp);

    //checking in passbook and credit money

    while(fscanf(tmp,"%s %s %s %s %d %s %lf  \n" ,addAcc.accountno, addAcc.transactionDate, addAcc.name, addAcc.status,  &addAcc.transactionId, addAcc.status, &addAcc.balance)!=EOF)
    {
        if(strcmp(addAcc.accountno,deposit.accountno)==0) 
        {
            flag=1;
            deposit.balance=addAcc.balance+amt;
        }
        deposit.transactionId=addAcc.transactionId+1;
    }
   
    if(!flag)
    {
        deposit.balance=amt;
    }
    
    printf("\033[33m Money is Deposited \033[0m \n\n");
    printf("current balance in account is %.2lf\n\n", deposit.balance);

    fprintf(tmp,"%s %s %s %s %d %s %.2lf \n",deposit.accountno, deposit.transactionDate, deposit.name, deposit.type,  deposit.transactionId, "Credit", deposit.balance);
    
    fclose(fp);
    fclose(tmp);
    printf("\n\n\n\t\tEnter 1 to continue to credit money. Enter 2 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("clear");
    if (main_exit==1)
        creditMoney();
    else if(main_exit==2)
        clarkLogin();
    else{
        logout();
    }  
}

//admin can debit money from customer account by his account number

void debitMoney()
{
    system("clear");
    double amt;
    FILE* fp = fopen("textfile/AccInfo.txt", "r");
    FILE* tmp = fopen("textfile/passbook.txt", "a+");  //storing transaction details done by admin(clerk)
    printf("\033[31m---------------Debit MONEY--------------------\033[0m");
    printf("\n\nEnter your account number : ");
    scanf(" %s", withdraw.accountno);
   
    time_t currentTime=time(NULL);
    struct tm*localTime=localtime(&currentTime);
    char date[11];
    strftime(date,sizeof(date) , "%Y-%m-%d" , localTime);
    strcpy(withdraw.transactionDate,date);

    int flag=0;

    //checking account is exist or not in customer information file(AccInfo.txt)

     while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", add.acc_no, add.customerId, add.name, add.accType, add.addres1, add.addres2, add.addres3, add.city, add.state, add.country, add.pinCode, add.number, add.email, add.pan)!=EOF) {
        if(strcmp(withdraw.accountno, add.acc_no)==0) 
        {
            flag=1;
            strcpy(withdraw.name,add.name);
            strcpy(withdraw.type,add.accType);
        }
    }
    if(!flag)
    {
        printf("account doest exits!!!!!");
        return;
    }
    label:
    printf("Enter amount you want to withdraw : ");
    scanf(" %lf", &amt);
    if(amt<0)
    {
        printf("negative number is entered please enter valid amount !!!\n");
        goto label;
    }
    flag=0;
    if(ftell(tmp)==0)
    {
        printf("insufficient balance !!!!!");
        return;
        //withdraw.transactionId=1000;
    }
    flag=0;
    rewind(tmp);
    while(fscanf(tmp,"%s %s %s %s %d %s %lf  \n" ,addAcc.accountno, addAcc.transactionDate, addAcc.name, addAcc.type,  &addAcc.transactionId, addAcc.status, &addAcc.balance)!=EOF)
    {
        if(strcmp(addAcc.accountno,withdraw.accountno)==0) 
        {
            
            if(amt<=addAcc.balance)          //withdraw amount validation 
            {
                withdraw.balance=addAcc.balance-amt;
                flag=0;
            }
            else
            {
                flag=1;
            }
            
        }
        withdraw.transactionId=addAcc.transactionId;
    }
    withdraw.transactionId++;

    if(flag==1)
    {
        system("clear");
        printf("Insufficient balannce !!!!"); 
        withdraw.balance=addAcc.balance;
        return;
    }
    
    printf("\033[33m Money is debited ...\033[0m \n");
    printf("\ncurrent balance in account is %.2lf", withdraw.balance);
    fprintf(tmp,"%s %s %s %s %d %s %.2lf \n",withdraw.accountno, withdraw.transactionDate, withdraw.name, withdraw.type,  withdraw.transactionId, "Debit", withdraw.balance);
   
    fclose(fp);
    fclose(tmp);
    printf("\n\n\n\t\tEnter 1 to continue to withdraw money. Enter 2 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("clear");
    if (main_exit==1)
        debitMoney();
    else if(main_exit==2)
        clarkLogin();
    else{
        logout();
    }  
}

//admin(clerk) can able to view his all transaction by account number

void getTransactionDetails(){
    system("clear");
    FILE* fp = fopen("textfile/passbook.txt", "r");
    printf("\033[31m Enter the Account no you want to get transaction Details : \033[0m ");
    scanf(" %s",transact.accountno);
    printf("Transaction Report\n");
    printf("\033[32mAccount_number\ttransaction_Date\t   Name\tAccount_Type\tTransaction_Id\t Transaction_Type\tBalance \033[0m\n");
       
    while(fscanf(fp,"%s %s %s %s %d %s %lf  \n" ,addAcc.accountno, addAcc.transactionDate, addAcc.name, addAcc.type,  &addAcc.transactionId, addAcc.status, &addAcc.balance) != EOF)
    {
        if(strcmp(addAcc.accountno, transact.accountno)==0)
        {
            printf("%s\t%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%.2lf\n",addAcc.accountno, addAcc.transactionDate, addAcc.name, addAcc.type,  addAcc.transactionId, addAcc.status, addAcc.balance);
        }
    }
}

// admin logout function 

void logout() {
    printf("\033[33m------- Admin Logged out successfully.-------\033[0m\n");
    main();
    //exit(0);
}

//admin(clerk) menu

void clarkLogin() {
    system("clear");
    int choice;
    do {
        printf("\033[31m\n-----------------------Banking Menu: ---------------------\033[0m\n");
        printf("\n1. Add a customer into the system to an account\n");
        printf("2. Delete a customer from the system\n");
        printf("3. Modify a customer's details\n");
        printf("4. Credit money to the customer\n");
        printf("5. Debit money from the customer account\n");
        printf("6. Query/Report on customer account & transactions\n");
        printf("7. Quit Application\n");
        printf("\033[31m\nEnter your choice : \033[0m");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                deleteAccount();
                break;
            case 3:
                modifyDetails();
                break;
            case 4:
                creditMoney();
                break;
            case 5:
                debitMoney();
                break;
            case 6:
                getTransactionDetails();
                break;
            case 7:
                logout();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);
}

//admin login 

int login(char *username,char *password) {
    
    FILE *fp;
    char user[NAME_LENGTH];
    char pass[PASSWORD_LENGTH];

    fp = fopen("admin/admin.txt", "r");
    //rewind(fp);
    if(fp == NULL)
    {
        printf("Error: Unable to open users file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %s", user, pass) == 2)
    {
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
        char newpass[10];
        fscanf(fp , "%s %s", user , pass);
        printf("enter updated pass");
        scanf("%s", newpass);
        fclose(fp);

        FILE *fpp = fopen("admin/admin.txt", "w");
        fprintf(fpp ,"%s %s", user, newpass);
        fclose(fpp);
            //fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;   
}

// admin login validation

void getlogindetails(char *username,char *password)
{
    printf("Enter Your Login Details \n");
    
    printf("\nEnter your username: ");
    scanf("%s", username);

    

    printf("Enter your password: ");
    
    scanf("%s", password);
    if (login(username, password))
    {
        printf("password is matching please wait !!!!!!!!!!!!!!!!");
        system("clear");
        fordelay(5);
        printf("\033[33m Admin Successfully Logged in....\033[0m");
        clarkLogin();
    }
    else{
        printf("Invalid Credentials!!! please enter valid details\n");
        getlogindetails(username,password);
    }
    
}



void fordelay(int j)
{
    while(sec < j)
    {
        if(clock()>stopclock)
        {
            stopclock+=1000000;
            printf(".");
            fflush(stdout);
            sec++;
        }
    }
}

