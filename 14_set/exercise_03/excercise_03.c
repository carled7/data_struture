#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 100
#define LEN 50 

void saveContact(char contacts [][LEN], char numbers [][12], int *freeIndex){
    system("clear");
    printf("====== SAVE CONTACT ======\n");
    printf("Type the name: ");
    scanf(" %[^\n]s", contacts[*freeIndex]);
    printf("\nType the number: ");
    scanf(" %s", numbers[*freeIndex]);

}

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

int menu (char contacts [][LEN], char numbers [][12], int *freeIndex){
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
        saveContact(contacts, numbers, &*freeIndex);
        ++*freeIndex;
        break;
    case 2:
        system("clear");
        printf("======== SEARCH ========\n");
        printContact(contacts, numbers, searchContact(contacts, numbers, &*freeIndex));
        break;
    case 3:
        system("clear");
        printf("======== DELETE ========\n");
        int toDelete = searchContact(contacts, numbers, &*freeIndex);
        deleteContact(contacts, numbers, toDelete, &*freeIndex);
        break;
    }
    
    return buffer;
}

int main (){
    char contacts [NAME][LEN];
    char numbers [NAME][12];
    int freeIndex = 0;
    int op = menu(contacts, numbers, &freeIndex);

    while (op != 0)
    {
        op = menu(contacts, numbers, &freeIndex);
    }
    
    printf("\nThe agenda has been closed\n\n");
    return 0;
}