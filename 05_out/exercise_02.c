#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define LEN 50 

void doubleSize(char* contacts[], char* numbers[], char* email[]){

    realloc(contacts, sizeof(char) * SIZE * 2);
    realloc(numbers, sizeof(char) * SIZE * 2);
    realloc(email, sizeof(char) * SIZE * 2);

}
void saveContact(char* contacts [], char* numbers [], char* email[], int *freeIndex){
    system("clear");

    char nameBuffer[LEN], numBuffer[LEN], emailBuffer[LEN], op;
    printf("====== SAVE CONTACT ======\n");
    printf("Type the name: ");
    scanf(" %[^\n]s", nameBuffer); 
    printf("\nType the number: ");
    scanf(" %s", numBuffer);

    printf("\nDo you wanna add an email?[y/n] ");
    scanf(" %c", &op);
    if(op == 'y'){
        printf("\nType the email: ");
        scanf(" %[^\n]s", emailBuffer);
        email[*freeIndex] = malloc(sizeof(char*) * strlen(emailBuffer));
        strcpy(email[*freeIndex], emailBuffer);
    }

    contacts[*freeIndex] = malloc(sizeof(char*) * strlen(nameBuffer));
    strcpy(contacts[*freeIndex], nameBuffer);
    numbers[*freeIndex] = malloc(sizeof(char*) * strlen(numBuffer));
    strcpy(numbers[*freeIndex], numBuffer);

}
/*
void printContact(char contacts [][LEN], char numbers [][12], int printIndex){
    system("clear");
    printf("====== CONTACT ======\n");
    printf("Name: %s\n", contacts[printIndex]);
    printf("Number: %s\n", numbers[printIndex]);
    sleep(2);
}

int searchContact(char contacts [][LEN], char numbers [][12], int *freeIndex){

    char searchKey [LEN];
    int searchIndexResult, currentSearchCorrespondence = 0, greaterSearchCorrespondence = 0;
    printf("Type the name: ");
    scanf(" %[^\n]s", searchKey);

    for (int i = 0; i < *freeIndex; ++i){
        currentSearchCorrespondence = 0;
        for (int t = 0; contacts[i][t] != '\0'; ++t){
            if(searchKey[t] == contacts[i][t]){
                ++currentSearchCorrespondence;
            }
        }
        if(currentSearchCorrespondence > greaterSearchCorrespondence){
            greaterSearchCorrespondence = currentSearchCorrespondence;
            searchIndexResult = i;
        }
    }
    return searchIndexResult;
}

void deleteContact(char contacts [][LEN], char numbers [][12], int deleteIndex, int *freeIndex){
    for (int i = deleteIndex; i < *freeIndex; ++i){
        strcpy(contacts[i], contacts[i + 1]);
        strcpy(numbers[i], numbers[i + 1]);
    }
    --*freeIndex;
    printf("Contact deleted\n");
    sleep(2);
}
*/

int menu (char* contacts [], char* numbers [], char* email[],  int *freeIndex){
    system("clear");

    int buffer;
    printf("======= AGENDA =======\n");
    printf("[1] - Save a contact\n");
    printf("[2] - Search contact\n");
    printf("[3] - Delete contact\n");
    printf("[0] - Exit\n");
    printf("    --> ");
    scanf(" %d", &buffer);

    switch (buffer)
    {
    case 1:
        saveContact(contacts, numbers, email, &*freeIndex);
        ++*freeIndex;
        if(*freeIndex == (strlen(*contacts) - 1)){
            //doubleSize(contacts, numbers, email);
        }
        break;
    case 2:
        system("clear");
        printf("======== SEARCH ========\n");
        //printContact(contacts, numbers, searchContact(contacts, numbers, &*freeIndex));
        break;
    case 3:
        system("clear");
        printf("======== DELETE ========\n");
        //int toDelete = searchContact(contacts, numbers, &*freeIndex);
        //deleteContact(contacts, numbers, toDelete, &*freeIndex);
        break;
    }
    
    return buffer;
}

int main (){
    char* contacts [SIZE];
    char* numbers [SIZE];
    char* email[SIZE];
    int freeIndex = 0;
    int op = menu(contacts, numbers, email, &freeIndex);

    while (op != 0)
    {
        op = menu(contacts, numbers, email, &freeIndex);
    }
    
    printf("\nThe agenda has been closed\n\n");
    return 0;
}