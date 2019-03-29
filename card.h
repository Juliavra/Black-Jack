///CARD.H
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef __CARD
#define __CARD


#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "scenario.h"



typedef struct
{
    int suit;	///1- corazones / 2- picas / 3- diamantes / 4- trebol
    int value;	///1 al 13
} card;



///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///FOO DECLARATION

LinkedList* foo_New_Deck(void);
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
int foo_Adds_Cards_Value (LinkedList *this);
int foo_Adds_Cards_Value_Banca (LinkedList *this);
int foo_Suit_To_Print (card *this);
int foo_Value_To_Print (card *this);
void foo_Prints_Hand(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna);

void foo_Card_ConStruct_Empty(int XFila, int YColumna, escenarioPosicionXY scene[]);
void foo_Prints_Hand_Banca(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna);
void foo_Prints_Hand_Banca_Shows_Both_Cards(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna);
void foo_Prints_Hand_Double(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna);
void foo_Prints_Hand_Split(LinkedList *playerOne_1st, LinkedList *playerOne_2nd, escenarioPosicionXY scene[], int XFila, int YColumna);
void foo_Card_Erase_From_Scenario(int XFila, int YColumna, escenarioPosicionXY scene[]);

#endif
