#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif
