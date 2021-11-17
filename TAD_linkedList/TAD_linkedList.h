
typedef struct item ITEM;

ITEM* createItem(ITEM* list);

void freeList (ITEM* list);

void insertElement(ITEM* list);

void printList(ITEM* list);

void searchItem(ITEM* list);

ITEM* removeElem(ITEM* list, int deleteKey);
