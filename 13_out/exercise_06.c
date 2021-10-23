#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2
#define LEN 50 

typedef struct contact
{
    char* nome;
    char* telefone;
    char* email;
}CONTACT;


void printContacts (CONTACT* agenda, int freeIndex){
    char buffer;
    system("clear");
    printf("\n========== CONTACTS ==========\n");
    for(int i = 0; i < freeIndex; ++i){
        printf("\nName: %s\n", (agenda[i]).nome);
        printf("Number: %s\n", (agenda[i]).telefone);
        if((agenda[i]).email){
            printf("Email: %s\n", (agenda[i]).email);
        }
        printf("\n");
    }
    printf("Press [0] to continue.\n");
    scanf(" %c", &buffer);
}

void saveContact(CONTACT* agenda, int freeIndex){
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
        (agenda[freeIndex]).email = malloc(sizeof(char) * strlen(emailBuffer));
        strcpy((agenda[freeIndex]).email, emailBuffer);
    }

    (agenda[freeIndex]).nome = malloc(sizeof(char) * strlen(nameBuffer));
    strcpy((agenda[freeIndex]).nome, nameBuffer);
    (agenda[freeIndex]).telefone = malloc(sizeof(char) * strlen(numBuffer));
    strcpy((agenda[freeIndex]).telefone, numBuffer);

}

int menu (CONTACT* agenda, int* freeIndex){
    system("clear");

    int buffer;

    printf("=========== AGENDA ===========\n");
    printf("[1] - Save a contact\n");
    printf("[2] - Show contacts\n");
    printf("[0] - Exit\n");
    printf("    --> ");
    scanf(" %d", &buffer);

    switch (buffer)
    {
    case 1:
        saveContact(agenda, *freeIndex);
        *freeIndex += 1;
        break;
    case 2:
        system("clear");
        printContacts(agenda, *freeIndex);
        break;
   
    }
    
    return buffer;
}

int main (){

    int agendaLen = 2, op = 1;
    CONTACT* agenda = malloc(sizeof(CONTACT) * agendaLen);

    int freeIndex = 0;

    while (op != 0)
    {
        op = menu(agenda, &freeIndex);
    }
    
    printf("\nThe agenda has been closed\n\n");
    return 0;
}