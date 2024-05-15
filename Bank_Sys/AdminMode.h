/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : AdminMode.h
 * MADE IN 6 MAY 2024 10:54 PM
 */
#ifndef ADMINMODE_H
#define ADMINMODE_H
#include "ClientMode.h"
void AddClient(node **n,char *name,int age,int id,int balance,short password);
void RemoveClient(node *n,int id);
void ShowAllClients(node *n);
void ShowClient(node *n,int id);
void Edit(node *n,int id,char *name,int age,int balance,short password);
#endif //ADMINMODE_H
