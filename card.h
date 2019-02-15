///CARD.H
///*************************************************************************************
///*************************************************************************************
#ifndef __CARD
#define __CARD


#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int suit;	///1- corazones / 2- picas / 3- diamantes / 4- trebol
    int value;	///1 al 13
} card;



///*************************************************************************************
///*************************************************************************************
///FOO DECLARATION

void fooCreatesCard (int *newCardValuePtr, int *newCardSuitPtr);
card* card_newCard(void);



#endif
