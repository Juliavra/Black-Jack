
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"

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
                printf("\nNULL\n");
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
///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int foo_Already_In_Deck (LinkedList *this, card* thiscard)
{
    int rtn=0;             ///IF RTN==0 NO ESTA EN EL DECK Y DEBE AGREGARSE    ///IF RTN==-1 NO DEBE AGREGARSE
    return rtn;
}

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

    printf("\nNodeDeck: %p\t", NodeDeck);
    printf("\tNodeOther: %p\n", NodeOther);

    card *Deckcard;
    card *othercard;

    Deckcard=card_newCard();
    othercard=card_newCard();

    printf("\n DeckCard\n");
    imprimeLinkedList(Deck);
    printf("\n\n\n OtherCard\n");
    imprimeLinkedList(other);

///system("pause");
    printf("\nDeckcard->suit: %d\t", Deckcard->suit);
    printf("\tDeckcard->value: %d\n", Deckcard->value);
    printf("\nothercard->suit: %d\t", othercard->suit);
    printf("\tothercard->value: %d\n", othercard->value);

do{
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

 }while(NodeDeck!=NULL);

printf("NodeOther: %p", NodeOther);
 printf("NodeOther->pNextNode: %p", NodeOther->pNextNode);

    printf("\n\nOther deberia estar vacio debajo!!!!!!\n\n\n");
    imprimeLinkedList(other);
    return rtn;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
