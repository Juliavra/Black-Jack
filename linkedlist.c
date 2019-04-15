#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "card.h"



///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* ll_newLinkedList(void)
{
    LinkedList* ll_newLinkedList=NULL;
    //printf("\n FOO CHECK ll_newLinkedList: %p\n", ll_newLinkedList);

    ll_newLinkedList=(LinkedList*)malloc(sizeof(LinkedList));

    //printf("\n FOO CHECK post MALLOC ll_newLinkedList: %p\n", ll_newLinkedList);
    if (ll_newLinkedList==NULL)
    {
        printf("NO MEMORIA PARA LLIST");
    }
    else
    {
        ll_newLinkedList->index=0;
        ll_newLinkedList->size=0;
        ll_newLinkedList->pFirstNode=NULL;
    }

    return ll_newLinkedList;
}


///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void imprimeLinkedList (LinkedList *this)
{
    card *card=NULL;
    Node *p=this->pFirstNode;
    ///  printf("\n\nFOO IMPRIME Node *p= %p\n", p);
   /// printf("\n %p->", p);

    if (p==NULL)
    {
        printf("\n FOO imprimeLinkedList: Linked List esta VACIA!!!");
    }
///printf("AAAAAAAAAAAACCCCCCCCCCCCCCCCCCCCAAAAAAAAAAAAA");
    while(p!=NULL)
    {
        card=p->pElement;
        printf("\n %p->\t", p);
        printf("S: %d  \t", card->suit);
        printf("V: %d  ", card->value);
        //   printf(" this->size: %d", this->size);
        printf(" p->pNextNode %p", p->pNextNode);
        p=p->pNextNode;

        // system("pause");
    }

}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Node* Node_NewNode(char *nombreNewNode)
{
    Node* newNode;
    newNode=(Node*)malloc(sizeof(Node));

    if (newNode== NULL)
    {
        printf("\nNO RESERVA MEMORIA PARA %s\n",nombreNewNode);
    }
    else
    {
        newNode->pNextNode=NULL;
     ///       printf("\n***Memoria reservada para %s %p -> OK.\n",nombreNewNode, newNode);
    }
    return newNode;
}/// CLOSES FOO NODE NEW NODE
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Node* foo_Finds_Last_Node (LinkedList *this)
{
    Node *tempNode=NULL;

    if (this->pFirstNode == NULL)
    {
        printf("\n\nfoo_Finds_Last_Node pFirstNode == NULL\n\n");
    }
    tempNode=this->pFirstNode;

    while (tempNode->pNextNode!=NULL)
    {
        tempNode=tempNode->pNextNode;
    }
    return tempNode;
}
///--------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------

