#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "linkedlist.h"
#include "card.h"
#include "scenario.h"
#include "control.h"

#define FILA 24
#define COLUMNA 80
#define TAMANIOPANTALLA 1920

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int controlValue=1;
    int *controlValuePtr=NULL;                   ///int areEqual=-1;
    int flag=0, secondflag=0;
    int insurance=0;
    int isPlayerAlive=-1;
    int *insurancePtr=NULL;
    int isDouble=0;         ///0== NO   1==YES
    int *isDoublePtr=NULL;
    int isSplit=0;         ///0== NO   1==YES
    int *isSplitPtr=NULL;
    int playerOneCards=0;
    int bancaCards=0;
    int credits=1000;
    int *creditsPtr=NULL;
    int betAmount=0;
    int *betAmountPtr=NULL;
    int initialBet=0;

    creditsPtr=&credits;
    controlValuePtr=&controlValue;
    betAmountPtr=&betAmount;
    ///printf("\n\nMAIN creditsPtr: %f\n\n", *creditsPtr);        //printf("\n\nMAIN controlValuePtr: %d\n\n", *controlValuePtr);
    LinkedList *Deck;
    Deck=(LinkedList*) foo_Creates_Decks_Randomly ();
    LinkedList *playerOne;
    LinkedList *banca;
    LinkedList *playerOne_1st;
    LinkedList *playerOne_2nd;

    Node *playerOne_1st_NodePtr=NULL;
    Node *playerOne_2nd_NodePtr=NULL;
    Node *tempNode=NULL;
    Node *tempNode2=NULL;

    tempNode=Node_NewNode("tempNode");      ///printf("\ntempNode: %p\n", tempNode);
    tempNode2=Node_NewNode("temp2");    ///printf("\ntempNode2: %p\n", tempNode2);
    playerOne_1st_NodePtr=Node_NewNode("playerOne_1st_NodePtr");        ///printf("\nplayerOne_1st_NodePtr: %p\n", playerOne_1st_NodePtr);
    playerOne_2nd_NodePtr=Node_NewNode("playerOne_2nd_NodePtr");        ///printf("\nplayerOne_1st_NodePtr: %p\n", playerOne_1st_NodePtr);

    playerOne=ll_newLinkedList();
    banca=ll_newLinkedList();
    playerOne_1st=ll_newLinkedList();
    playerOne_2nd=ll_newLinkedList();

    escenarioPosicionXY scene[TAMANIOPANTALLA];                         ///init scene (pantalla juego)

    LinkedList *harcoded_Deck=NULL;
    harcoded_Deck=(LinkedList*)ll_newLinkedList;
    harcoded_Deck=(LinkedList*)foo_HARCODE_DATA_DECK(Deck);

    Deck=harcoded_Deck;     ///QUITAR HARDCODED DE AQUI LUEGO

