/*
 * AUTHOR : MOHAMED TAREK
 * FILE NAME : Data.h
 * MADE IN 13 MAY 2024 5:35 PM
 */
#include "Data.h"
void savefile(node *n)
{
    FILE *file = fopen(FILEDATA,"w");
    if(file == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        node *k = n;
        while(k != NULL)
        {
            fprintf(file,"%s %i %i %i %i\n",(k->name),k->id,k->age,k->balance,k->password);
            k = k->next;
        }
        fclose(file);
    }
}
void load_file_data(node **n) {
    FILE *file = fopen(FILEDATA, "r");
    char c[50];
    int id;
    int age;
    int balance;
    short pass;

    if (file == NULL) {
        printf("Error opening file for reading\n");
    } else {
        node *k = *n;
        int itemsRead;
        while ((itemsRead = fscanf(file, "%49s %i %i %i %hd", c, &id, &age, &balance, &pass)) == 5) {
            AddClient(n, strdup(c), age, id, balance, pass); // strdup to allocate memory for name
        }
        if (itemsRead != EOF) {
            printf("Error reading from file\n");
        }
        fclose(file);
    }
}
