///********************************************************************************************************************************************************
///********************************************************************************************************************************************************
/// BLACK JACK EUROPEO
/// RULES
/// entre 4 y 8 mazos
/// 2 al 10 igual a su valor
/// As= 1 u 11
/// 1- Apuesta Inicial
/// 2- Dos cartas descubiertas al jugador, una al croupier
/// 3- Cada Player puede
///
/// 1. PEDIR
/// PIDE UNA CARTA

/// 2. PLANTARSE
/// FINALIZA SU TURNO


/// 3. DOBLAR
/// (SOLO LAS 2 PRIMERAS CARTAS). APUESTA IGUAL A LA INICIAL. AL DOBLAR SE RECIBE UNA CARTA MAS
///
/// 4. SEPARAR
///
/// 5. RENDIRSE
///
/// 6. APUESTA DE SEGURO
///--------------------
///CROUPIER

/// Si 16 o <  DEBE PEDIR
/// Si 17      DEBE PLANTARSE
/// AS vale 11 excepto q se pase
///--------------------


///init vars
///{
///    Create scene
///    Shuffle deck
///}

///Takes bets
///Deals cards
///Player(s) Play
///AI Plays
///Prizes & losses
///Goto Takes bets

#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "linkedlist.h"
#include "card.h"



///********************************************************************************************************************************************************
///********************************************************************************************************************************************************

int main()
{

    ///Node *pFirstNode;
    Node *pNode;

    int opcion=0;
    int newCardSuit=0;
    int newCardValue=0;
    int *newCardSuitPtr=NULL;
    int *newCardValuePtr=NULL;

    newCardSuitPtr=&newCardSuit;
    newCardValuePtr=&newCardValue;;

    card *Ptr;                               ///               printf("card *Ptr;\n");            printf("\tCHECK: card *Ptr= %p;\n", Ptr);

    LinkedList *Deck;
    Deck=ll_newLinkedList();                         printf("\n chek ll_newLinkedList  Deck: %p\n", Deck);
                                                    ///printf("\tCHECK: Deck.iNDeX= %d;\n", Deck->index);
                                                    ///printf("\tCHECK: Deck.size= %d;\n", Deck->size);
                                                    ///printf("\nCHECK MAIN Deck->pFirstNode=%p", Deck->pFirstNode);
    pNode=Node_NewNode();                      printf("\t\tCHECK: Deck.FirstNode= %p;\n", Deck->pFirstNode);
   /// Deck->pFirstNode= pNode;                           printf("\t\tCHECK: Deck.FirstNode= %p;\n", Deck->pFirstNode);

system("pause");
                                                            ///Ptr=(card*)cardCalloc_newCard();
                                                            ///printf("\nPtr=(card*)cardCalloc_newCard();\n");
                                                            ///printf("\nCHECK Ptr suit %d\t", Ptr->suit);
                                                           /// printf("CHECK  Ptr value %d\n", Ptr->value);
    do
    {

    Ptr=(card*)card_newCard();
    fooRandomizes_New_Card_Values (&newCardValue, &newCardSuit);     ///printf("\t\tMAIN newCardValuePtr: %d \t newCardSuitPtr: %d\n", *newCardValuePtr, *newCardSuitPtr);
    setCardSuit(Ptr, newCardSuitPtr);                       printf("\n ASS CHECK Ptr suit %d\t", Ptr->suit);
    setCardValue(Ptr, newCardValuePtr);                      printf("\nASS CHECK  Ptr value %d\n", Ptr->value);
    pNode->pElement=Ptr;                               ///printf("\npNode: %d",pNode);///printf("\npFirstNode->pElement: %d",pFirstNode->pElement);
                                                                ///printf("\nPtr: %d",Ptr);


///ARMAR BIEN ESTOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

    if(Deck->pFirstNode==NULL)
    {
        printf("\nDeck.pFirstNode==NULL\n");
         Deck->pFirstNode= pNode;
         Deck->size++;
         printf("\nDeck.pFirstNode==pNode\n");
         printf("\nDeck.pFirstNode= %p\n",Deck->pFirstNode );
         printf("\nDeck->size= %d\n", Deck->size);
    }
    else
    {
        pNode=pNode->pNextNode;
    }
                                                            ///printf("\n Deck.pFirstNode== %p\t",Deck->pFirstNode);
                                                            /// printf("\n pFirstNode.pNextNode== %p\n",pFirstNode->pNextNode);
    imprimeLinkedList (Deck);

    printf("\n\nDESEA SEGUIR? (!=1)\n ? ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n    opcion: %d", opcion);

   }
    while (opcion!=1);


    printf("   SALIENDO\n\n\n");
    system("pause");

///system("pause");
    return 0;
}

///*********************************************************************************************************************************************************************************








