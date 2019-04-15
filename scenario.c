#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#include "scenario.h"
#include "card.h"
#include "linkedlist.h"




///-------------------------------------------------------------------------
///INIT SCENE

void initEscenario (escenarioPosicionXY scene[])
{
    int i=0, j=0, t=0;

    for (i=0; i<FILA; i++)
    {
        for(j=0; j<COLUMNA; j++)
        {
            scene[t].escenarioXFila=i;
            scene[t].escenarioYColumna=j;
            scene[t].charAImprimir=0;
            scene[t].Lethality=0;
            t++;
        }
    }
}///ENDS INITESCENARIO

///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------
///FOO PRINTS SCREEN

void fooprintsScenario (escenarioPosicionXY scene [])
{
    int k=0;
    system("cls");                                      ///NO BORRAR MANTIENE LA APANTALLA EN SU LUGAR
    for(k=0; k<TAMANIOPANTALLA; k++)
    {
        printf("%c", scene[k].charAImprimir);
    }
}


///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
///-------------------------------------------

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void fooFrameConstruct(int XFila, int YColumna, int largoCaja, int altoCaja, escenarioPosicionXY scene[], int puertaHorizontal, int puertaVertical)

{
    int lineaParalela=0;
    int i=0, j=0, k=0, t=0,  valorScene=0;

    for (i=0; i<FILA; i++)
    {
        for(j=0; j<COLUMNA; j++)
        {
            if (XFila==i)
            {
                if (YColumna==j)
                {
                    valorScene= t;
                    ///    printf("valorScene: %d", valorScene);
                    break;
                }
            }
            t++;
        }
    }

    lineaParalela=altoCaja*80;
    for(j=0; j<largoCaja; j++)
    {
        scene[valorScene+j].charAImprimir=196;///196
        scene[valorScene+lineaParalela+j].charAImprimir=196;///196
    }
    for(k=valorScene; k<valorScene+lineaParalela; k=k+80)
    {
        scene[k].charAImprimir=179;
    }
    for(k=valorScene+largoCaja; k<valorScene+lineaParalela+largoCaja; k=k+80)
    {
        scene[k].charAImprimir=179;
    }

    ///BORDES SCENARIO
    scene[valorScene].charAImprimir=218; ///218
    scene[valorScene+largoCaja].charAImprimir=191; ///191
    scene[valorScene+lineaParalela].charAImprimir=192; ///192
    scene[valorScene+lineaParalela+largoCaja].charAImprimir=217; ///217

    if (puertaHorizontal>=0)
    {
        ///PUERTA puertaVertical HORIZONTAL
        scene[puertaHorizontal].charAImprimir=0; ///0
        scene[puertaHorizontal+1].charAImprimir=195; ///0
        scene[puertaHorizontal-1].charAImprimir=180; ///0
    }

    if(puertaVertical>=0)
    {
        ///PUERTA puertaVertical VERTICAL
        scene[puertaVertical].charAImprimir=255; ///0
        scene[puertaVertical+80].charAImprimir=194; ///0
        scene[puertaVertical-80].charAImprimir=193; ///0
    }




}
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void fooSquareConstruct(int XFila, int YColumna, int largoCaja, int altoCaja, escenarioPosicionXY scene[], int puertaHorizontal, int puertaVertical)

