#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* next;
};

typedef struct node NODE;

NODE* createList(){
    NODE* first = NULL;
    return first;
}

NODE* insertElemStart(NODE* list, int info){
    NODE* newELem = malloc(sizeof(NODE));

    newELem->info = info;
    newELem->next = list;

    return newELem;
}

void insertElemEnd(NODE* list, int info){

    NODE* current = list;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = malloc(sizeof(NODE));
    current->next->info = info;
    current->next->next = NULL;

}

void passThroughList(NODE* list){
    NODE* aux;
    int i = 0;
    for (aux = list; aux != NULL; aux = aux->next)
    {
        ++i;
        printf("[%d] - %d\n", i, aux->info);
    }
    
}

NODE* searchElem(NODE* list, int searchKey){
    NODE* aux;

    for (aux = list; aux != NULL; aux = aux->next)
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

void menu(NODE* list){

    int op, buffer;

    do{
        system("clear");
        printf("[1] - Create list\n");
        printf("[2] - Insert element\n");
        printf("[3] - Print list\n");
        printf("[4] - Search element\n");
        printf("[5] - Remove element\n");
        printf("[6] - Insert element at the end\n");
        printf("[0] - Exit ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            list = createList();
            system("clear");
            printf("List created\n");
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        case 2:
            system("clear");
            int num;
            printf("Type the number to insert: ");
            scanf(" %d", &num);
            list = insertElemStart(list, num);
            printf("Number has been inserted\n");
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        case 3:
            system("clear");
            passThroughList(list);
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        case 4:
            system("clear");
            int toSearch;
            printf("Type the number to search: ");
            scanf(" %d", &toSearch);
            NODE* result = searchElem(list, toSearch);
            printf("Result: %d", result->info);
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        case 5:
            system("clear");
            int toDel;
            printf("Type the number to delete: ");
            scanf(" %d", &toDel);
            list = removeElem(list, toDel);
            printf("The element has been removed\n");
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        case 6:
            system("clear");
            int numAtEnd;
            printf("Type the number to insert: ");
            scanf(" %d", &numAtEnd);
            insertElemEnd(list, numAtEnd);
            printf("Number has been inserted\n");
            printf("\n\n[0] - Back ");
            scanf("%d", &buffer);
            break;
        }
    }while(op != 0);
    freeList(list);
}

int main (){

    NODE* list;
           
    menu(list);

    return 0;
}