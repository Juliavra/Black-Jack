///********************************************************************************************************************************************************
///********************************************************************************************************************************************************
/// BLACK JACK EUROPEO
/// RULES
/// entre 4 y 8 mazos
/// 2 al 10 igual a su valor
/// As= 1 u 11
/// 1- Apuesta Inicial
/// 2- Dos cartas descubiertas al jugador, una al croupier
/// 3- Cada Player puede
///
/// 1. PEDIR
///	PIDE UNA CARTA

/// 2. PLANTARSE
///	FINALIZA SU TURNO


/// 3. DOBLAR
/// (SOLO LAS 2 PRIMERAS CARTAS). APUESTA IGUAL A LA INICIAL. AL DOBLAR SE RECIBE UNA CARTA MAS
///
/// 4. SEPARAR
///
/// 5. RENDIRSE
///
/// 6. APUESTA DE SEGURO
///--------------------
///CROUPIER

/// Si 16 o <  DEBE PEDIR
/// Si 17 	   DEBE PLANTARSE
/// AS vale 11 excepto q se pase
///--------------------


///init vars
///{
///    Create scene
///    Shuffle deck
///}

///Takes bets
///Deals cards
///Player(s) Play
///AI Plays
///Prizes & losses
///Goto Takes bets

#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "linkedlist.h"
#include "card.h"


///********************************************************************************************************************************************************
///********************************************************************************************************************************************************

int main()
{
    int newCardSuit=0;
    int newCardValue=0;
    int *newCardSuitPtr=NULL;
    int *newCardValuePtr=NULL;

    newCardSuit=4;
    newCardValue=13;

    newCardSuitPtr=&newCardSuit;
    newCardValuePtr=&newCardValue;;
                                                            printf("\n CHECK newCardSuit= %d\n", newCardValue);



    card *Ptr;                                              printf("card *Ptr;\n");            printf("\tCHECK: card *Ptr= %p;\n", Ptr);
     Node *cardpuntero;                                     printf("Node *cardpuntero");       printf("\tcardpuntero: %p\n", cardpuntero);

    LinkedList Deck; /*   USAR MALLOC PARA ASIGNAR ESPACIO???*/                                   printf("\nLinkedList Deck;\n");
    Deck.size=0;                                            printf("\n Deck.size=0;");  printf("\n"); printf("\tCHECK: Deck.size= %d;\n", Deck.size);
    Deck.pFirstNode=NULL;
                                                            printf("\t\tCHECK: Deck.FirstNode= %p;\n", Deck.pFirstNode);
                                                            printf("\n");

    Deck.size++;                                            printf("\n Deck.size++;"); printf("\n");  printf("\tCHECK: Deck.size= %d;\n", Deck.size);

    Deck.pFirstNode=cardpuntero;                            printf("Deck.pFirstNode=cardpuntero;");


                                                          printf("\n");  printf("\t\t\tCHECK: Deck.FirstNode= %p;\n", Deck.pFirstNode);


///system("pause");

    Ptr=(card*)malloc(sizeof(card));                        printf("\nPtr=malloc(sizeof(card))");
                                                            printf("\n"); printf("\n");

    if (Ptr== NULL)
    {
        printf("NO RESERVA MEMORIA");
    }
    else
    {
        printf("\tMemoria reservada. OK.\n");
        ///printf("\nPointer aadreess\n");
     //   printf("\nPtr %d\t", *Ptr);
   //     printf("printf Ptr suit %d\t", Ptr->suit);
       // printf("printf Ptr value %d\n", Ptr->value);
    }

                                                          ///  printf("\nLoads var\n");
    Ptr->value=12;                                          printf("\n Ptr->value=12;\t");
    Ptr->suit=3;                                            printf("Ptr->suit=3\n");
                                                            printf("\nCHECK Ptr suit %d\t", Ptr->suit);
                                                            printf("CHECK Ptr value %d\n", Ptr->value);
    Ptr=(card*)calloc(1,sizeof(card));                      printf("\nPtr=calloc(1,sizeof(card));\n");
                                                            printf("\nCHECK Ptr suit %d\t", Ptr->suit);
                                                            printf("CHECK  Ptr value %d\n", Ptr->value);




 int opcion=0;

    do
    {
    cardpuntero=(Node*)card_newCard();                                         printf("\ncardpuntero: %d\n\n", cardpuntero);

 ///VOID PELEMENT TIENE Q USAR LA DATA DE SUIT Y VALU DE CARD
 ///COMO ASIGNO UN VALOR A SUIT Y VALUE DE CARD A TRAVES DE ESTE PUNTERO????
 ///ES POSIBLE????

    fooCreatesCard (&newCardValue, &newCardSuit);




  ///    printf("\t\tMAIN newCardValuePtr: %d\t newCardSuitPtr: %d\n", newCardValuePtr, newCardSuitPtr);
      printf("\t\tMAIN newCardValue: %d\t newCardSuit: %d\n", newCardValue, newCardSuit);


     printf("\n\nDESEA SEGUIR? (!=1)\n ? ");
    fflush(stdin);
    scanf("%d", &opcion);
    ///  getche(opcion);
  ///    opcion=(int)opcion;
      printf("\n    opocin: %d", opcion);
   }
    while (opcion!=1);


    printf("   SALIENDO\n\n\n");
    system("pause");






///system("pause");
    return 0;
}

///*********************************************************************************************************************************************************************************
/*
Para solucionar este problema, debemos crear un espacio de memoria para una variable
Persona, cada vez que el usuario ingresa un nuevo ítem en la lista. Esto es posible mediante el
uso de malloc:
*/
///Persona* persona = (Persona*)malloc(sizeof(Persona));
///preguntarNombre(persona->nombre);
///persona->edad = preguntarEdad();
///lista[index] = persona;


///**********************************************************************************************************************************************************************************
///**********************************************************************************************************************************************************************************
///-------------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------
///PROGRAMA FULL CON REALLOC
/*
{
int seguirCargando;
int i;
int auxNuevaLogitud;
int logitudPersonas = 1;
struct persona* pArrayPersona;
struct persona* pAuxPersona;
// Creamos el array de personas
pArrayPersona = malloc(sizeof(struct persona));
if (pArrayPersona == NULL)
{
printf("\nNo hay lugar en memoria\n");
exit(0);
}
while(1)
{
printf("\nIngrese nombre: ");
scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
printf("\nIngrese edad: ");
scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad));
printf("\nSi desea cargar otra persona ingrese (1): ");
scanf("%d",&seguirCargando);
if(seguirCargando == 1)
{
// Calculamos el nuevo tamaño del array
auxNuevaLogitud = sizeof(struct persona) * logitudPersonas;
// Redimencionamos la lista
pAuxPersona = realloc( pArrayPersona, auxNuevaLogitud);
if (pAuxPersona == NULL)
{
printf("\nNo hay lugar en memoria\n");
break;
}
logitudPersonas++; //Incremento el contador de personas
pArrayPersona = pAuxPersona;
}
else
{
break;
}
}
*/

///-------------------------------------------------------------------------------------


///**********************************************************************************************************************************************************************************
///**********************************************************************************************************************************************************************************
/// INGRESE NOMBRE JUGADOR
/*
    char nombreAux [64];
    struct player *PlayerPtr;
    printf("Blackjack!\n");
    printf("iNICIALIZANDO VARIABLES!\n");
    PlayerPtr=(struct player*)malloc(sizeof(struct player*));
    if (PlayerPtr == NULL)
    {
    printf("\nNO QUEDA MEMORIA");
    }
    else
    {
        printf("Memoria reservada\n");
    }
    printf ("ingrese nombre de jugador 1\n");
    scanf("%s", nombreAux);
    printf("\n%s\n", nombreAux);
    ///player.name
    system("pause");
*/

///***************************************************************************************************************************************************************************
///***************************************************************************************************************************************************************************
///***************************************************************************************************************************************************************************
/// MALLOC
/*
int *a;
a=(int *)malloc(sizeof(int));
*/
/*
int *a;
a=(int *)malloc(sizeof(int));
if (a == NULL)
{
printf("NO QUEDA MEMORIA");
}
*/

/*struct ALFA{
unsigned int a;
float b;
int *c;
};
struct ALFA* d;
if ((d=(struct ALFA *)malloc(sizeof(struct ALFA)))==NULL)
exit(0);        ///Salimos del programa
*/

/// CALLOC
/*
int *a;
a=(int *)calloc(20,sizeof(int));
*/
