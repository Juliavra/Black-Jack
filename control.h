#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "linkedlist.h"

#define FILA 24
#define COLUMNA 80
#define TAMANIOPANTALLA 1920


int Bet_Options (void);
int player_Menu_Options (void);
int player_Choice_Resolution_Full (int controlValue);

int foo_Machine_Plays (LinkedList *banca, LinkedList *Deck);

void foo_Double_Tap_The_Table (LinkedList *playerOne_1st, LinkedList *Deck);

void deals_Two_Cards_To_Each_Player (LinkedList *Deck, LinkedList *playerOne_1st, LinkedList *banca);
int Calculates_controlValue (LinkedList *banca, LinkedList *playerOne);
int stillAlive (int playerOneCards);
int who_Wins (int bancaCards, int playerOneCards);

void Credits_Minus_betAmount (int *creditsPtr, int *betAmountPtr);

Node* gets_First_Card(LinkedList *Deck);

#endif