{
    int lineaParalela=0;
    int i=0, j=0, k=0, t=0,  valorScene=0;

    for (i=0; i<FILA; i++)
    {
        for(j=0; j<COLUMNA; j++)
        {
            if (XFila==i)
            {
                if (YColumna==j)
                {
                    valorScene= t;
                    ///    printf("valorScene: %d", valorScene);
                    break;
                }
            }
            t++;
        }
    }

    lineaParalela=altoCaja*80;
    for(j=0; j<largoCaja; j++)
    {
        scene[valorScene+j].charAImprimir=196;///196
        scene[valorScene+lineaParalela+j].charAImprimir=196;///196
    }
    for(k=valorScene; k<valorScene+lineaParalela; k=k+80)
    {
        scene[k].charAImprimir=179;
    }
    for(k=valorScene+largoCaja; k<valorScene+lineaParalela+largoCaja; k=k+80)
    {
        scene[k].charAImprimir=179;
    }

    ///BORDES SCENARIO
    scene[valorScene].charAImprimir=218; ///218
    scene[valorScene+largoCaja].charAImprimir=191; ///191
    scene[valorScene+lineaParalela].charAImprimir=192; ///192
    scene[valorScene+lineaParalela+largoCaja].charAImprimir=217; ///217

    if (puertaHorizontal>=0)
    {
        ///PUERTA puertaVertical HORIZONTAL
        scene[puertaHorizontal].charAImprimir=0; ///0
        scene[puertaHorizontal+1].charAImprimir=195; ///0
        scene[puertaHorizontal-1].charAImprimir=180; ///0
    }

    if(puertaVertical>=0)
    {
        ///PUERTA puertaVertical VERTICAL
        scene[puertaVertical].charAImprimir=0; ///0
        scene[puertaVertical+80].charAImprimir=194; ///0
        scene[puertaVertical-80].charAImprimir=193; ///0
    }
}
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------
///-------------------------------------------------------------------------------

void foo_Prints_Header_BJack (escenarioPosicionXY scene[], int *betAmountPtr, int playerOneCards, int *creditsPtr, /*BORRAR LUEGO*/ int bancaCards)             ///PRINTS SCENARIO
{
    char nrochar[4];
    char cardsValuechar[2];
    char cardsBancachar[2];
    char creditsAmountChar[4];
    int credits=0;
    int betAmount=0;
    betAmount=*betAmountPtr;          ///      printf("betAmount: %d", betAmount);    printf("\n FOO PRE creditsPtr: %f\n", *creditsPtr);
    credits=*creditsPtr;           ///  printf("\n FOO  POST credits: %d\n", credits);
    //system("pause");

      scene[90].charAImprimir=36; ///@ CREDITS
    itoa(credits, creditsAmountChar, 10);
    scene[92].charAImprimir=creditsAmountChar[0]; ///
    scene[93].charAImprimir=creditsAmountChar[1]; ///
    scene[94].charAImprimir=creditsAmountChar[2]; ///
    scene[95].charAImprimir=creditsAmountChar[3]; ///

    scene[168].charAImprimir=66;    ///B
    scene[169].charAImprimir=101;   ///E
    scene[170].charAImprimir=116;   ///T
    itoa(betAmount, nrochar, 10);
    scene[172].charAImprimir=nrochar[0];         ///
    scene[173].charAImprimir=nrochar[1];         ///
    scene[174].charAImprimir=nrochar[2];         ///


    scene[249].charAImprimir=80; ///PLAYER CARDS
    scene[250].charAImprimir=49; ///PLAYER CARDS
    itoa(playerOneCards, cardsValuechar, 10);
    scene[252].charAImprimir=cardsValuechar[0]; ///B
    scene[253].charAImprimir=cardsValuechar[1]; ///B

    scene[326].charAImprimir=66; ///BANCA CARDS
    scene[327].charAImprimir=65; ///BANCA CARDS
    scene[328].charAImprimir=78; ///BANCA CARDS
    scene[329].charAImprimir=67; ///BANCA CARDS
    scene[330].charAImprimir=65; ///BANCA CARDS
    itoa(bancaCards, cardsBancachar, 10);
    scene[332].charAImprimir=cardsBancachar[0]; ///B
    scene[333].charAImprimir=cardsBancachar[1]; ///B


}///CLOSES FOO

///---------------------------------------------------------------------
///---------------------------------------------------------------------

///---------------------------------------------------------------------
///---------------------------------------------------------------------
///---------------------------------------------------------------------
void fooConstructHorizontalLine (int XFila, int YColumna, int largoRecta, escenarioPosicionXY scene[])
{
    int i=0;

    int sceneNro=0;
    sceneNro=scenarioReturnsScenePosition (XFila, YColumna);

    for(i=0; i<largoRecta; i++)
    {
        scene[sceneNro+i].charAImprimir=196;
        ///printf("sceneNro %d   i %d", sceneNro, i);
        ///system("pause");
    }
}


