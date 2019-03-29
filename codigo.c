
         /*
           tempNode2=gets_First_Card(Deck);
            tempNode2->pNextNode=NULL;
            tempNode=playerOne_1st->pFirstNode;
             tempNode->pNextNode=tempNode2;

            tempNode=playerOne_2nd->pFirstNode;
             tempNode->pNextNode=tempNode2;
*/



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
