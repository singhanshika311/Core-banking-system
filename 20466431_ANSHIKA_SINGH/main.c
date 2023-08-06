#include<stdio.h>
#include "admin/admin.h"
#include "main.h"
#include "customer/customer.h"
#include <stdlib.h>
#include <string.h>


#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20
int main(){
    system("clear");
    printf("\033[31m -------------------------------WELCOME TO CORE BANKING SYSTEM------------------------\033[0m \n\n");
    printf("1. BANK STAFF(CLERK)\n\n");
    printf("2. CUSTOMER\n\n");
    printf("3. EXIT\n\n");
    int choice;
    printf("\033[31m Enter Your choice for role  : \033[0m");
    scanf(" %d",&choice);
    switch (choice)
    {
    case 1:{
        system("clear");
        char username[NAME_LENGTH];
        char password[PASSWORD_LENGTH];
        getlogindetails(username,password);
        break;
    }
    case 2:{
        //exit (0);
        system("clear");
        char username[NAME_LENGTH];
        char password[PASSWORD_LENGTH];
        getcustomerlogindetails(username,password);
       
        break;
    }
    case 3:
    {
        exit(0);
    }
    default:
        printf("invalid choice!!!!");
    }
    
    return 0;
}