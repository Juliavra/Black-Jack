#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList{
    Node* pFirstNode;
    int size;
    int index;
}typedef LinkedList;

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* ll_newLinkedList(void);
Node* Node_NewNode(char *nombreNewNode);
void imprimeLinkedList (LinkedList *this);
LinkedList* foo_Creates_Decks_Randomly (void);
Node* foo_Finds_Last_Node (LinkedList *this);
Node* foo_Finds_First_Node_And_Removes_It (LinkedList *this);
int foo_Are_initial_Cards_Equal (LinkedList *this);
LinkedList* foo_HARCODE_DATA_DECK(LinkedList *this);
LinkedList* ll_clone(LinkedList* this);
/*
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
*/

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif
