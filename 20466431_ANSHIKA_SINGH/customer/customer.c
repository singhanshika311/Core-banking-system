#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "customer.h"  // customer header file
#include "../main.h"   

#define NAME_LENGTH 50         // MICROS
#define PASSWORD_LENGTH 20

char session[20];      // storing customer userid
char AccountSession[20];   // storing customer account number

// customer logout function

void custlogout() {
    printf("\033[33m ------- Customer Logged out successfully.-------\033[0m \n");
    main();
   // exit(0);
  
}

// customer can view his details which are present in account created by admin(clerk)

void viewDetails(){
    system("clear");
    FILE* fp = fopen("textfile/AccInfo.txt", "r");
    strcpy(trans.custid,session);
    printf("%s",trans.custid);
    printf("\033[31m --------------------------------CUSTOMER DETAILS------------------------------\033[0m \n");
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", Add.acc_no, Add.customerId, Add.name, Add.accType, Add.addres1, Add.addres2, Add.addres3, Add.city, Add.state, Add.country, Add.pinCode, Add.number, Add.email, Add.pan)!=EOF)
    {
        if(strcmp(Add.customerId, trans.custid)==0)
        {
            printf("Customer Account number : %s\n", Add.acc_no);
            printf("Customer Unique ID : %s\n", Add.customerId);
            printf("Customer name : %s\n", Add.name);
            printf("Customer Account type : %s\n", Add.accType);
            printf("Customer Address : %s %s %s\n", Add.addres1,Add.addres2,Add.addres3);
            printf("Customer City : %s\n", Add.city);
            printf("Customer State : %s\n", Add.state);
            printf("Customer Country : %s\n", Add.country);
            printf("Customer pincode : %s\n", Add.pinCode);
            printf("Customer Number : %s\n", Add.number);
            printf("Customer Email : %s\n", Add.email);
            printf("Customer Pan : %s\n", Add.pan);
        }
    }
}

// customer can trasfer money from his account to another account. 

void transferMoney(){
    system("clear");
    //char date[20];

    strcpy(transactionn.src,AccountSession);                //source account number
    strcpy(transactionn.accountno,AccountSession); 

    printf("\033[31m \nEnter destination Customer Account no where you want to send money  \033[0m");
    scanf("%s", transactionn.dst);                         //destination number
    
    //self transfer validation
    if(strcmp(transactionn.src,transactionn.dst)==0)
    {
        printf("cannot transfer money to yourself!!!");
        return;
    }
    
    FILE* fp = fopen("textfile/passbook.txt", "a+");
    rewind(fp);
    FILE* tmp = fopen("textfile/customerTransaction.txt", "a+");   // for storing customer transaction records
    rewind(tmp);
    int flag=0;

    //reading passbook file
    while(fscanf(fp,"%s %s %s %s %d %s %lf  \n" ,AddAcc.accountno, AddAcc.transactionDate, AddAcc.name, AddAcc.type, &AddAcc.transactionId, AddAcc.status, &AddAcc.balance)!=EOF)
    {
        if((strcmp(AddAcc.accountno,transactionn.dst)==0))
        {
            flag=1;
            destDetail=AddAcc;
        }
        if(strcmp(AddAcc.accountno,AccountSession)==0)
        {
            srcDetail=AddAcc;
        }
    }
    if(flag==0)
    {
        printf("\naccount not exist try another account");
        return;
    }


    label:
    printf("\nEnter amount which you want to transfer");
    scanf("%lf",&transactionn.amount); //transfer account

    //transaction amount validaton
    if(transactionn.amount<0)
    {
        printf("please enter valid amount to transfer try again!!!!");
        goto label;
    }                    
    

    time_t currentTime=time(NULL);
    struct tm*localTime=localtime(&currentTime);
    char date[11];
    strftime(date,sizeof(date) , "%Y-%m-%d" , localTime);

    strcpy(srcDetail.transactionDate,date);
    strcpy(destDetail.transactionDate,date);

    // transfer amount validation
    if(srcDetail.balance<transactionn.amount)
    {
        printf("\n\ninnsufficient balance !!!!!");
        return;
    }

    srcDetail.balance-=transactionn.amount;
    destDetail.balance+=transactionn.amount;

    srcDetail.transactionId=AddAcc.transactionId+1;
    destDetail.transactionId=AddAcc.transactionId+2;


    //storing data in passbook file to store transaction history

    fprintf(fp, "%s %s %s %s %d %s %.2lf\n", srcDetail.accountno, srcDetail.transactionDate, srcDetail.name, srcDetail.type,  srcDetail.transactionId, "Debit", srcDetail.balance);
    fprintf(fp, "%s %s %s %s %d %s %.2lf\n", destDetail.accountno, destDetail.transactionDate, destDetail.name, destDetail.type,  destDetail.transactionId, "Credit", destDetail.balance);
    
    if(ftell(tmp)==0)
    {
        transactionn.TransID=1000;
    }

    while(fscanf(tmp,"%d %s %s %s %lf %s",&temp.TransID,temp.type,temp.src,temp.dst,&temp.amount,temp.accountno)!=EOF)
    {
        transactionn.TransID=temp.TransID+1;
    }

    strcpy(transactionn.type,"saving");

    //storing data in customer_transaction file to store transaction details
    fprintf(tmp,"%d %s %s %s %.2lf %s\n",transactionn.TransID,transactionn.type,transactionn.src,transactionn.dst,transactionn.amount,transactionn.accountno);
    printf("\033[33m \nTransfer done safely!!!!!\033[0m \n\nYour Balance is  %.2lf",srcDetail.balance);
    fclose(fp);
    fclose(tmp);
}

