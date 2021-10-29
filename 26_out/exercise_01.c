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

NODE* insertElem(NODE* list, int info){
    NODE* newELem = malloc(sizeof(NODE));

    newELem->info = info;
    newELem->next = list;

    return newELem;
}

void passThroughList(NODE* list){
    NODE* aux;

    for (aux = list; aux != NULL; aux = aux->next)
    {
        printf("%d", aux->info);
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

void menu(NODE* list, int op){

    switch (op)
    {
    case 1:
        list = createList();
        system("clear");
        printf("List created\n");
        //sleep(2);
        break;
    case 2:
        system("clear");
        int num;
        printf("Type the number to insert: ");
        scanf(" %d", &num);
        list = insertElem(list, num);
        printf("Number has been inserted\n");
        //sleep(2);
        break;
    case 3:
        system("clear");
        passThroughList(list);
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    
    }

}

int main (){

    int op;
    NODE* list;
    do{
        system("clear");
        printf("[1] - Create list\n");
        printf("[2] - Insert element\n");
        printf("[3] - Print list\n");
        printf("[4] - Search element\n");
        printf("[5] - Remove element\n");
        scanf("%d", &op);

        menu(list, op);

    }while(op != 0);

    return 0;
}