#include <stdio.h>
#include <stdlib.h>
#define NAME 100
#define LEN 50 

void saveContact(){
    printf("\nsave contact");
}
void searchContact(){
    printf("\nsearch contact");
}
void deleteContact(){
    printf("\ndelete contact");
}

void menu (char contacts [][LEN], char numbers [][12]){
    system("clear");

    int buffer;
    printf("========AGENDA========\n");
    printf("[1] - Save a contact\n");
    printf("[2] - Search contact\n");
    printf("[3] - Delete contact\n");
    scanf("%d", &buffer);

    switch (buffer)
    {
    case 1:
        saveContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        deleteContact();
        break;    
    default:
        printf("Not valid\n");
        sleep(1);
        menu();
        break;
    }
}

int main (){
    char contacts [NAME][LEN];
    char numbers [NAME][12];
    menu(contacts, numbers);

    return 0;
}