///------------------------------------------------------------------------------
///------------------------------------------------------------------------------
///------------------------------------------------------------------------------
void fooConstructVerticalLine (int XFila, int YColumna, int largoRecta, escenarioPosicionXY scene[])
{
    int i=0, finalRecta=0;

    int sceneNro=0;
    sceneNro=scenarioReturnsScenePosition (XFila, YColumna);
    finalRecta=(largoRecta*80);
    for(i=0; i<finalRecta; i=i+80)
    {
        scene[sceneNro+i].charAImprimir=179;
    }
}


///-----------------------------------------------------------------------
///-----------------------------------------------------------------------
///-----------------------------------------------------------------------
///-----------------------------------------------------------------------
///-----------------------------------------------------------------------

void faceMessages (escenarioPosicionXY scene[], char faceMessage[])
{
    int messageLength=0, i=0;

    messageLength= strlen (faceMessage);

    for(i=0; i<messageLength; i++)
    {
        scene[1686+i].charAImprimir=faceMessage[i];
    }
}

///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------
void eraseFaceMessage (escenarioPosicionXY scene[])
{
    int x=0;

    for(x=1686; x<1849; x++)
    {
        scene[x].charAImprimir=0;
    }
}

///---------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------

void intro (int XFila, int YColumna, escenarioPosicionXY scene[])
{
    int sceneNro=0;
    sceneNro=scenarioReturnsScenePosition (XFila, YColumna);

    scene[sceneNro].charAImprimir=42;
    scene[sceneNro+8].charAImprimir=42;
    scene[sceneNro+81].charAImprimir=42;
    scene[sceneNro+84].charAImprimir=42;   ///W
    scene[sceneNro+87].charAImprimir=42;
    scene[sceneNro+162].charAImprimir=42;
    scene[sceneNro+166].charAImprimir=42;

    scene[sceneNro+11].charAImprimir=42;
    scene[sceneNro+91].charAImprimir=42;
    scene[sceneNro+93].charAImprimir=42;
    scene[sceneNro+171].charAImprimir=42;   ///E
    scene[sceneNro+173].charAImprimir=42;
    scene[sceneNro+175].charAImprimir=42;
    scene[sceneNro+13].charAImprimir=42;
    scene[sceneNro+15].charAImprimir=42;

    scene[sceneNro+18].charAImprimir=42;
    scene[sceneNro+98].charAImprimir=42;
    scene[sceneNro+178].charAImprimir=42;   ///L
    scene[sceneNro+180].charAImprimir=42;
    scene[sceneNro+182].charAImprimir=42;

    scene[sceneNro+25].charAImprimir=42;
    scene[sceneNro+27].charAImprimir=42;
    scene[sceneNro+29].charAImprimir=42;
    scene[sceneNro+105].charAImprimir=42;       ///C
    scene[sceneNro+185].charAImprimir=42;
    scene[sceneNro+187].charAImprimir=42;
    scene[sceneNro+189].charAImprimir=42;

    scene[sceneNro+32].charAImprimir=42;
    scene[sceneNro+112].charAImprimir=42;
    scene[sceneNro+192].charAImprimir=42;
    scene[sceneNro+34].charAImprimir=42;
    scene[sceneNro+36].charAImprimir=42;   ///O
    scene[sceneNro+116].charAImprimir=42;
    scene[sceneNro+196].charAImprimir=42;
    scene[sceneNro+194].charAImprimir=42;

    scene[sceneNro+39].charAImprimir=42;
    scene[sceneNro+43].charAImprimir=42;
    scene[sceneNro+123].charAImprimir=42;
    scene[sceneNro+203].charAImprimir=42;   ///M
    scene[sceneNro+119].charAImprimir=42;
    scene[sceneNro+121].charAImprimir=42;
    scene[sceneNro+199].charAImprimir=42;

    scene[sceneNro+46].charAImprimir=42;
    scene[sceneNro+126].charAImprimir=42;
    scene[sceneNro+128].charAImprimir=42;
    scene[sceneNro+206].charAImprimir=42;   ///E
    scene[sceneNro+208].charAImprimir=42;
    scene[sceneNro+210].charAImprimir=42;
    scene[sceneNro+48].charAImprimir=42;
    scene[sceneNro+50].charAImprimir=42;

    scene[sceneNro+490].charAImprimir=49;
    scene[sceneNro+491].charAImprimir=45;
    scene[sceneNro+493].charAImprimir=68;
    scene[sceneNro+494].charAImprimir=101;      /// 1- Demo
    scene[sceneNro+495].charAImprimir=109;
    scene[sceneNro+496].charAImprimir=111;

    scene[sceneNro+510].charAImprimir=50;
    scene[sceneNro+511].charAImprimir=45;
    scene[sceneNro+513].charAImprimir=80;
    scene[sceneNro+514].charAImprimir=108;      /// 2- Play
    scene[sceneNro+515].charAImprimir=97;
    scene[sceneNro+516].charAImprimir=121;

    scene[sceneNro+530].charAImprimir=51;
    scene[sceneNro+531].charAImprimir=45;
    scene[sceneNro+533].charAImprimir=76;
    scene[sceneNro+534].charAImprimir=111;      /// 2- Load
    scene[sceneNro+535].charAImprimir=97;
    scene[sceneNro+536].charAImprimir=100;

}///CLOSES FOO


