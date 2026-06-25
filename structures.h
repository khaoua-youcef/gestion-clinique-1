#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "constantes.h"
typedef struct {
    char nom[MAXNOM];
    int age ;
    char sexe[MAXSEXE];
    int ticket ;
} patient ;
  
typedef struct tnode
{
    patient record;
    struct tnode *next;
} node;

typedef node *list;
typedef struct {
    node *debut;
    node *fin;
} FileAttente;
typedef struct Observation {
    patient record;
    int numerolit;
    struct Observation *next;
} ListeObservation;

void attribuerlit(ListeObservation *observation, int *nombrelits);

#endif //khaoua youcef
