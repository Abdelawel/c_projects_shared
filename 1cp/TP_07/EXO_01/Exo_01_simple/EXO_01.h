#ifndef EXO_01_H_INCLUDED
#define EXO_01_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
typedef struct
{
    int value;
    struct liste *next;
}liste;

bool empty ( liste *tete);
void create(liste *tete, int *n);
void create_2(liste *tete ,int *n);
void affiche (liste *tete);
liste* add_first(liste *tete);
liste* add_last(liste *tete);
void add_in_pos(liste **tete, int n);
liste* add_with_tri(liste *tete);
int count(liste *tete);
void research(liste *tete);
liste* delete_front (liste *tete);
liste* deldete_back (liste *tete);
liste* delete_number (liste *tete, int val);
liste* clear_list(liste *tete);
#endif // EXO_01_H_INCLUDED
