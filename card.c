
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"

void fooCreatesCard (int *newCardValuePtr, int *newCardSuitPtr)      ///TIENE Q RECIBIR DOS PUNTEROS IICIALIZADOS EN NULL, CARAGAR EL RANDOM Y REVISAR Q AMBOS SEAN !=NULL Y pasar return 1 como exit 0 como failure
{
    int suit=0, value=0, opcion=0;


            printf("\t\tFOO INIT newCardValuePtr: %d\t newCardSuitPtr: %d\n", newCardValuePtr, newCardSuitPtr);

        suit = 1 + ( rand() % 4 );
        value = 1 + ( rand() % 13 );
        printf("\t\tFOO carta suit: %d\t value: %d\n", suit, value);

        *newCardValuePtr=value;
        *newCardSuitPtr=suit;



        printf("\t\tFOO newCardValuePtr: %d \t newCardSuitPtr: %d\n", *newCardValuePtr, *newCardSuitPtr);

}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
card* card_newCard(void)
{
card* Card = (card*)malloc(sizeof(card));
return Card;
}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
void setCard(void)
{

}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
void getCard(void)
{

}
