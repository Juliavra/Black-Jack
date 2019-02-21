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
    card *nuevacarta;
    card *nuevacartatempNode;
    int agregarCarta=-1;

    Node *pNode=NULL;
    Node *tempNode=NULL;

    int opcion=0;
    int newCardSuit=0;
    int newCardValue=0;
    int *newCardSuitPtr=NULL;
    int *newCardValuePtr=NULL;

    newCardSuitPtr=&newCardSuit;
    newCardValuePtr=&newCardValue;;

    card *Ptr;
    LinkedList *Deck;
    Deck=ll_newLinkedList();

    do
    {
        pNode=Node_NewNode();
        printf("\nreserva para el pNode ");
        tempNode=Node_NewNode();
        printf("\nreserva para el nodo temp");

        pNode->pNextNode=NULL;
        tempNode->pNextNode=NULL;

        Ptr=(card*)card_newCard();
        fooRandomizes_New_Card_Values (&newCardValue, &newCardSuit);
        setCardSuit(Ptr, newCardSuitPtr);
        setCardValue(Ptr, newCardValuePtr);
        pNode->pElement=Ptr;




        if(Deck->pFirstNode==NULL)
        {
                                                                                                printf("\nDeck.pFirstNode ES NULL\n");
            Deck->pFirstNode= pNode;
                                                                                                printf("\nDeck.pFirstNode==pNode\n");
                                                                                                printf("\n CHECK Deck.pFirstNode= %p\n",Deck->pFirstNode );
            Deck->size++;
                                                                                                printf("\n CHECK Deck->size= %d\n", Deck->size);
        }
        else
        {
                                                                                                printf("\n\n\nDeck.pFirstNode NO ES NULL!!!\n\n\n");
            tempNode = Deck->pFirstNode;
                                                                                                printf("\ntempNode = Deck->pFirstNode\n");
                                                                                                printf("\nELSE tempNode: %p\n", tempNode);
                                                                                                printf("\nELSE tempNode->nextNode: %p\n", tempNode->pNextNode);

            while (tempNode->pNextNode != NULL)
            {

                nuevacarta=(card*)pNode->pElement;
                nuevacartatempNode= (card*)tempNode->pElement;

                if (nuevacarta->value==nuevacartatempNode->value)
                {
                    printf("\nnuevacarta->value= %d\n", nuevacarta->value);
                    printf("\nnuevacartatempNode->value= %d\n",nuevacartatempNode->value );
                    printf("\nnuevacarta->value==nuevacartatempNode->value\n");
                    ///system("pause");

                    if(nuevacarta->suit==nuevacartatempNode->suit)
                    {
                        printf("\nnuevacarta->suit= %d\n", nuevacarta->suit);
                        printf("\nnuevacartatempNode->suit= %d\n",nuevacartatempNode->suit);
                        printf("\nnuevacarta->suit==nuevacartatempNode->suit\n");
                        agregarCarta=-1;
                        system("pause");
                    }

                }

                ///printf("WHILE ");
                tempNode= tempNode->pNextNode;
                ///printf("\nELSE2 tempNode->nextNode: %p\n", tempNode->pNextNode);
                ///printf("\nELSE2 tempNode->pElement: %p\n", tempNode->pElement);
            }/// CLOSES while (tempNode->pNextNode != NULL)

            if (agregarCarta==0)
            {
                tempNode->pNextNode=pNode;
                pNode->pNextNode=NULL;
            }

                printf("NO DEBE AGREGARSE LA CARTA");
        }

///foo_Already_In_Deck (Deck,Ptr);
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------








///-----------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------
        imprimeLinkedList (Deck);
        printf("\n\n\n");
        imprimeLinkedListData (Deck);

        printf("\n---------------------------------------------------------------------------------\n");
///system("pause");

        printf("\n\nDESEA SEGUIR? (!=1)\n ? ");
        fflush(stdin);
        scanf("%d", &opcion);

    }
    while (opcion!=1);


    printf("   SALIENDO\n\n\n");
    system("pause");

///system("pause");
    return 0;
}

