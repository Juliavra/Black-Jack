
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"
#include "scenario.h"


card* fooRandomizes_New_Card_Values (void)
{
    int suit=0, value=0;
    card *NewCard=NULL;
    NewCard=(card*)card_newCard();
    value=fooRandomizes_New_Card_Value();
    suit=fooRandomizes_New_Card_Suit();
    setCardValue(NewCard, value);
    setCardSuit(NewCard, suit);
    return NewCard;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int fooRandomizes_New_Card_Value (void)
{
    int value=-1;
    value = 1 + ( rand() % 13 );
    return value;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int fooRandomizes_New_Card_Suit(void)
{
    int suit=-1;
    suit = 1 + ( rand() % 4 );
    return suit;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
card* card_newCard(void)
{
    card* this = (card*)malloc(sizeof(card));
    if (this!= NULL)
    {
        this->suit=-1;
        this->value=-1;
    }
    return this;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
card* cardCalloc_newCard(void)
{
    card *this;
    this=(card*)calloc(1,sizeof(card));
    if (this != NULL)
    {
        printf("Unable to Calloc");
        //this->suit=-1;
        //this->value=-1;
    }
    return this;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int setCardSuit(card* this, int suit)
{
    int rtn=-1;
    if(this != NULL && suit> 0 && suit< 5)
    {
        this->suit = suit;
        rtn=1;
    }
    return rtn;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int getCardSuit (card* this)
{
    int rtn=-1;
    if(this != NULL)
    {
        rtn=this->suit;
    }
    return rtn;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int setCardValue(card* this, int value)
{
    int rtn=-1;
    if(this != NULL && value> 0 && value<14)
    {
        this->value = value;
        rtn=1;
    }
    return rtn;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int getCardValue (card* this)
{
    int rtn=-1;                                  ///RETRURN -1 = NOT OK
    if(this != NULL)
    {
        rtn=this->value;
    }
    return rtn;
}
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* foo_New_Deck()
{
    int i=0, j=0;

    Node *pNode=NULL;
    Node *tempNode=NULL;

    card *card_Ptr;
    LinkedList *this;
    this=ll_newLinkedList();
    pNode=Node_NewNode("");
    tempNode=Node_NewNode("");
    pNode->pNextNode=NULL;

    for (i=1; i<5; i++)
    {
        for (j=1; j<14; j++)
        {
            if (this->pFirstNode==NULL)
            {
                card_Ptr=(card*) card_newCard();
                card_Ptr->suit=i;
                card_Ptr->value=j;
                pNode->pElement=card_Ptr;
                this->pFirstNode= pNode;
                this->size++;
            ///    printf("\nNULL\n");
                /// system("pause");
            }
            else
            {
                pNode=Node_NewNode("pNode FOO NEW DECK ");
                this->size++;
                card_Ptr=(card*) card_newCard();
                card_Ptr->suit=i;
                card_Ptr->value=j;
                pNode->pElement=card_Ptr;
                tempNode=this->pFirstNode;
                while (tempNode->pNextNode!=NULL)
                {
                    tempNode=tempNode->pNextNode;
                }
                tempNode->pNextNode=pNode;
            }
        }
    }
    return this;
}
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Compare_Decks (LinkedList *Deck, LinkedList *other)
{
    int rtn=0, contador=0;

    Node *NodeDeck=NULL;
    Node *NodeOther=NULL;

    NodeDeck=Node_NewNode("NodeDeck");
    NodeOther=Node_NewNode("NodeOther");
    NodeDeck=Deck->pFirstNode;
    NodeOther=other->pFirstNode;

///    printf("\nNodeDeck: %p\t", NodeDeck);
///    printf("\tNodeOther: %p\n", NodeOther);

    card *Deckcard;
    card *othercard;

    Deckcard=card_newCard();
    othercard=card_newCard();

    printf("\n DeckCard\n");
   /// imprimeLinkedList(Deck);
    printf("\n\n\n OtherCard\n");
///    imprimeLinkedList(other);

///system("pause");
    printf("\nDeckcard->suit: %d\t", Deckcard->suit);
    printf("\tDeckcard->value: %d\n", Deckcard->value);
    printf("\nothercard->suit: %d\t", othercard->suit);
    printf("\tothercard->value: %d\n", othercard->value);

    do
    {
        while (NodeOther!=NULL)          ///while (NodeOther->pNextNode!=NULL)
        {
            Deckcard=NodeDeck->pElement;
            othercard=NodeOther->pElement;

            printf("\nDeckcard->suit: %d\t", Deckcard->suit);
            printf("\tDeckcard->value: %d\n", Deckcard->value);
            printf("\nothercard->suit: %d\t", othercard->suit);
            printf("\tothercard->value: %d\n", othercard->value);

            if (Deckcard->suit==othercard->suit)
            {
                printf("\nsuit ==\n");
                if (Deckcard->value==othercard->value)
                {
                    printf("\nvalue==\n");
                    othercard->suit=-1;
                    ///  othercard->value=-1;
                    ///             system("pause");
                    contador++;
                    printf("\n contador: %d", contador);
                    break;
                }
            }
            NodeOther=NodeOther->pNextNode;
        }
        NodeOther=other->pFirstNode;
        NodeDeck=NodeDeck->pNextNode;

        printf("NodeOther: %p", NodeOther);
        printf("NodeOther->pNextNode: %p", NodeOther->pNextNode);

        imprimeLinkedList(other);

    }
    while(NodeDeck!=NULL);

    printf("NodeOther: %p", NodeOther);
    printf("NodeOther->pNextNode: %p", NodeOther->pNextNode);

    printf("\n\nOther deberia estar vacio debajo!!!!!!\n\n\n");
    imprimeLinkedList(other);
    return rtn;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Adds_Cards_Value (LinkedList *this)
{
    ///FALTA ARMAR LA PARTE DEL AS Q ES 1 U 11
    Node *tempNode=NULL;
    int cardSum=0, cardToAdd=0;
    card *cardValue=NULL;

    tempNode=this->pFirstNode;

    while (tempNode!=NULL)
    {
        cardValue= (card*)tempNode->pElement;
        //  printf("cardValue:%d", cardValue);
        //   system("pause");

        if (cardValue->value==1)
        {
            cardToAdd=11;
      ///      printf("\n\n\nAS debe valer 11\n\n\n");
       ///     system("pause");
        }
        else if (cardValue->value==11 || cardValue->value==12 || cardValue->value==13 )
        {
            cardToAdd=10;
        }
        else
        {
            cardToAdd=cardValue->value;
        }
        cardSum=cardSum+cardToAdd;
        tempNode=tempNode->pNextNode;
    }
    return cardSum;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void foo_Card_ConStruct_Scenario(int XFila, int YColumna, escenarioPosicionXY scene[], card *this)
{
    int lineaParalela=0;
    int i=0, j=0, k=0, t=0,  valorScene=0;
    int largoCaja=4, altoCaja=4;
    int suit=0, value=0;

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

    ///SUIT
    suit=foo_Suit_To_Print (this);
    scene[valorScene+162].charAImprimir=suit;

    ///VALOR CARTA
    value=foo_Value_To_Print (this);
    scene[valorScene+83].charAImprimir=value;
}
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------
void foo_Card_ConStruct_Empty(int XFila, int YColumna, escenarioPosicionXY scene[])
{
    int lineaParalela=0;
    int i=0, j=0, k=0, t=0,  valorScene=0;
    int largoCaja=4, altoCaja=4;

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
}
///-------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Suit_To_Print (card *this)
{
    int suit=0;

    switch (this->suit)
    {
    case 1:
    {
        suit=3;
        break;
    }
    case 2:
    {
        suit=4;
        break;
    }
    case 3:
    {
        suit=5;
        break;
    }
    case 4:
    {
        suit=6;
        break;
    }
    default:
    {
        break;
    }
    }
    return suit;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Value_To_Print (card *this)
{
    int value;

    switch (this->value)
    {
    case 1:
    {
        value=65;
        break;
    }
    case 2:
    {
        value=50;
        break;
    }
    case 3:
    {
        value=51;
        break;
    }
    case 4:
    {
        value=52;
        break;
    }
    case 5:
    {
        value=53;
        break;
    }
    case 6:
    {
        value=54;
        break;
    }
    case 7:
    {
        value=55;
        break;
    }
    case 8:
    {
        value=56;
        break;
    }
    case 9:
    {
        value=57;
        break;
    }
    case 10:
    {
        value=88;
        break;
    }
    case 11:
    {
        value=74;
        break;
    }
    case 12:
    {
        value=81;
        break;
    }
    case 13:
    {
        value=75;
        break;
    }
    default:
    {
        break;
    }
    }
    return value;
}
///----------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------
void foo_Prints_Hand(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna)
{
    Node *tempNode=NULL;
    card *cardToBePrinted;
    tempNode= this->pFirstNode;

    while (tempNode!=NULL)
    {
        cardToBePrinted=tempNode->pElement;
        foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
        YColumna=YColumna+6;
        tempNode=tempNode->pNextNode;
    }
}
///----------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------
void foo_Prints_Hand_Banca(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna)
{
    Node *tempNode=NULL;
    card *cardToBePrinted;
    tempNode= this->pFirstNode;

   while (tempNode!=NULL)
    {
        cardToBePrinted=tempNode->pElement;
        foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
        YColumna=YColumna+6;
        tempNode=tempNode->pNextNode;
    }

    foo_Card_ConStruct_Empty(1, 41, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------
void foo_Prints_Hand_Banca_Shows_Both_Cards(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna)
{
    Node *tempNode=NULL;
    card *cardToBePrinted;
    tempNode= this->pFirstNode;

    while (tempNode!=NULL)
    {
        cardToBePrinted=tempNode->pElement;
        foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
        YColumna=YColumna+6;
        tempNode=tempNode->pNextNode;
    }

    /// foo_Card_ConStruct_Empty(1, 41, scene);///CREAR CARTA VACIA PARA PRESENTAR LA MESA
}
///-----------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Adds_Cards_Value_Banca (LinkedList *this)
{
    ///FALTA ARMAR LA PARTE DEL AS Q ES 1 U 11
    Node *tempNode=NULL;
    int cardSum=0, cardToAdd=0;
    card *cardValue=NULL;

    tempNode=this->pFirstNode;

    while (tempNode!=NULL)
    {
        cardValue= (card*)tempNode->pElement;
        ///     printf("\nfoo_Adds_Cards_Value_Banca\n", cardValue->suit);
        /// printf("\ncardValue->suit:%d\n", cardValue->suit);
    ///    printf("\ncardValue->value:%d\n", cardValue->value);
        ///   system("pause");
        if (cardValue->value==1)
        {
            cardToAdd=11;
        }
        else if (cardValue->value==11 || cardValue->value==12 || cardValue->value==13 )
        {
            cardToAdd=10;
        }
        else
        {
            cardToAdd=cardValue->value;
        }
        cardSum=cardSum+cardToAdd;
        if (cardSum>21)
        {
            ///opcion 1 crear un contador q indique q hay un o mas ases
            ///y en ese caso se descuenta 10 si se paso
        }
     ///   printf("cardSum: %d", cardSum);
        tempNode=tempNode->pNextNode;
    }
    return cardSum;
}

///-----------------------------------------------------------------
///-----------------------------------------------------------------
void foo_Prints_Hand_Double(LinkedList *this, escenarioPosicionXY scene[], int XFila, int YColumna)
{
    Node *tempNode=NULL;
    card *cardToBePrinted;
    tempNode= this->pFirstNode;
    int contador=0;

    while (tempNode!=NULL)
    {
        contador++;
        if (contador<3)
        {
            cardToBePrinted=tempNode->pElement;
            foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
            YColumna=YColumna+6;
            tempNode=tempNode->pNextNode;
        }
        else
        {
            cardToBePrinted=tempNode->pElement;
            foo_Card_ConStruct_Scenario(10, 38, scene, cardToBePrinted);
            tempNode=tempNode->pNextNode;
        }
    }
}
///------------------------------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------------------------------
void foo_Prints_Hand_Split(LinkedList *playerOne_1st, LinkedList *playerOne_2nd, escenarioPosicionXY scene[], int XFila, int YColumna)
{
    Node *tempNode=NULL;
    card *cardToBePrinted;
    tempNode= playerOne_1st->pFirstNode;

    while (tempNode!=NULL)
    {
      ///printf("\n\nTemp Node: %p\n\n", tempNode);
    ///system("pause");
            cardToBePrinted=tempNode->pElement;
            foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
            YColumna=YColumna+26;
            tempNode=tempNode->pNextNode;
    }

 tempNode= playerOne_2nd->pFirstNode;

    while (tempNode!=NULL)
    {
      ///printf("\n\nTemp Node: %p\n\n", tempNode);
    ///system("pause");
            cardToBePrinted=tempNode->pElement;
            foo_Card_ConStruct_Scenario(XFila, YColumna, scene, cardToBePrinted);
            YColumna=YColumna+6;
            tempNode=tempNode->pNextNode;
    }

}
///------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void foo_Card_Erase_From_Scenario(int XFila, int YColumna, escenarioPosicionXY scene[])
{
    int lineaParalela=0;
    int i=0, j=0, k=0, t=0,  valorScene=0;
    int largoCaja=4, altoCaja=4;
    int suit=0, value=0;

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
        scene[valorScene+j].charAImprimir=0;///196
        scene[valorScene+lineaParalela+j].charAImprimir=0;///196
    }
    for(k=valorScene; k<valorScene+lineaParalela; k=k+80)
    {
        scene[k].charAImprimir=0;
    }
    for(k=valorScene+largoCaja; k<valorScene+lineaParalela+largoCaja; k=k+80)
    {
        scene[k].charAImprimir=0;
    }

    ///BORDES SCENARIO
    scene[valorScene].charAImprimir=0; ///218
    scene[valorScene+largoCaja].charAImprimir=0; ///191
    scene[valorScene+lineaParalela].charAImprimir=0; ///192
    scene[valorScene+lineaParalela+largoCaja].charAImprimir=0; ///217

    ///SUIT
   scene[valorScene+162].charAImprimir=0;

    ///VALOR CARTA
   scene[valorScene+83].charAImprimir=0;
}
///-------------------------------------------------------------------------------------------------------------------------------------------------------
