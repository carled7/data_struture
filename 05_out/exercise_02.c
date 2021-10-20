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

void doubleSize(char** contacts, char** numbers, char** email){

    realloc(contacts, sizeof(char*) * SIZE * 2);
    realloc(numbers, sizeof(char*) * SIZE * 2);
    realloc(email, sizeof(char*) * SIZE * 2);
    system("clear");
    printf("reallocating memory...\n");
    sleep(2);
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

int menu (char** contacts, char** numbers, char** email, int* freeIndex){
    system("clear");

    int buffer;

    printf("=========== AGENDA ===========\n");
    printf("[1] - Save a contact\n");
    printf("[2] - Show contacts\n");
    printf("[3] - Delete contact\n");
    printf("[0] - Exit\n");
    printf("    --> ");
    scanf(" %d", &buffer);

    switch (buffer)
    {
    case 1:
        saveContact(contacts, numbers, email, *freeIndex);
        *freeIndex += 1;
        if(*freeIndex == SIZE){
            doubleSize(contacts, numbers, email);
        }
        break;
    case 2:
        system("clear");
        printContacts(contacts, numbers, email, *freeIndex);
        break;
   
    }
    
    return buffer;
}

int main (){
    char **contacts;
    char **numbers;
    char **email;
    int freeIndex = 0;
    contacts = malloc(sizeof(char*) * SIZE);
    numbers = malloc(sizeof(char*) * SIZE);
    email = malloc(sizeof(char*) * SIZE);
    int op = menu(contacts, numbers, email, &freeIndex);

    while (op != 0)
    {
        op = menu(contacts, numbers, email, &freeIndex);
    }
    
    printf("\nThe agenda has been closed\n\n");
    return 0;
}