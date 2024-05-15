/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : LinkedList.h
 * MADE IN 6 MAY 2024 8:28 PM
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nl
{
    char *name;
    int id;
    int age;
    int balance;
    short password;
    struct nl *next;
}node;


#endif //LINKEDLIST_H