// customer can able to view his all transactions 

void transactionReport()
{
    system("clear");
    FILE* tmp = fopen("textfile/customerTransaction.txt", "r");
    int flag=0;
    printf("\033[32m TID\tDESTINATION ACCOUNT NUMBER \tTRANSACTION TYPE\t AMOUNT TRANSFERED\n\033[0m");
    while(fscanf(tmp,"%d %s %s %s %lf %s",&temp.TransID,temp.type,temp.src,temp.dst,&temp.amount,temp.accountno)!=EOF)
    {
        if(strcmp(temp.src,AccountSession)==0)
        {
            flag=1;
            printf("%d    %s                        %s                %.2lf \n",temp.TransID,temp.dst,"debited",temp.amount);
        }
        else if(strcmp(temp.dst,AccountSession)==0)
        {
            flag=1;
            printf("%d    %s                        %s                %.2lf \n",temp.TransID,temp.src,"credited",temp.amount);
        }
    }
    if(flag==0)
    {
        printf("NO TRANSACTION DATA FOUND!!!!");
    }
}

// customer menu 

void customermenuLogin() {
    system("clear");
    int choice;
    do {
        printf("\033[31m \n----------------------------------CUSTOMER LOGIN: --------------------------------\n\033[0m");
        printf("1. View customer detail\n");
        printf("2. Transfer money to another account\n");
        printf("3. Query/Report on transaction\n");
        printf("4. Quit Application\n");
        printf("------------------------------------Enter your choice: --------------------");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                viewDetails();
                break;
            case 2:
                transferMoney();
                break;
            case 3:
                transactionReport();
                break;
            case 4:
                custlogout();
                break;
            default:
                printf("I-----------invalid choice. Please try again.-------------\n");
                break;
        }
    } while (1);
}

// customer login function (customer userid)

int customerlogin(char *username,char *password) {
    
    FILE *fp;
    char user[NAME_LENGTH];
    char pass[PASSWORD_LENGTH];
    char acc[20];
    fp = fopen("textfile/Customer.txt", "r");
    if(fp == NULL)
    {
        printf("Error: Unable to open users file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s", user, pass, acc) == 3)
    {
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
            strcpy(session,username);
            strcpy(AccountSession,acc);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;   
}

// login function validation 

void getcustomerlogindetails(char *username,char *password)
{
    //system("clear");
    printf("\033[31m----------------------------Enter Login Details(bank_customer)----------------------------- \033[0m \n");
    
    printf("\nEnter your userid(bank_customer): ");
    scanf("%s", username);

    printf("Enter your password(bank_customer): ");
    scanf("%s", password);
    if (customerlogin(username, password))
    {
        printf("\033[33m-----Customer Successfully Logged in....\033[0m \n\n\n");
        customermenuLogin();
    }
    else{
        printf("Invalid Credentials!!! please enter valid details\n");
        getcustomerlogindetails(username,password);
    }
    
}