/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : ClientMode.h
 * MADE IN 6 MAY 2024 11:12 PM
 */
#ifndef CLIENTMODE_H
#define CLIENTMODE_H
#include "LinkedList.h"
void Deposit(node *n,int id,int balance,short password);
void Withdraw(node *n,int id,int balance,short password);
void ShowData(node *n,int id,short password);
#endif //CLIENTMODE_H
