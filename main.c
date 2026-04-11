//khaoua youcef et khedouci akli
#include <stdio.h>
#include<stdlib.h>
#include "structures.h"

void ticketplus(int *numero) 
{
    FILE *f = fopen("fichier1.txt", "r"); 
    int TICKET = 0;

    if (f == NULL) 
    {
        *numero = 0; 
    } 
    else 
    {
        while (fscanf(f, " %*[^0-9] %d %*[^\n]\n", &TICKET) != EOF);
        
        *numero = TICKET; 
        fclose(f);
    }
}

int main ()
{
    int nombre = 0 ;
 FILE *listesdespatiant=NULL ;
    int reponse , compteur,traitement ;
    patient p ;
    Filedattente file ;
    file.debut = NULL;
    file.fin = NULL;
char phrase[300];
int numerodobservation  = 0;
int numerodessortie = 0 ;
int numerodestransmit = 0 ;
int nombretotales =0 ;

FILE *filedobservations = NULL;
listesdObservation *debutdobservations = NULL;
reponse=1;
    while (reponse !=0)
{
printf ("\n vous voulez faire quoi :\n");
printf("0-arrter le programme-\n");
printf ("1-prendre un ticket-\n");
 printf("2-inisialisation de la file d observation\n -");
       printf("  3-afficher la file d attente (historique)-\n");
        printf( "4-orientes vers le medcin-\n");
        printf(" 5-le nombre de patient sortie-\n");
        printf(" 6-initialisation la  file d attente-\n");
        printf(" 7-le nombre de patient observes-\n");
       printf("  8-le nombre des patient en totales-\n  ");
       printf("9-le nombre des patiant transmis-\n") ;
       printf("10-afficher la liste d observation-\n");

scanf ("%d",&reponse);

if (reponse == 1) {

   ticketplus(&nombre);
p.ticket=nombre+1;
printf("veulliez remplire vos information\n");  
         printf ("votre nom et prenom\n");
        scanf(" %[^\n]", p.nom);
        printf ("votre age\n");
    scanf("%d", & p.age);
     printf("votre sex\n");
    scanf("%s",p.sexe);
    
    listesdespatiant= fopen("fichier1.txt","a");
    fprintf(listesdespatiant,"ticket numero : %d  / nom et prenom:%s / age:%d / Sexe:%s \n",p.ticket,p.nom,p.age,p.sexe);
    fclose(listesdespatiant);
    node *chaine=malloc(sizeof(node));
    chaine->record=p;
    chaine->next=NULL;
    if (file.debut == NULL)
    {
        file.debut = chaine;
        file.fin=chaine;
    } 
    else
    {
     file.fin->next= chaine;
     file.fin=chaine;  
    }
    

      printf("le patient est enregistres son ticket est:%d\n",p.ticket);
}
  if (reponse == 0)

{
  printf ("vous avez arreter le programme");

  return 1 ;

}
else if (reponse == 4)
{
    if (file.debut==NULL)
    {
        printf ("la file d attente dans la ram est vide\n");
    } else
    {
        node *sort = file.debut;
        printf("\n le patiant %s numero %d sort vers le medcin \n",sort->record.nom,sort->record.ticket);
        file.debut=file.debut->next ;
        
        printf("veulliez choisir :");
        printf("1-le patient sort-\n ");
        printf("2-le patient est sous observation-\n");
        printf("3-le patient est envoyes dans un autre deparetement -\n ");
        scanf("%d",&traitement);
        if (traitement == 1)
        {
            printf("\n le patiant %s numero %d sort\n",sort->record.nom,sort->record.ticket);
            numerodessortie = numerodessortie +1 ;
        }else if (traitement == 2)
{
    listesdObservation *chainedobservation = malloc(sizeof(listesdObservation));
    
    printf("Attribuer un numero de lit : ");
    scanf("%d", &chainedobservation->numerolit);

    chainedobservation->record.ticket = sort->record.ticket;
    chainedobservation->record.age = sort->record.age;
    
    int i = 0;
    while (sort->record.nom[i] != '\0')
    {
        chainedobservation->record.nom[i] = sort->record.nom[i];
        i++;
    }
    chainedobservation->record.nom[i] = '\0';

    filedobservations = fopen("fichier2.txt", "a");
    if (filedobservations != NULL)
    {
        fprintf(filedobservations, "Lit: %d / Nom: %s\n", chainedobservation->numerolit, sort->record.nom);
        fclose(filedobservations);
    }

    chainedobservation->next = debutdobservations;
    debutdobservations = chainedobservation;

    printf("Le patient %s est au lit %d\n", sort->record.nom, chainedobservation->numerolit);
    numerodobservation = numerodobservation +1 ;
} else if (traitement == 3)
{
     printf("\n le patiant %s numero %d a etais transmit a un autre deparetemnt\n",sort->record.nom,sort->record.ticket);
     numerodestransmit = numerodestransmit +1;
}

         
       
        if (file.debut== NULL)
        {
          file.debut= NULL ;
          file.fin= NULL ;  
        }
        free(sort);
        
    }
    
} if (reponse == 3)
{
    listesdespatiant = fopen("fichier1.txt", "r");
    if (listesdespatiant == NULL)
    {
        printf("la file d attente est vide\n");
    } else
    {
        listesdespatiant= fopen("fichier1.txt","r");
while (fgets(phrase, 300, listesdespatiant) != NULL) {
    printf("%s", phrase);
}
    }
    
} if (reponse == 8)
{
    ticketplus(&compteur);
    printf("le nombre totales des pataient est %d \n",compteur);
    nombretotales = numerodessortie + numerodestransmit +numerodobservation ;
    printf("c est juste pour verifier le nombre totales =%d\n",nombretotales);
}
if (reponse == 6)
{
     listesdespatiant= fopen("fichier1.txt","w");
        fclose(listesdespatiant);
    
    file.debut = NULL;
    file.fin = NULL;
    nombre = 0;
     printf("\n le file d attente  a etais initialisate \n");
}if (reponse == 2)
{
filedobservations= fopen("fichier2.txt","w");
        fclose(listesdespatiant);
     printf("\n le file d observation etais inisialiter \n");
}
if (reponse == 5)
{
    printf("le nmbre des persones sortie est : %d \n",numerodessortie);
}if (reponse == 7)
{
    printf("le nombre des perssone sous observation est\n :%d",numerodobservation);
}if (reponse == 9)
{
    printf("le nombre des perssone transmis est :%d \n",numerodestransmit);
}
if (reponse == 10);
{
    filedobservations = fopen("fichier2.txt","r");
    if (filedobservations == NULL)
    {
        printf("la liste est vide");
    } else {
    
            filedobservations= fopen("fichier2.txt","r");
while (fgets(phrase, 300, filedobservations) != NULL) {
    printf("%s", phrase);
}

    

    }




}
}
return 0 ;
}  // mini projet