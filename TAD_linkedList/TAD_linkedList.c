
#include "TAD_linkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct item{

    int info;
    ITEM* next;

} ITEM;

ITEM* createItem(ITEM* list){

    list = malloc(sizeof(ITEM));
    list->next = NULL;

    if(list != NULL){
        printf("\nThe item has been created");
        printf("\nType the value: ");
        scanf("%d", &list->info);
        return list;
    }

    return -1;
}

void freeList(ITEM* list){

    ITEM* aux = list;
    do{
        aux = list->next;
        printf("\n%d has been freed", list->info);
        free(list);
        list = aux;
    }while(list != NULL);

}



void insertElement(ITEM* list){

    //ITEM* aux = list;
    int buffer;

    while(list->next != NULL){
        list = list->next;
    }
    printf("\nType the value to insert: ");
    scanf("%d", &buffer);

    list->next = malloc(sizeof(ITEM));
    list->next->info = buffer;
    list->next->next = NULL;


}

void printList(ITEM* list){

    do{
        printf("\ninfo: %d", list->info);
        list = list->next;
    }while(list != NULL);

}

void searchItem(ITEM* list){

    int buffer, i=1;
    printf("\nType the element to search: ");
    scanf("%d", &buffer);
    ITEM* aux = list;

    while(aux != NULL){
        if(aux->info == buffer){
            break;
        }
        aux = aux->next;
        i++;
    }

    if(aux == NULL){
        printf("\nNot found");
        return;
    }else{
        printf("Element %d: %d", i, aux->info);
    }
    char op;
    printf("\nDo you want to remove this item?");
    printf("\n[y/n]  ");
    scanf(" %c", &op);

    if(op == 'y'){
        list = removeElem(list, aux->info);
    }
}

ITEM* removeElem(ITEM* list, int deleteKey){
    ITEM* aux = list;
    ITEM* ant = NULL;

    while ( aux != NULL && aux->info != deleteKey){
        ant = aux;
        aux = aux->next;
    }

    if ( aux == NULL ){
        return list;
    }

    if (ant == NULL){
        list = aux->next;
    } else {
        ant->next = aux->next;
    }

    free (aux);

    return list;
}