LinkedList* foo_Creates_Decks_Randomly ()
{
    card *nuevacarta;
    card *nuevacartatempNode;
    int agregarCarta=-1;
    int number_Of_Generated_Cards=0;

    card *cardPtr;
    LinkedList *Deck;
    Deck=ll_newLinkedList();

    Node *pNode=NULL;
    Node *tempNode=NULL;
    Node *Next_ll_Node=NULL;
    Node *lastNode=NULL;

    pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly");
    tempNode=Node_NewNode("tempNode foo_Creates_Decks_Randomly");
    Next_ll_Node=Node_NewNode("Next_ll_Node foo_Creates_Decks_Randomly");
    lastNode=Node_NewNode("Next_ll_Node foo_Creates_Decks_Randomly");

    pNode->pNextNode=NULL;
    tempNode->pNextNode=NULL;
    Next_ll_Node->pNextNode=NULL;
    lastNode->pNextNode=NULL;

    cardPtr=(card*)card_newCard();
    cardPtr=fooRandomizes_New_Card_Values ();
    pNode->pElement=cardPtr;
    Deck->pFirstNode= Next_ll_Node;
    Next_ll_Node->pElement=pNode->pElement;
    Deck->size=1;

    do
    {

        cardPtr=(card*)card_newCard();
        cardPtr=fooRandomizes_New_Card_Values ();
        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly");
        pNode->pElement=cardPtr;
        tempNode=Deck->pFirstNode;

        while (tempNode != NULL)
        {
            nuevacarta=(card*)pNode->pElement;
            nuevacartatempNode= (card*)tempNode->pElement;
            if (nuevacarta->value==nuevacartatempNode->value)
            {
                if (nuevacarta->suit==nuevacartatempNode->suit)
                {
                    agregarCarta=-1;
                    break;///NO CAMBIA NADA
                }
            }
            tempNode= tempNode->pNextNode;
        }///CLOSES WHILE
        if (agregarCarta!=0)
        {
            free(pNode);
        }
        else
        {
            lastNode=foo_Finds_Last_Node (Deck);
            Next_ll_Node=Node_NewNode("Next_ll_Node foo_Creates_Decks_Randomly");
            Next_ll_Node->pElement=pNode->pElement;
            lastNode->pNextNode=Next_ll_Node;

            pNode->pNextNode=NULL;
            Deck->size++;
        }
        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        tempNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        pNode->pNextNode=NULL;
        tempNode->pNextNode=NULL;
        agregarCarta=0;

        number_Of_Generated_Cards++;

    }
    while (Deck->size<=51);

    return Deck;
}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Node* foo_Finds_First_Node_And_Removes_It (LinkedList *this)
{
    Node *tempNode=NULL;
    Node *FirstNode=NULL;
    Node *SecondNode=NULL;

    tempNode=Node_NewNode("");
    FirstNode=Node_NewNode("");
    SecondNode=Node_NewNode("");

    if (this->pFirstNode == NULL)
    {
        ///printf("\n\nfoo_Finds_First_Node pFirstNode == NULL\nNO HAY CARTAS EN ESA LINKED LIST\n");
        tempNode=NULL;
        ///SE CUELGA AQUI CUANDO ESTA FOO NO ENCUENTRA NADA Y TEMPNODE == NULL
        /// HAY Q PODER DEVOLVER ESE VALOR (NULL) A QUIEN LO LLAMA,
        ///Y QUE ESTA SE ENCARGUE DE RESPONDER EN CASO QUE NO HAYA CARTAS

    }
    else
    {
    FirstNode=this->pFirstNode;
    SecondNode=FirstNode->pNextNode;

    tempNode=FirstNode;     /// printf("\ntempNode: %p\n", tempNode); // printf("\nFirstNode: %p\n", FirstNode);    // printf("\nSecondNode: %p\n", SecondNode);
    tempNode->pNextNode=NULL;
    this->pFirstNode=SecondNode;        ///imprimeLinkedList(this);
    }
    return tempNode;
}
///--------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------
int foo_Are_initial_Cards_Equal (LinkedList *this)
{
    int rtn=0;     ///0=FALSE      1=TRUE
    Node *tempNode1=NULL;
    Node *tempNode2=NULL;

    card *card1=NULL;
    card *card2=NULL;

    tempNode1=this->pFirstNode;
    tempNode2=tempNode1->pNextNode;

    card1=(card*) tempNode1->pElement;
    card2=(card*) tempNode2->pElement;

    if (card1->value==card2->value)
    {
        printf("las cartas valen igual");
        rtn=1;
    }

    return rtn;
}

