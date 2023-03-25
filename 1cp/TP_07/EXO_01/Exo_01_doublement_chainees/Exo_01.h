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
    struct liste *back;
}liste;

bool empty(liste *tete);
void create (liste *tete, int *n);
void affiche (liste *tete);
liste* add_first(liste *tete);
liste* add_last(liste *tete);
liste* add_in_pos(liste *tete, int n);
liste* add_with_tri(liste *tete);
int count(liste *tete);
void research(liste *tete);
liste* delete_front(liste *tete);
liste* delete_last(liste *tete);
liste* delete_numbers(liste *tete, int val);
liste* clear_list(liste *tete);
void order_liste (liste *tete);
liste* delete_position(liste *tete, int n);
/*------------------------------------------------------------------*/
#endif // EXO_01_H_INCLUDED
