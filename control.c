#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "control.h"
#include "linkedlist.h"
#include "card.h"

#define FILA 24
#define COLUMNA 80
#define TAMANIOPANTALLA 1920


int Bet_Options (void)
{
    int betValue=0;
    char bet;
    do
    {
        fflush(stdin);
        bet=getche();
        printf("bet: %d", bet);
        switch (bet)
        {
        case 49:
        {
            betValue=100;
            break;
        }
        case 50:
        {
            betValue=200;
            break;
        }
        case 51:
        {
            betValue=300;
            break;
        }
        case 52:
        {
            betValue=400;
            break;
        }
        default:
        {
            bet=0;
            break;
        }
        }///closes switch
    }
    while (bet<48 || bet > 52);
    return betValue;
}///CLOSES FOO

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int player_Choice_Resolution_Full (int controlValue)
{
    int flag=0;
    ///Node *tempNode=NULL;
    char playerChoice;
   // printf("\nplayerChoice: %c\n", playerChoice);
  /// printf("\ncontrolValue: %d\n", controlValue);
    ///system("pause");

    switch(controlValue)
    {
    case 1: ///1-HIT  2-STAND  3-GIVE UP
    {
        do
        {
         ///   printf("CASE controlValue== 1 \n");
            fflush(stdin);
            playerChoice=getche();
            switch(playerChoice)
            {
            case '1':   ///HIT
            {
        ///        printf("\nplayerChoice: %c\n", playerChoice);
           ////     printf("foo player_Choice_Resolution_Full elegiste hit en el case 1 ");
                flag=1;
             ///   system("pause");
                break;
            }
            case '2':   ///STAND
            {
               /// printf("foo player_Choice_Resolution_Full elegiste stand en el case 1 ");
                flag=2;
          ///      system("pause");
                break;
            }
            case '3':   ///GIVE UP
            {
            ///    printf("foo player_Choice_Resolution_Full elegiste give up en el case 1 ");
                flag=5;
               /// system("pause");
                break;
            }
            default:
            {
                // printf("ingresaste un valor invalido en menu de juego en controlValue==1");
                break;
            }
            }///ENDS SWITCH switch(playerChoice)
        }
        while (flag!=1 && flag!=2 && flag!=5);
        break;
    }/// CLOSES CASE 1
    case 2:
    {
        do
        {
            ///printf("\nCASE controlValue==2 \n");
            fflush(stdin);
            playerChoice=getche();
            switch(playerChoice)
            {
            case '1':     ///HIT
            {
               /// printf("\nplayerChoice: %c\n", playerChoice);
                ///printf("foo player_Choice_Resolution_Full elegiste hit en el case 2 ");
                flag=1;
                ///system("pause");
                break;
            }
            case '2':     ///STAND
            {

                flag=2;
                ///system("pause");
                break;
            }
            case '3':     ///GIVE UP
            {

                flag=5;
                ///system("pause");
                break;
            }
            case '4':     ///INSURANCE
            {

                flag=6;
                ///system("pause");
                break;
            }
            default:
            {
                break;
            }
            }///CLOSES SWITCH
        }
        while (flag!=1 && flag!=2 && flag!=5 && flag!=6);
        break;
    }///CLOSES CASE 2
    case 3:
    {
        do
        {
            ///printf("\nCASE controlValue==3 \n");
            fflush(stdin);
            playerChoice=getche();
            switch(playerChoice)
            {
            case '1':///HIT
            {
            ///    printf("\nplayerChoice: %c\n", playerChoice);
          ///      printf("foo player_Choice_Resolution_Full elegiste hit en el case 3 ");
                flag=1;
               /// system("pause");
                break;
            }
            case '2':///STAND
            {

                flag=2;
               /// system("pause");
                break;
            }
            case '3':///DOUBLE
            {

                flag=3;
                ///system("pause");
                break;
            }
            case '4':///SPLIT
            {

                flag=4;
                ///system("pause");
                break;
            }
            case '5':///GIVE UP
            {

                flag=5;
                ///system("pause");
                break;
            }
            default:
            {
                break;
            }
            }///CLOSES SWITCH
        }
        while (flag!=1 && flag!=2 && flag!=3 && flag!=4 && flag!=5);
        break;
    }///CLOSES CASE 3
    case 4:
    {
        do
        {
          ///  printf("\nCASE controlValue== 4 \n");
            fflush(stdin);
            playerChoice=getche();
            switch(playerChoice)
            {
            case '1':///HIT
            {
                ///printf("\nplayerChoice: %c\n", playerChoice);
    ///            printf("foo player_Choice_Resolution_Full elegiste hit en el case 1 ");
                flag=1;
                ///system("pause");
                break;
            }
            case '2':///STAND
            {
                flag=2;
                ///system("pause");
                break;
            }
            case '3':///DOUBLE
            {
                flag=3;
                ///system("pause");
                break;
            }
            case '4':///SPLIT
            {
                flag=4;
                ///system("pause");
                break;
            }
            case '5':///GIVE UP
            {
                flag=5;
                ///system("pause");
                break;
            }
            case '6':///INSURANCE
            {
                flag=6;
                ///system("pause");
                break;
            }
            default:
            {
                break;
            }
            }///CLOSES SWITCH
        }
        while (flag!=1 && flag!=2 && flag!=3 && flag!=4 && flag!=5 && flag!=6);
        break;
    }
    }///ENDS SWITCH switch(controlValue)
    ///printf("\nFoo valor flag Pre Return: %d\n", flag);
    return flag;
}///CLOSES FOO

///-------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------

