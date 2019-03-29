#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#include "linkedlist.h"

#define FILA 24
#define COLUMNA 80
#define TAMANIOPANTALLA 1920

typedef struct
{
    int escenarioXFila;
    int escenarioYColumna;
    int charAImprimir;
    int Lethality;
} escenarioPosicionXY;

typedef struct
{
    int playerXFila;
    int playerYColumna;
    int charAImprimir;
} playerPosicionXY;


void initEscenario (escenarioPosicionXY scene[]);
void fooprintsScenario (escenarioPosicionXY scene []);

void fooFrameConstruct(int XFila, int YColumna, int largoCaja, int altoCaja, escenarioPosicionXY scene[], int puertaHorizontal, int puertaVertical);
void fooSquareConstruct(int XFila, int YColumna, int largoCaja, int altoCaja, escenarioPosicionXY scene[], int entrada, int salida);
void fooConstructMinefield(int XFila, int YColumna, int largoCaja, int altoCaja, escenarioPosicionXY scene[]);
void setSpecialChars (escenarioPosicionXY scene[]);
void fooConstructHorizontalLine (int XFila, int YColumna, int largoRecta, escenarioPosicionXY scene[]);
void fooConstructVerticalLine (int XFila, int YColumna, int largoRecta, escenarioPosicionXY scene[]);
void faceMessages (escenarioPosicionXY scene[], char faceMessage[]);
void eraseFaceMessage (escenarioPosicionXY scene[]);
void intro (int XFila, int YColumna, escenarioPosicionXY scene[]);
void eraseIntro (int XFila, int YColumna, escenarioPosicionXY scene[]);
void foo_Sets_Face (escenarioPosicionXY scene[]);
int scenarioReturnsScenePosition (int XFila, int YColumna);
void prints_Bets_Values (escenarioPosicionXY scene[]);
void foo_Prints_Header_BJack (escenarioPosicionXY scene[], int *betAmountPtr, int playerOneCards, int *creditsPtr, /*BORRAR LUEGO*/ int bancaCards);
void foo_Resolves_After_player_Choice (escenarioPosicionXY scene[], int controlValue);
void initial_Bet_Screen (escenarioPosicionXY scene[]);
void screen_Player_Plays (escenarioPosicionXY scene[], LinkedList *playerOne, LinkedList *banca, int controlValue, int *isDoublePtr, int * isSplitPtr);

#endif
