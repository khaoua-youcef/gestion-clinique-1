#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "constantes.h"
typedef struct {
    char nom[MAXNOM];
    int age ;
    char sex[MAXSEX];
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
typedef struct obs_node {
    patient record;
    int numero_lit;
    struct obs_node *next;
} listesdObservation;
#endif //khaoua youcef