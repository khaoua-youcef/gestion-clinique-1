//khaoua youcef 
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

void attribuerlit(listesdObservation *observation, int *nombrelits)
{
    *nombrelits = *nombrelits + 1;
    observation->numerolit = *nombrelits;
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
int nombrelits = 0;

FILE *filedobservations = NULL;
listesdObservation *debutdobservations = NULL;
reponse=1;
    while (reponse !=0)
{
printf ("             Que voulez-vous faire ?\n");
printf("0-Arreter le programme-\n");
printf ("1-Prendre un ticket-\n");
 printf("2-Initialisation de la file d'observation\n -");
       printf("  3-Afficher la file d'attente (historique)-\n");
        printf( "4-Orienter vers le medecin-\n");
        printf(" 5-Le nombre de patients sortis-\n");
        printf(" 6-Initialiser la file d'attente-\n");
        printf(" 7-Le nombre de patients observes-\n");
       printf("  8-Le nombre total de patients-\n  ");
       printf("9-Le nombre de patients transmis-\n") ;
       printf("10-Afficher la liste d'observation-\n");
      

scanf ("%d",&reponse);

if (reponse == 1) {

   ticketplus(&nombre);
p.ticket=nombre+1;
printf("Veuillez remplir vos informations\n");  
         printf ("Votre nom et prenom\n");
        scanf(" %[^\n]", p.nom);
        printf ("Votre age\n");
    scanf("%d", & p.age);
     printf("Votre sexe\n");
    scanf("%s",p.sexe);
    
    listesdespatiant= fopen("fichier1.txt","a");
    fprintf(listesdespatiant,"Ticket numero : %d  / Nom et prenom : %s / age : %d / Sexe : %s \n",p.ticket,p.nom,p.age,p.sexe);
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
    

      printf("Le patient est enregistre. Son ticket est : %d\n",p.ticket);
}
  if (reponse == 0)

{
  printf ("Vous avez arrete le programme");

  return 1 ;

}
else if (reponse == 4)
{
    if (file.debut==NULL)
    {
        printf ("La file d'attente dans la RAM est vide\n");
    } else
    {
        node *sort = file.debut;
        printf("\nLe patient %s numero %d sort vers le medecin\n",sort->record.nom,sort->record.ticket);
        file.debut=file.debut->next ;
        
        printf("Veuillez choisir :");
        printf("1-Le patient sort-\n ");
        printf("2-Le patient est sous observation -\n");
        printf("3-Le patient est envoye dans un autre departement-\n ");
        scanf("%d",&traitement);
        if (traitement == 1)
        {
            printf("\nLe patient %s numero %d sort\n",sort->record.nom,sort->record.ticket);
            numerodessortie = numerodessortie +1 ;
        }else if (traitement == 2)
{
    listesdObservation *chainedobservation = malloc(sizeof(listesdObservation));
    
    attribuerlit(chainedobservation, &nombrelits);
    printf("Le numero de lit attribue est : %d\n", chainedobservation->numerolit);

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
     printf("\nLe patient %s numero %d a ete transmis a un autre departement\n",sort->record.nom,sort->record.ticket);
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
        printf("\nLa file d'attente n'est pas creee\n");
    } else
    {
        
while (fgets(phrase, 300, listesdespatiant) != NULL) {
    printf("%s", phrase);
    if (phrase == NULL){
        printf("La file d'attente est vide");
    }
}
    }fclose(listesdespatiant);
    
} if (reponse == 8)
{
    nombretotales = numerodessortie + numerodestransmit +numerodobservation ;
    printf(" le nombre total des patiant= %d\n",nombretotales);
}
if (reponse == 6)
{
     listesdespatiant= fopen("fichier1.txt","w");
        fclose(listesdespatiant);
    
    file.debut = NULL;
    file.fin = NULL;
    nombre = 0;
    printf("la file dattente a etais inisialiser\n");

}if (reponse == 2)
{
filedobservations= fopen("fichier2.txt","w");
        fclose(filedobservations);
        debutdobservations = NULL;
        numerodobservation = 0;
        nombrelits = 0;
     printf("\nLa file d'observation a ete initialisee\n");
}
if (reponse == 5)
{
    printf("Le nombre de personnes sorties est : %d \n",numerodessortie);
}if (reponse == 7)
{
    printf("Le nombre de personnes sous observation est\n :%d",numerodobservation);
}if (reponse == 9)
{
    printf("Le nombre de personnes transmises est : %d \n",numerodestransmit);
}
if (reponse == 10)
{
    filedobservations = fopen("fichier2.txt","r");
    if (filedobservations == NULL)
    {
      printf("\nLa file est vide");
    } else {
    
while (fgets(phrase, 300, filedobservations) != NULL) {
    if (phrase == NULL)
    {
      printf("la file dobservation est dejas vide");
    }
    else 
    {
        printf("%s", phrase);    }
    
    
} fclose(filedobservations);

    }

}
}
return 0 ;
}  
