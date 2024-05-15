/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : ClientMode.c
 * MADE IN 6 MAY 2024 11:12 PM
 */
#include "ClientMode.h"
void Deposit(node *n,int id,int balance,short password)
{
    node *k = n;
    while(k->id != id)
    {
        k = k->next;
    }
    if(k->password == password)
    {
        k->balance += balance;
        printf("Transaction has been made successfully\n");
    }
    else
    {
        printf("Password is wrong\n");
    }
}
void Withdraw(node *n,int id,int balance,short password)
{
    node *k = n;
    while(k->id != id)
    {
        k = k->next;
    }
    if(k->password == password)
    {
        k->balance -= balance;
        printf("Transaction has been made successfully\n");
    }
    else
    {
        printf("Password is wrong\n");
    }
}
void ShowData(node *n,int id,short password)
{
    node *k = n;
    while(k->id != id)
    {
        k = k->next;
    }
    if(k->password == password)
    {
        printf("name : %s   id : %i   age : %i   balance : %i $\n", k->name, k->id, k->age, k->balance);
    }
    else
    {
        printf("Password is wrong\n");
    }
}