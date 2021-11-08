
    void printContacts (char** contacts, char** numbers, char** email, int freeIndex);
/*      lists all the contacts that has been inserted.

        how to call it:
            printContacts(contacts, numbers, email, *freeIndex) */

    void saveContact(char** contacts, char** numbers, char** email, int freeIndex);
/*      saves a contact with name, number and optional email, it
        alocates the exact amount of memory to each string.

        how to call it:
            saveContact(contacts, numbers, email, *freeIndex)   */