///-----------------------------------------------------------------------
void eraseIntro (int XFila, int YColumna, escenarioPosicionXY scene[])
{
    int sceneNro=0;
    sceneNro=scenarioReturnsScenePosition (XFila, YColumna);

    scene[sceneNro+490].charAImprimir=0;
    scene[sceneNro+491].charAImprimir=0;
    scene[sceneNro+493].charAImprimir=0;
    scene[sceneNro+494].charAImprimir=0;      /// 1- Help
    scene[sceneNro+495].charAImprimir=0;
    scene[sceneNro+496].charAImprimir=0;

    scene[sceneNro+510].charAImprimir=0;
    scene[sceneNro+511].charAImprimir=0;
    scene[sceneNro+513].charAImprimir=0;
    scene[sceneNro+514].charAImprimir=0;      /// 2- Play
    scene[sceneNro+515].charAImprimir=0;
    scene[sceneNro+516].charAImprimir=0;

    scene[sceneNro+530].charAImprimir=0;
    scene[sceneNro+531].charAImprimir=0;
    scene[sceneNro+533].charAImprimir=0;
    scene[sceneNro+534].charAImprimir=0;      /// 2- Load
    scene[sceneNro+535].charAImprimir=0;
    scene[sceneNro+536].charAImprimir=0;


}///CLOSES FOO eraseIntro
///------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------------------------
///ESTA FOO VA EN CONTROL DEL VIDEO 5
int scenarioReturnsScenePosition (int XFila, int YColumna)
{
    int i=0, j=0, t=0, sceneNro=-1;
    ///int scene [TAMANIOPANTALLA];

    for (i=0; i<FILA; i++)
    {
        for(j=0; j<COLUMNA; j++)
        {
            ///   scene[t]=t;      ///SI NO DA ERROR HAY QUE BORRAR ESTA SENTENCIA
            ///printf("\nscene: %d\n", scene[t]);
            if (XFila==i)
            {
                if (YColumna==j)
                {
                    sceneNro=t;
                    break;
                    ///printf("\FOO nscene: %d\n", sceneNro);
                }
            }
            t++;
        }
    }
    return sceneNro;
}

///------------------------------------------------------------------------------------------------------------------------------

void foo_Sets_Face (escenarioPosicionXY scene[])
{
    ///CARA
    scene[1680].charAImprimir=91;
    scene[1681].charAImprimir=48;
    scene[1682].charAImprimir=106;
    scene[1683].charAImprimir=48;
    scene[1684].charAImprimir=93;
}

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void prints_Bets_Values (escenarioPosicionXY scene[])
{
///OPCIONES VALORES APUESTAS
    scene[1714].charAImprimir=49;   ///1
    scene[1715].charAImprimir=45;
    scene[1716].charAImprimir=172;

    scene[1723].charAImprimir=50;   ///2
    scene[1724].charAImprimir=45;
    scene[1725].charAImprimir=171;

    scene[1731].charAImprimir=51;   ///3
    scene[1732].charAImprimir=45;
    scene[1733].charAImprimir=243;

    scene[1738].charAImprimir=52;   ///4
    scene[1739].charAImprimir=45;
    scene[1740].charAImprimir=49;
}

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void foo_Resolves_After_player_Choice (escenarioPosicionXY scene[], int controlValue)
{
//printf("FOOOOOO controlValue: %d", controlValue);
///    system("pause");
    switch (controlValue)
    {
    case 1:
    {
        eraseFaceMessage (scene);
        faceMessages (scene, "1-HIT  2-STAND  3-GIVE UP ");
        break;
    }
    case 2:
    {
        eraseFaceMessage (scene);
        faceMessages (scene, "1-HIT  2-STAND  3-GIVE UP  4-INSURANCE");
        break;
    }
    case 3:
    {
        eraseFaceMessage (scene);
        faceMessages (scene, "1-HIT  2-STAND  3-DOUBLE  4-SPLIT  5-GIVE UP  ");
        break;
    }
    case 4:
    {
        eraseFaceMessage (scene);
        faceMessages (scene, "1-HIT  2-STAND  3-DOUBLE  4-SPLIT  5-GIVE UP  6-INSURANCE");
        break;
    }
    default:
    {
        printf("Si estas viendo esto es un error");
        system("pause");
        break;
    }
    }///ENDS SWITCH
}///CLOSES FOO

