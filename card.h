///CARD.H
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef __CARD
#define __CARD


#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int suit;	///1- corazones / 2- picas / 3- diamantes / 4- trebol
    int value;	///1 al 13
} card;



///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///FOO DECLARATION

LinkedList* foo_New_Deck();
card* fooRandomizes_New_Card_Values (void);
int fooRandomizes_New_Card_Value (void);
int fooRandomizes_New_Card_Suit(void);
card* card_newCard(void);
int setCardSuit(card* this, int suit);
int getCardSuit (card* this);
int setCardValue(card* this, int value);
int getCardValue (card* this);
card* cardCalloc_newCard(void);


int foo_Compare_Decks (LinkedList *Deck, LinkedList *other);
int foo_Already_In_Deck (LinkedList *this, card* thiscard);



#endif
