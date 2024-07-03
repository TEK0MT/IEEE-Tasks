/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : main.c
 * MADE IN 6 MAY 2024 8:26 PM
 */

//file handling file name Clients.txt
#include "Data.h"
node *n = NULL;
int UserEnd(node **k)
{
    int choice = 0;
    int choice2 = 0;
    int id = 0;
    char c[50];
    int age = 0;
    int balance = 0;
    short password = 0;
    printf("Enter your mode :\n 1-Admin Mode\n 2-ClientMode\n 3-Exit\n");
    scanf("%i",&choice);
    switch(choice)
    {
        case 1 :
            printf("Select the Request :\n1-Add Client\n2-Remove Client\n3-Show all Clients\n4-Show Client\n5-Edit Client\n");
            scanf("%i",&choice2);
            switch(choice2)
            {
                case 1:
                    printf("Enter the name : ");
                    scanf("%s", c);
                    fflush(stdin);
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    printf("Enter the age : ");
                    scanf("%i", &age);
                    printf("Enter the balance : ");
                    scanf("%i", &balance);
                    printf("Enter the password : ");
                    scanf("%hd", &password);
                    AddClient(k,c,age,id,balance,password);
                    break;
                case 2:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    RemoveClient(n,id);
                    break;
                case 3:
                    ShowAllClients(*k);
                break;
                case 4:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    ShowClient(*k,id);
                    break;
                case 5:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    printf("Enter the name : ");
                    scanf("%s", c);
                    fflush(stdin);
                    printf("Enter the age : ");
                    scanf("%i", &age);
                    printf("Enter the balance : ");
                    scanf("%i", &balance);
                    printf("Enter the password : ");
                    scanf("%hd", &password);
                    Edit(*k,id,c,age,balance,password);
                    break;
                default :
                    printf("Wrong Input \n");
                    break;

            }
            break;
        case 2:
            printf("Select the Request :\n1-Deposit\n2-Withdraw\n3-ShowData\n");
            scanf("%i",&choice2);
            switch(choice2)
            {
                case 1:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    printf("Enter the balance : ");
                    scanf("%i", &balance);
                    printf("Enter the password : ");
                    scanf("%hd", &password);
                    Deposit(*k,id,balance,password);
                    break;
                case 2:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    printf("Enter the balance : ");
                    scanf("%i", &balance);
                    printf("Enter the password : ");
                    scanf("%hd", &password);
                    Withdraw(*k,id,balance,password);
                    break;
                case 3:
                    printf("Enter the Id : ");
                    scanf("%i", &id);
                    printf("Enter the password : ");
                    scanf("%hd", &password);
                    ShowData(*k,id,password);
                    break;
                default :
                    printf("Wrong Input\n");
                    break;
            }
            break;
        case 3:
            choice = 0;
            break;
    }
    return choice;
}
int main(void) {
    load_file_data(&n);
    int flag = 1;
    while(flag)
    {
        flag = UserEnd(&n);
    }
    savefile(n);
    return 0;
}