///---------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------
void initial_Bet_Screen (escenarioPosicionXY scene[])
{
///PANTALLA PARA INGRESAR EL VALOR DE LA APUESTA INICIAL
///        system("cls");
    initEscenario (scene);
    fooFrameConstruct(0, 0, 79, 20, scene, -1, -1);///BORDE ESCENARIO
    foo_Card_ConStruct_Empty(1, 35, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
    foo_Card_ConStruct_Empty(1, 41, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
    foo_Card_ConStruct_Empty(15, 35, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
    foo_Card_ConStruct_Empty(15, 41, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
    foo_Sets_Face(scene);
    faceMessages (scene, "INITIAL BET? ");
    prints_Bets_Values (scene);

}
///---------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------
void screen_Player_Plays (escenarioPosicionXY scene[], LinkedList *playerOne, LinkedList *banca, int controlValue, int *isDoublePtr, int *isSplitPtr)
{
   /// printf("\nisDoublePtr:%d\n", isDoublePtr);
  ///  printf("\nisSplitPtr:%d\n", isSplitPtr);
  ///  system("pause");

    if (isDoublePtr!=0)
    {
        ///IMPRIME PANTALLA PARA DOUBLE
        initEscenario (scene);
        fooFrameConstruct(0, 0, 79, 20, scene, -1, -1);///BORDE ESCENARIO
        foo_Prints_Hand_Banca(banca, scene, 1, 35);
        ///foo_Prints_Hand(playerOne, scene, 15, 35);
        foo_Sets_Face(scene);
        foo_Resolves_After_player_Choice (scene, controlValue);///se encarga de definir el manu correspondiente



/*
                   ///RESOLVER LA JUGADA HASTA Q JUEGA LA MAQUINA
            tempNode=foo_Finds_Last_Node (playerOne);
            tempNode->pNextNode=foo_Finds_First_Node_And_Removes_It (Deck);                imprimeLinkedList(playerOne);    system("pause");
            ///tempNode=foo_Finds_First_Node_And_Removes_It (Deck);                imprimeLinkedList(playerOne);    system("pause");
            playerOneCards=foo_Adds_Cards_Value_Banca(playerOne);
            foo_Prints_Hand_Double(playerOne, scene, 15, 35);
            foo_Prints_Header_BJack (scene, betAmountPtr,playerOneCards, creditsPtr, bancaCards);
            fooprintsScenario(scene);
            controlValue=1;
            flag=0;
            break;
*/




    }
    else if (isSplitPtr!=0)
    {
        ///IMPRIME PANTALLA PARA SPLIT
        ///foo_Prints_Hand_Split(LinkedList *playerOne_1st, LinkedList *playerOne_2nd, escenarioPosicionXY scene[], int XFila, int YColumna)
    }
    else
    {
        initEscenario (scene);
        fooFrameConstruct(0, 0, 79, 20, scene, -1, -1);///BORDE ESCENARIO
        foo_Prints_Hand_Banca(banca, scene, 1, 35);
        foo_Prints_Hand(playerOne, scene, 15, 35);
        foo_Sets_Face(scene);
        foo_Resolves_After_player_Choice (scene, controlValue);///se encarga de definir el manu correspondiente
    }
}
