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

void fooRandomizes_New_Card_Values (int *newCardValuePtr, int *newCardSuitPtr);
card* card_newCard(void);
int setCardSuit(card* this, int *newCardSuitPtr);
int getCardSuit (card* this);
int setCardValue(card* this, int *newCardValuePtr);
int getCardValue (card* this);

card* cardCalloc_newCard(void);

#endif