///ARRANCA LA MANO  ARRANCA LA MANO ARRANCA LA MANO ARRANCA LA MANO ARRANCA LA MANO
tag1:
    deals_Two_Cards_To_Each_Player (Deck, playerOne, banca);        ///REPARTE 2 CARTAS PARA CADA UNO
    playerOneCards=foo_Adds_Cards_Value(playerOne);                 ///BBORRAR LUEGO
    bancaCards=foo_Adds_Cards_Value(banca);                         ///BBORRAR LUEGO
    do
    {
        controlValue=Calculates_controlValue (banca, playerOne);        ///printf("\n\n\n MAIN controlValue al inicio: %d\n\n\n", controlValue);
        initialBet=1;    ///FORZANDO CONDICION PARA EVITARLO EN TEST
        if (initialBet==0)
        {
            initial_Bet_Screen (scene);
            foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
            fooprintsScenario (scene);
            betAmount=Bet_Options();
            Credits_Minus_betAmount (creditsPtr, betAmountPtr);
            initialBet=1;
        }
tag2:        ///INICIA PARTIDA, MUESTAR CARTAS
        ///PANTALLA PARA ACCION PLAYER

        eraseFaceMessage (scene);
        screen_Player_Plays (scene, playerOne, banca, controlValue, isDoublePtr, isSplitPtr);
        foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
        fooprintsScenario (scene);
        flag= player_Choice_Resolution_Full(controlValue);
        ///   printf("\n\n\nEn TAG 2 flag: %d\n\n\n",flag);
        system("pause");
        switch(flag)
        {
        case 1: ///1-HIT
        {
            foo_Double_Tap_The_Table (playerOne, Deck);
            playerOneCards=foo_Controls_Hand_Player(playerOne);
            isPlayerAlive=stillAlive (playerOneCards);               /// printf("\n\n\nisPlayerAlive: %d\n\n\n", isPlayerAlive);

            if (isPlayerAlive)
            {
                controlValue=1;
                goto tag2;
            }
            else
            {
                ///   system("cls");
                ///   printf("\n\nMAIN MURIO\n\n");
                flag=-2;
                secondflag=-2;

                eraseFaceMessage (scene);
                screen_Player_Plays (scene, playerOne, banca, controlValue, isDoublePtr, isSplitPtr);
                foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
                fooprintsScenario (scene);

            }
            break;
        }///CLOSES CASE 1
        case 2: ///2-STAND
        {
            ///  printf("MAIN PLAYER SE PLANTA Y DEBE JUGAR LA MAQUINA");
            flag=0, secondflag=0 ;
            ///JUEGA LA MAQUINA
            break;
        }
        case 3:///DOUBLE
        {
            ///RESOLVER LA JUGADA HASTA Q JUEGA LA MAQUINA
            tempNode=foo_Finds_Last_Node (playerOne);
            tempNode->pNextNode=foo_Finds_First_Node_And_Removes_It (Deck);
            ///    imprimeLinkedList(playerOne);
            foo_Prints_Hand_Double(playerOne, scene, 15, 35);
            fooprintsScenario(scene);
            controlValue=1;
            flag=0;

            break;
        }
        case 4: ///SPLIT
        {
             ///imprimeLinkedList(playerOne_1st);
            playerOne_1st_NodePtr=foo_Finds_First_Node_And_Removes_It (playerOne);
            playerOne_2nd_NodePtr=foo_Finds_First_Node_And_Removes_It(playerOne);
            playerOne_1st->pFirstNode=playerOne_1st_NodePtr;
            playerOne_2nd->pFirstNode=playerOne_2nd_NodePtr;
  printf("\n1ST\n");
 imprimeLinkedList(playerOne_1st);
 printf("\nSECOND\n");
 imprimeLinkedList(playerOne_2nd);
system("pause");
///----------------------------------------------------
///BORRA LAS CARTAS IMPRESAS EN PLAYER PLAYS
///foo_Card_Erase_From_Scenario( 15, 35, scene);
///foo_Card_Erase_From_Scenario( 15, 41, scene);
///--------------------------------------------------
controlValue=1;
printf("AAAAAAAAAAAACCCCCCCCCCCCCAAAAAAAAAAAAAA");
eraseFaceMessage (scene);
///foo_Prints_Hand_Split(playerOne_1st, playerOne_2nd, scene, 15, 20);
isSplit=1;

///-------------------------------------------------
///DEFINIR SI USAR PLAYER PLAYS CON IS SPLIT PTR O USAR
///foo_Prints_Hand_Split(playerOne_1st, playerOne_2nd, scene, 15, 20);
screen_Player_Plays (scene, playerOne, banca, controlValue, isDoublePtr, isSplitPtr);

foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
fooprintsScenario (scene);
flag= player_Choice_Resolution_Full(controlValue);
system("pause");





///--------------------------------------------------
///--------------------------------------------------
system("pause");

            flag=1, secondflag=1;
            ///goto tag2;
            break;
        }
        case 5: ///GIVE UP
        {///DEBE COBRARSE LA MITAD DE LA APUESTA Y GOTO TAG2
            flag=-1, secondflag=-1;
            break;
        }
        case 6: ///INSURANCE
        {
            ///SI LA BANCA MUESTRA UNA AS, PAGAS SEGURO POR SI PERDES
            eraseFaceMessage(scene);
            faceMessages(scene,"Insurance Taken");
            insurance=1;
            flag=6;
            controlValue=1;
            fooprintsScenario(scene);
            ///CALCULAR EL COSTO DEL INSURANCE Y APLICARLO
            system("pause");
            goto tag2;
            break;
        }

        }///CLOSES SWITCH
        /// system("pause");
    }
    while (flag>0);
///-----------------------------------------------------------------------------------------------------------------------------------
    switch(secondflag)
    {
    case -2:    ///PLAYER SE PASO
    {
        ///printf("\n\n secondflag: %d   PLAYER 1 SE PASO\n\n", secondflag);
        ///SI ESTE FLAG ES, ENTONCES NO JUEGA LAS CARTAS LA BANCA
        break;
    }
    case -1:    ///SE RINDE Y DEBE PERDER LA MITAD DE LO QUE APOSTO
    {
        /// printf("\n\n SE RINDE Y DEBE PERDER LA MITAD DE LO QUE APOSTO\n\n");
        credits=credits+(betAmount/2);
        betAmount=0;
        goto tag1;
        break;
        ///GIVE UP
    }
    case 0:     ///DEBE JUGAR LA MAQUINA
    {
        /// printf("\n\n 2ND FLAG DEBE JUGAR LA MAQUINA\n\n");

        ///IF EL FLAG ES Q EL PLAYER PERDIO SALTEA LO DE ABAJO Y DA GANADORA A BANCA Y VUELVE A ARRANCAR
        bancaCards=foo_Machine_Plays (banca, Deck);
        imprimeLinkedList(banca);
        ///system("pause");
        ///printf("\n\nMAIN bancaCards: %d\n\n", bancaCards);
///------------------------------------------------------------------------------------------------------------------------------------------------------------------
        eraseFaceMessage (scene);
        foo_Prints_Hand_Banca_Shows_Both_Cards (banca, scene, 1, 35);
        foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
        fooprintsScenario (scene);
///------------------------------------------------------------------------------------------------------------------------------------------------------------------
        break;
    }///CLOSES CASE 0
    }///CLOSES SWITCH

///------------------------------------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------------------------------------------
///    system("pause");
    if (who_Wins (bancaCards, playerOneCards))   ///0=banca   1=PLAYER 1
    {
        credits=credits+(betAmount*2);  ///PAGA 150% NO 200!!!!!!!!!!!!!!!!!!!
        betAmount=0;
        initialBet=0;
        eraseFaceMessage (scene);
        faceMessages(scene, "GANA EL PLAYER");
        fooprintsScenario (scene);

    }
    else
    {
        betAmount=0;
        initialBet=0;
        eraseFaceMessage (scene);
        faceMessages(scene, "GANA LA BANCA");
        fooprintsScenario (scene);
    }
//    free(playerOne);
//   free(banca);
    /// printf("\n\nLUEGO QUE PULSES, VOLVERAS AL PRINCIPIO DEL TAG 1\n\n");
    system("pause");
    goto tag1;

    return 354;
}
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
