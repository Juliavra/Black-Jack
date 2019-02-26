/*
typedef struct node
{
    int data;    ///PTR a Void
    struct node *next;
}node;


node *createLinkedList (int n);
void displayLinkedList (node *head);

int main()
{

int n=52;
node *HEAD = NULL;

printf("How many nodes");
scanf("%d", &n);
HEAD=createLinkedList(n);
displayLinkedList(HEAD);


    return 0;
}
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
node *createLinkedList (int n)
{
    int i=0;

    node *head =NULL;
    node *temp =NULL;
    node *p =NULL;

    for (i=0;i<n;i++)
    {
        temp = (node*)malloc (sizeof(node));
        printf("enter data", i+1);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (head==NULL)
            {
                head=temp;
            }
        else
        {
             p=head;
             while (p->next!=NULL)
             {
                p=p->next;
             }
             p->next=temp;
        }
    }
        return head;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void displayLinkedList (node *head)
{
    node *p=head;
    while(p!=NULL)
    {
        printf("\t %d->", p->data);
        p=p->next;
    }
}
*/
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Para solucionar este problema, debemos crear un espacio de memoria para una variable
Persona, cada vez que el usuario ingresa un nuevo ítem en la lista. Esto es posible mediante el
uso de malloc:
*/
///Persona* persona = (Persona*)malloc(sizeof(Persona));
///preguntarNombre(persona->nombre);
///persona->edad = preguntarEdad();
///lista[index] = persona;


///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
