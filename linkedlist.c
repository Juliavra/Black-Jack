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
    while(p!=NULL)
    {
        ///printf("\t %d->", p->pElement);
        printf("\t %p->", p->pNextNode);
        p=p->pNextNode;
    }


    /*
    ///TERMINAR Y CORREGIR

    Node *nextNode=NULL;
    Node *temp=NULL;
    card *imprimeNodo;

    printf("\nLinkedList *this->size: %d\n", this->size);
    printf("\nLinkedList *this->index: %d\n", this->index);
    printf("\nLinkedList *this->index: %p\n", this->pFirstNode);

    if (this->pFirstNode==NULL)
    {
        printf("EL PUNTERO this->pFirstNode == NULL");
    }
    else
    {
        temp=this->pFirstNode;
        printf("\nLinkedList *temp->index: %p\n", temp);
        nextNode=temp->pNextNode;
        printf("\nnextNode=temp->pNextNode: %p\n");
        printf("\ntemp->pNextNode: %p\n", temp->pNextNode);
        printf("\nnextNode: %p\n", nextNode);

                if (nextNode==NULL)
                {
                    printf("EL PUNTERO nextNode == NULL");
                }
                else
                {

                    imprimeNodo=(card*)nextNode->pElement;
                    printf("\n nextNode suit: %d\n", imprimeNodo->suit);
                }
    }
    //while
*/
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