///----------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* foo_HARCODE_DATA_DECK(LinkedList *this)
{
    LinkedList *templl;
    templl=ll_newLinkedList();
    Node *NodePtr=NULL;
    card *cardPtr=NULL;
///    card *nuevacarta=NULL;
    ///card *nuevacartatempNode=NULL;

    Node *PRIMERNODO=NULL;
    Node *pNode=NULL;
    Node *tempNode=NULL;
    int i=0;
    int arrayValues2Harcode[52]= {3,2,3,4,5,6,7,4,9,3,6,1,7,6,5,13,4,12,6,8,5,8,9,10,11,12,13,7,13,12,5,10,8,3,5,1,2,2,2,2,9,5,6,4,7,2,1,13,12,1,5,9};

    cardPtr=card_newCard();
    NodePtr=Node_NewNode("");
    PRIMERNODO=Node_NewNode("");
    templl->pFirstNode=PRIMERNODO;
    cardPtr->suit=1;
    cardPtr->value=arrayValues2Harcode[0];
    PRIMERNODO->pElement=cardPtr;
    ///printf("HARCODE DATA FOO ");
    i++;
    while(i<52)         ///EL VALOR NO ES I, SINO LINKED LIST SIZE < 52
    {
        cardPtr=(card*)card_newCard();
        cardPtr->suit=1;
        cardPtr->value=arrayValues2Harcode[i];
        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly");
        pNode->pElement=cardPtr;
        tempNode=templl->pFirstNode;
        Node *Next_ll_Node=NULL;
        Node *lastNode=NULL;

        lastNode=foo_Finds_Last_Node (templl);
        Next_ll_Node=Node_NewNode("Next_ll_Node foo_Creates_Decks_Randomly");
        Next_ll_Node->pElement=pNode->pElement;
        lastNode->pNextNode=Next_ll_Node;

        pNode->pNextNode=NULL;
        templl->size++;

        pNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        tempNode=Node_NewNode("pNode foo_Creates_Decks_Randomly luego de evaluar card");
        pNode->pNextNode=NULL;
        tempNode->pNextNode=NULL;
        i++;
    }
    this=templl;
   /// imprimeLinkedList(this);

    return this;
}
///----------------------------------------------------------------------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* ll_clone(LinkedList* this)
{
    int cardToBeClonedValue=0, cardToBeClonedSuit=0;
    LinkedList *cloned_List;
    cloned_List=ll_newLinkedList();

    card *cardClone=NULL;
    card *card=NULL;

    Node *tempNode=NULL;
    Node *tempNode2=NULL;
    Node *lastNode=NULL;
    tempNode=Node_NewNode("");
    tempNode2=Node_NewNode("");
    lastNode=Node_NewNode("");
    card=card_newCard();
    cardClone=card_newCard();

    tempNode=this->pFirstNode;              ///printf("tempNode: %d", tempNode);
    tempNode->pNextNode=NULL;
    tempNode2->pNextNode=NULL;

    if (tempNode==NULL)
    {
        printf("\n FOO CLONE Linked List THIS esta VACIA!!!");
    }
        while(tempNode!=NULL)
    {
        card=tempNode->pElement;               /// printf("\ncard->suit: %d\n", card->suit);           printf("\ncard->value: %d\n", card->value);


        cardToBeClonedValue=card->value;                     printf("\n cardToBeClonedValue: %d\n", cardToBeClonedValue);
        cardToBeClonedSuit=card->suit;                     printf("\n cardToBeClonedSuit: %d\n", cardToBeClonedSuit);

        cardClone->value=cardToBeClonedValue;               printf("\n  cardClone->value: %d\n",  cardClone->value);
        cardClone->suit=cardToBeClonedSuit;

        tempNode2->pElement=cardClone;

        if(cloned_List->pFirstNode==NULL)
        {
           cloned_List->pFirstNode=tempNode2;       imprimeLinkedList(cloned_List);     printf("\nHE AQUI EL ERROR????\n");
    system("pause");

        }
        else
        {

            lastNode=(Node*)foo_Finds_Last_Node (cloned_List);
            lastNode->pNextNode=tempNode2;
        }
        tempNode=tempNode->pNextNode;

        ///HAY QUE CLONAR LOS DEMAS DATOS ADEMAS DEL PRIMERO

        ///tempNode2=Node_NewNode("");
    }

printf("\n\n\n FOO FOO  FOO  MUESTRA LA LISTA CLONADA\n\n\n");
    imprimeLinkedList(cloned_List);
    system("pause");

    return cloned_List;
}





