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

int main ()
{
    int nombre = 0 ;
 FILE *listesdespatiant=NULL ;
    int reponse ;
    patient p ;

    reponse=1;
    while (reponse !=0)
{
printf ("vous voulez faire quoi\n");
printf("0-arrter le programme-\n");
printf ("1-prendre un ticket-\n");
     printf( "   2-ajouter a la file d attente-\n");
       printf("  3-afficher la file d attente-\n");
        printf( "4-orientes vers le medcin-\n");
        printf(" 5-le nombre de patient sortie-\n");
        printf(" 6-le nombre de patient transfert-\n");
        printf(" 7-le nombre de patient observes-\n");
       printf("  8-le nombre des patient en totales-\n  ");

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
    scanf("%s",p.sex);
    node *chaine =  (node*)malloc(sizeof(node));

    if (chaine != NULL)

    {

        chaine->record = p;
        chaine->next=NULL;
    listesdespatiant= fopen("fichier1.txt","a");
    fprintf(listesdespatiant,"ticket numero : %d  / nom et prenom:%s / age:%d / Sex:%s \n",p.ticket,p.nom,p.age,p.sex);
    fclose(listesdespatiant);
      

      printf("le patient est enregistres son ticket est:%d\n",p.ticket);
}
}
}  if (reponse == 0)

{
  printf ("vous avez arrter le programme");

  return 1 ;
//khaoua youcef
}
return 0 ;
}