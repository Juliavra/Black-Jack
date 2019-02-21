
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"

void fooRandomizes_New_Card_Values (int *newCardValuePtr, int *newCardSuitPtr)      ///TIENE Q RECIBIR DOS PUNTEROS IICIALIZADOS EN NULL, CARAGAR EL RANDOM Y REVISAR Q AMBOS SEAN !=NULL Y pasar return 1 como exit 0 como failure
{
    int suit=0, value=0;


    /// printf("\t\tFOO INIT newCardValuePtr: %d\t newCardSuitPtr: %d\n", newCardValuePtr, newCardSuitPtr);

    suit = 1 + ( rand() % 4 );
    value = 1 + ( rand() % 13 );
    ///  printf("\t\tFOO carta suit: %d\t value: %d\n", suit, value);

    *newCardValuePtr=value;
    *newCardSuitPtr=suit;
    ///  printf("\t\tFOO newCardValuePtr: %d \t newCardSuitPtr: %d\n", *newCardValuePtr, *newCardSuitPtr);

}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
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

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
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

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
int setCardSuit(card* this, int *newCardSuitPtr)
{
    int rtn=-1;
    if(this != NULL && *newCardSuitPtr> 0 && *newCardSuitPtr< 5)
    {
        this->suit = *newCardSuitPtr;
        rtn=1;
    }
    return rtn;
}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
int getCardSuit (card* this)
{
    int rtn=-1;
    if(this != NULL)
    {
        rtn=this->suit;
    }

    return rtn;
}
///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
int setCardValue(card* this, int *newCardValuePtr)           /// int *newCardValuePtr  CORRESPONDE ESTE EN LUGAR DE VALIE
{
    int rtn=-1;
    if(this != NULL && *newCardValuePtr> 0 && *newCardValuePtr<14)
    {
        this->value = *newCardValuePtr;
        rtn=1;
    }
    return rtn;
}

///********************************************************************************************************************************************************************************************
///********************************************************************************************************************************************************************************************
int getCardValue (card* this)
{
    int rtn=-1;                                  ///RETRURN -1 = NOT OK
    if(this != NULL)
    {
        rtn=this->value;
    }
    return rtn;
}
///***********************************************************************************************************************************************************************************************
///***********************************************************************************************************************************************************************************************
int foo_Already_In_Deck (LinkedList *this, card* thiscard)
{
    int rtn=-1;             ///IF RTN==0 NO ESTA EN EL DECK Y DEBE AGREGARSE    ///IF RTN==1 NO DEBE AGREGARSE
    Node *tempNode=NULL;
    Node *pNode=NULL;

    printf("\nLinkedList *this: %p\n", this);
    printf("\nthiscard: %p\n", thiscard);


    if(this->pFirstNode==NULL)
    {
        rtn=0;
    }
    else
    {
        tempNode = this->pFirstNode;
        printf("\ntempNode = this->pFirstNode\n");
        printf("\n FOO ELSE tempNode: %p\n", tempNode);
        printf("\n FOO ELSE tempNode->pNextNode : %p\n", tempNode->pNextNode);

        while (tempNode->pNextNode != NULL)
        {printf("FOO PRUEBA PARA ENCONTRAR ERROR");
            if (thiscard->value==8)
            {
                printf("\nES 88888888888888888888888888888888888888888\n");
            }
            tempNode= tempNode->pNextNode;

        }
        tempNode->pNextNode=pNode;
        pNode->pNextNode=NULL;
    }
    return rtn;
}


///***********************************************************************************************************************************************************************************************
///***********************************************************************************************************************************************************************************************
