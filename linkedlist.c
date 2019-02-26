#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"



///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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


///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void imprimeLinkedList (LinkedList *this)
{
    card *card=NULL;
    Node *p=this->pFirstNode;
                                                                ///  printf("\n\nFOO IMPRIME Node *p= %p\n", p);
         printf("\n %p->", p);

   if (p==NULL)
   {
      printf("\n FOO imprimeLinkedList: Linked List esta VACIA!!!");
   }

    while(p!=NULL)
    {
      card=p->pElement;
      printf("\n %p->\t", p);
      printf("S: %d  \t", card->suit);
      printf("V: %d  \t", card->value);
      printf(" this->size: %d", this->size);
      printf(" p->pNextNode %p", p->pNextNode);
      p=p->pNextNode;
    }

}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Node* Node_NewNode(char *nombreNewNode)
    {
        Node* newNode;
        newNode=(Node*)malloc(sizeof(Node));

     if (newNode== NULL)
    {
        printf("\nNO RESERVA MEMORIA PARA %s\n",nombreNewNode);
    }
    else
    {
        newNode->pNextNode=NULL;
      ///  printf("\n\tMemoria reservada para %s %p -> OK.\n",nombreNewNode, newNode);
    }
    return newNode;
}/// CLOSES FOO NODE NEW NODE
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void imprimeLinkedListData (LinkedList *this)
{
    card *carta;
    Node *p=this->pFirstNode;
    printf("\n %p->\n", p);

   if (p==NULL)
   {
      printf("\n FOO imprimeLinkedList: Linked List esta VACIA!!!");
   }

    while(p!=NULL)
    {
        carta=(card*)p->pElement;
        printf("%d suit %d   value: %d  ->\n", this->size,carta->suit, carta->value);
        p=p->pNextNode;
    }

}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

LinkedList* foo_Creates_Decks_Randomly ()
{
    card *nuevacarta;
    card *nuevacartatempNode;
    int agregarCarta=-1;
    int number_Of_Generated_Cards;

    Node *pNode=NULL;
    Node *tempNode=NULL;

    int opcion=0;

    card *cardPtr;
    LinkedList *Deck;
    Deck=ll_newLinkedList();
    pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly");
    tempNode=Node_NewNode("tempNode foo_Creates_Decks_Randomly");
    pNode->pNextNode=NULL;
    tempNode->pNextNode=NULL;


    do
    {
                                                        // printf("\ntempNode = Deck->pFirstNode\n");   ///  printf("\nELSE tempNode: %p\n", tempNode);

        if (Deck->pFirstNode==NULL)                                                                                      ///  printf("\nELSE tempNode->nextNode: %p\n", tempNode->pNextNode);
        {
             cardPtr=(card*)card_newCard();
             cardPtr=fooRandomizes_New_Card_Values ();
             pNode->pElement=cardPtr;
             Deck->pFirstNode= pNode;
             Deck->size++;
             agregarCarta=0;
           ///  system("pause");
        }

         cardPtr=(card*)card_newCard();
        cardPtr=fooRandomizes_New_Card_Values ();
        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly");
        pNode->pElement=cardPtr;
        tempNode=Deck->pFirstNode;
                                                                ///printf("\n\n\n tempNode: %p\n", tempNode);
                                                                ///printf("\n tempNode->pNextNode : %p\n", tempNode->pNextNode );
        while (tempNode->pNextNode != NULL)
        {
            nuevacarta=(card*)pNode->pElement;
            nuevacartatempNode= (card*)tempNode->pElement;

                if (nuevacarta->value==nuevacartatempNode->value)
                {
                    printf("\nnuevacarta->value= %d\t", nuevacarta->value);
                    printf("\tnuevacartatempNode->value= %d\n",nuevacartatempNode->value );
                    if (nuevacarta->suit==nuevacartatempNode->suit)
                        {
                            agregarCarta=-1;
                        }
                }
                tempNode= tempNode->pNextNode;
        }///CLOSES WHILE

            if (agregarCarta!=0)
            {
                printf("\nNO DEBE AGREGARSE LA CARTA\n");
                printf("\n NODO A LIBERAR: %p",pNode );
                //  free(pNode);
            }
            else
            {
                tempNode->pNextNode=pNode;
                pNode->pNextNode=NULL;
                Deck->size++;
            }
///system("pause");
        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        tempNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        pNode->pNextNode=NULL;
        tempNode->pNextNode=NULL;
       agregarCarta=0;

   ///    number_Of_Generated_Cards++;

    printf("\n\n\nFOO CREATES DECK RANDOM Deck->size: %d\n\n\n", Deck->size);
   /// system("pause");
    }while (Deck->size<52);

    printf("\n\n\n IMPRIME LIST DECK ANTES DE SALIR DE FOO CREA MAZO RANDOM\n\n\n");
    ///imprimeLinkedList(Deck);
    printf("\n\n\nFOO CREATES DECK RANDOM Deck->size FINAL: %d\n\n\n", Deck->size);
    printf("\n \n\n\n");
    system("pause");

    return Deck;
}