int foo_Machine_Plays (LinkedList *banca, LinkedList *Deck)
{
///   int acesCounter=0;
    int flag=-1;
    int bancaCards=0;
    card *isThereAnAce=NULL;
    Node *nextCard=NULL;
    Node *tempNode=NULL;

    do
    {
        bancaCards=foo_Adds_Cards_Value_Banca(banca);
     ///   printf("\nFOO MACHINE PLAYSbancaCards: %d\n", bancaCards);
tag2:
        if (bancaCards<=16)
        {
           nextCard=foo_Finds_First_Node_And_Removes_It (Deck);
           tempNode=foo_Finds_Last_Node (banca);
           tempNode->pNextNode=nextCard;
           flag=1;
        }
        else if (bancaCards>=17)
        {
   ///         printf("\n DEBE PLANTARSE\n");
            flag=0;
        }
    }
    while(flag!=0);
///**********************************************************************************************************************************
///**********************************************************************************************************************************
/// ESTO VA A FALLAR SI HAY MAS DE UN AS EN LA MANO DE LA BANCA!!!!!!!!!!!!!!
///**********************************************************************************************************************************
///**********************************************************************************************************************************
bancaCards=foo_Adds_Cards_Value_Banca(banca);
    if (bancaCards>=22)
    {
        printf("\nBANCA SE PASO\n");
        //flag=0;
     /*   tempNode=banca->pFirstNode;
       do
        {
            //  imprimeLinkedList(banca);///BORRRAR
            system("pause");
            isThereAnAce=tempNode->pElement;
            if (isThereAnAce->value==1)
            {
       ///         printf("\n\nbancaCards: %d\n\n", bancaCards);
                bancaCards=bancaCards-10;
                printf("\n\n en If bancaCards: %d\n\n", bancaCards);
                break;
                //flag=0;
            }
     ///       printf("\n\ntempNode: %p\n\n", tempNode);
            tempNode=tempNode->pNextNode;
      ///      printf("\n\nbancaCards: %d\n\n", bancaCards);
        }
        while(tempNode!=NULL);  ///CLOSES WHILE
        */
        imprimeLinkedList(banca);
    }
    if(bancaCards<=16)
    {
        goto tag2;
    }
system("pause");
    return bancaCards;
}

///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void foo_Double_Tap_The_Table (LinkedList *this, LinkedList *Deck)
{
    Node *tempNode;

    tempNode=foo_Finds_Last_Node (this);
    tempNode->pNextNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);
}
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int stillAlive (int playerOneCards)
{
    int stillAlive=0;
    if (playerOneCards<=21)
    {
        stillAlive=1;
    ///    printf("FOO stillAlive: %d", stillAlive);
    }
    else
    {
        stillAlive=0;
    ///    printf("FOO SOS BOLETA");
     ///   system("pause");
    }
    //}
    return stillAlive;      ///0 PLAYER LOSSES  1 PLAYER < 21
}///CLOSES FOO

///-------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------
void deals_Two_Cards_To_Each_Player (LinkedList *Deck, LinkedList *playerOne_1st, LinkedList *banca)
{
    Node *tempNode=NULL;

    playerOne_1st->pFirstNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);
    banca->pFirstNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);

    tempNode=playerOne_1st->pFirstNode;
    tempNode->pNextNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);

    tempNode=banca->pFirstNode;
    tempNode->pNextNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);
}
///------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------
int Calculates_controlValue (LinkedList *banca, LinkedList *playerOne_1st)
{
    Node *tempNode=NULL;
    card *cardPtr=NULL;
    int controlValue=1;
    int areEqual=0;

    tempNode=banca->pFirstNode;
    cardPtr=tempNode->pElement;
    if (cardPtr->value==1)
    {
     ///   printf("\nla primera carta es un as\n");
        controlValue++;
    }
    areEqual=foo_Are_initial_Cards_Equal(playerOne_1st);    ///HACER UNA SOLA SENTENCIA DE ESTO
    if(areEqual)
    {
        ///MENU ALL IN
        controlValue++;
        controlValue++;
    }
    ///  printf("\n\n Calculates_controlValueFOO controlValue: %d\n\n ", controlValue);
    return controlValue;
}
///---------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------
int who_Wins (int bancaCards, int playerOneCards)   ///0=banca   1=PLAYER 1
{
    int winner=-1;

    if (playerOneCards<=21)
    {
        if (bancaCards<=21)
        {
            if (bancaCards>=playerOneCards)
            {
                winner=0;    //printf("\n\n\nGANA LA BANCA\n\n\n");
            }
            else
            {
                winner=1;   //   printf("\n\n\nGANA PLAYER 1\n\n\n");
            }
        }
        else
        {
            winner=1;        //   printf("\n\n\nGANA PLAYER 1\n\n\n");
        }
    }
    else
    {
        winner=0;        //printf("\n\n\nGANA LA BANCA\n\n\n");
    }
    return winner;
}
///---------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------
void Credits_Minus_betAmount (int *creditsPtr, int *betAmountPtr)
{
    int credits=*creditsPtr;
    int betAmount=*betAmountPtr;
    // printf("\n\ncredits: %d\n\n", credits);
    //  printf("\n\nbetAmount: %d\n\n", betAmount);
    ///  system("pause");

    credits=credits-betAmount;
//printf("\n\n POST credits: %d\n\n", credits);
    *creditsPtr=credits;
    //  printf("\n\n POST *credits: %d\n\n", credits);
}

///-------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------
Node* gets_First_Card(LinkedList *Deck)
{
    Node *tempNode;
    tempNode=(Node*) foo_Finds_First_Node_And_Removes_It (Deck);
    return tempNode;
}
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------------------------------------------
