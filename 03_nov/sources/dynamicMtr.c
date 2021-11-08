#include "dynamicMtr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2
#define LEN 50

void printContacts (char** contacts, char** numbers, char** email, int freeIndex){
    char buffer;
    system("clear");
    printf("\n========== CONTACTS ==========\n");
    for(int i = 0; i < freeIndex; ++i){
        printf("\nName: %s\n", contacts[i]);
        printf("Number: %s\n", numbers[i]);
        if(email[i]){
            printf("Email: %s\n", email[i]);
        }
        printf("\n");
    }
    printf("Press [0] to continue.\n");
    scanf(" %c", &buffer);
}

void saveContact(char** contacts, char** numbers, char** email, int freeIndex){
    system("clear");

    char nameBuffer[LEN], numBuffer[LEN], emailBuffer[LEN], op;
    printf("======== SAVE CONTACT ========\n");
    printf("Type the name: ");
    scanf(" %[^\n]s", nameBuffer); 
    printf("\nType the number: ");
    scanf(" %s", numBuffer);

    printf("\nDo you wanna add an email?[y/n] ");
    scanf(" %c", &op);
    if(op == 'y'){
        printf("\nType the email: ");
        scanf(" %[^\n]s", emailBuffer);
        email[freeIndex] = malloc(sizeof(char) * strlen(emailBuffer));
        strcpy(email[freeIndex], emailBuffer);
    }

    contacts[freeIndex] = malloc(sizeof(char) * strlen(nameBuffer));
    strcpy(contacts[freeIndex], nameBuffer);
    numbers[freeIndex] = malloc(sizeof(char) * strlen(numBuffer));
    strcpy(numbers[freeIndex], numBuffer);

}