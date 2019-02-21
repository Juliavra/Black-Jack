#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"



///-----------------------------------------------------
LinkedList* ll_newLinkedList(void)
{
    LinkedList* ll_newLinkedList=NULL;
    printf("\n FOO CHECK ll_newLinkedList: %p\n", ll_newLinkedList);

    ll_newLinkedList=(LinkedList*)malloc(sizeof(LinkedList));

    printf("\n FOO CHECK post MALLOC ll_newLinkedList: %p\n", ll_newLinkedList);
    if (ll_newLinkedList==NULL)
    {
        printf("NO MEMORIA PARA LLIST");
    }
    else
    {
        ll_newLinkedList->index=0;
        ll_newLinkedList->size=0;
        ll_newLinkedList->pFirstNode=NULL;
    }

    return ll_newLinkedList;
}


///-------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------
void imprimeLinkedList (LinkedList *this)
{

    Node *p=this->pFirstNode;
  ///  printf("\n\nFOO IMPRIME Node *p= %p\n", p);
     printf("\n %p->", p);

   if (p==NULL)
   {
      printf("\n FOO imprimeLinkedList: Linked List esta VACIA!!!");
   }

    while(p!=NULL)
    {
        printf(" %p->", p->pNextNode);
        p=p->pNextNode;
    }

}

///--------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------
    Node* Node_NewNode(void)
    {
        Node* newNode;
        newNode=(Node*)malloc(sizeof(Node));

     if (newNode== NULL)
    {
        printf("NO RESERVA MEMORIA PARA newNode");
    }
    else
    {
        newNode->pNextNode=NULL;
        printf("\n\tMemoria reservada para newNode %p -> OK.\n", newNode);
    }
    return newNode;
}/// CLOSES FOO NODE NEW NODE
///--------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------





///-------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------
void imprimeLinkedListData (LinkedList *this)
{
    card *carta;
    Node *p=this->pFirstNode;
    printf("\n %p->", p);

   if (p==NULL)
   {
      printf("\n FOO imprimeLinkedList: Linked List esta VACIA!!!");
   }

    while(p!=NULL)
    {
        carta=(card*)p->pElement;
        printf(" suit %d   value: %d  ->\n",carta->suit, carta->value);
        p=p->pNextNode;
    }

}

///--------------------------------------------------------------------------------------------------------------------------------------
