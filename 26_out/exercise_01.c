#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}NODE;

NODE* createList(){
    NODE* first = NULL;
    return first;
}

NODE* insertElem(NODE* list, int info){
    NODE* newELem = malloc(sizeof(NODE));

    newELem->info = info;
    newELem->next = list;

    return newELem;
}

void passThroughList(NODE* list){
    NODE* aux;

    for (aux = list; aux != NULL; aux->next)
    {
        printf("%d", aux->info);
    }
    
}

NODE* searchElem(NODE* list, int searchKey){
    NODE* aux;

    for (aux = list; aux != NULL; aux->next)
    {
        if(aux->info == searchKey){
            return aux;
        }
    }
    return NULL;
}

NODE* removeElem(NODE* list, int deleteKey){
    NODE* aux = list;
    NODE* ant = NULL;

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

void freeList(NODE* list){
    NODE* aux = list;
    NODE* ref;

    while (aux != NULL)
    {
        ref = aux->next;
        free(aux);
        aux = ref;
    }
    

}

int main (){

    int op;
    do{
        printf("[1] - Create list\n");
        printf("[2] - Insert element\n");
        printf("[3] - Print list\n");
        printf("[4] - Search element\n");
        printf("[5] - Remove element\n");
        scanf("%d", &op);
    }while(op != 0);




    return 0;
}