///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
int main()
{
    Node *pNode=NULL;
    Node *tempNode=NULL;

    int opcion=0;
    int newCardSuit=0;
    int newCardValue=0;
    int *newCardSuitPtr=NULL;
    int *newCardValuePtr=NULL;

    newCardSuitPtr=&newCardSuit;
    newCardValuePtr=&newCardValue;;

    card *Ptr;
    LinkedList *Deck;
    Deck=ll_newLinkedList();
                                                                                printf("\n\npNode=Node_NewNode();\n");
    pNode=Node_NewNode();                                                       printf("\n\tCHECK: Deck.FirstNode= %p\n", Deck->pFirstNode);
                                                                                printf("\nDeck->pFirstNode= pNode;\n");
   Deck->pFirstNode= pNode;                                                        printf("\n\tCHECK: Deck.FirstNode= %p\n", Deck->pFirstNode);

   imprimeLinkedList (Deck);

    system("pause");

    do
    {
  ///pNode=Node_NewNode();
        Ptr=(card*)card_newCard();
        fooRandomizes_New_Card_Values (&newCardValue, &newCardSuit);     ///printf("\t\tMAIN newCardValuePtr: %d \t newCardSuitPtr: %d\n", *newCardValuePtr, *newCardSuitPtr);
        setCardSuit(Ptr, newCardSuitPtr);                                     printf("\n ASS CHECK Ptr suit %d\t", Ptr->suit);
        setCardValue(Ptr, newCardValuePtr);                                      printf("\nASS CHECK  Ptr value %d\n", Ptr->value);
        pNode->pElement=Ptr;                               ///printf("\npNode: %d",pNode);///printf("\npFirstNode->pElement: %d",pFirstNode->pElement);

printf("\ntempNode=Node_NewNode()\n");
        tempNode=Node_NewNode();            printf("\nRECIEN NCREADO tempNode: %p\n", tempNode);
        tempNode->pNextNode=NULL;           printf("\nRECIEN NCREADO tempNode->PNEXTNODE: %p.\n", tempNode->pNextNode);


///ARMAR BIEN ESTOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

        if(Deck->pFirstNode==NULL)
        {
            printf("\nDeck.pFirstNode==NULL\n");
            Deck->pFirstNode= pNode;                                    printf("\nDeck.pFirstNode==pNode\n");  printf("\n CHECK Deck.pFirstNode= %p\n",Deck->pFirstNode );
            Deck->size++;                                               printf("\n CHECK Deck->size= %d\n", Deck->size);
imprimeLinkedList (Deck);
        }
        else
        {
            printf("\n ELSE Deck.pFirstNode==NULL\n");
            tempNode = Deck->pFirstNode;                                            printf("\ntempNode = Deck->pFirstNode\n");             printf("\nELSE tempNode: %p\n", tempNode);
                                                                                   printf("\nELSE tempNode->nextNode: %p\n", tempNode->pNextNode);

            if (tempNode->pNextNode==NULL)
            {
                                                                            ///printf("\nIF tempNode->pNextNode==NULL");  printf("\nIF tempNode: %p", tempNode);
                                                                            ///printf("\nIF  tempNode->nextNode: %p", tempNode->pNextNode);
               /// tempNode->pNextNode=pNode;      ///ESTO ESTA MALLLLLLLL TOMA LA DIRECCION DOS VECES

                                                                            ///printf("\nIF tempNode: %p", tempNode);
                                                                            ///printf("\nIF  tempNode->nextNode: %p", tempNode->pNextNode);
                Deck->size++;
                                                                        printf("\nDeck->size= %d\n", Deck->size);
            }
            else
            {
            printf("\nELSE DE tempNode->pNextNode==NULL");
            ///Deck->size++;                                               printf("\n CHECK Deck->size= %d\n", Deck->size);

                  while (tempNode->pNextNode != NULL)
                tempNode= tempNode->pNextNode ;

                tempNode->pNextNode = pNode;
            }

        }
*/

/*while (tempNode->pNextNode != NULL)
  tempNode= tempNode->pNextNode ;

tempNode->pNextNode = pNode;
*/
/*        ///printf("\n Deck.pFirstNode== %p\t",Deck->pFirstNode);
        /// printf("\n pFirstNode.pNextNode== %p\n",pFirstNode->pNextNode);
        printf("\n---------------------------------------------------------------------------------\n");
        system("pause");

        printf("\n\nDESEA SEGUIR? (!=1)\n ? ");
        fflush(stdin);
        scanf("%d", &opcion);
        printf("\n    opcion: %d", opcion);

        imprimeLinkedList (Deck);
    }
    while (opcion!=1);


    printf("   SALIENDO\n\n\n");
    system("pause");

///system("pause");
    return 0;
}
*/
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------







