#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "constantes.h"
typedef struct {
    char nom[MAXNOM];
    int age ;
    char sexe[MAXSEXE];
    int ticket ;
} patient ;
  
typedef struct tnode node ;
typedef node *list;

struct tnode
{
    patient record;
    struct tnode *next;
};
typedef struct {
    node *debut;
    node *fin;
} Filedattente;
typedef struct Observation {
    patient record;
    int numerolit;
    struct Observation *next;
} listesdObservation;

void attribuerlit(listesdObservation *observation, int *nombrelits);

#endif //khaoua youcef
