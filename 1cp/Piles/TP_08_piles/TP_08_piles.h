#ifndef TP_08_PILES_H_INCLUDED
#define TP_08_PILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


typedef struct element
{
    int data;
    struct element *next;
}element;

typedef struct
{
    element *top;
}Stack;



Stack* initpile();
bool empty_stack(Stack *top);
void push (Stack **pile, int v);
void pop (Stack **pile, int *v);
int nbrelements(Stack *pile);
void view(Stack *pile);
void viewreverse(Stack *pile);

#endif // TP_08_PILES_H_INCLUDED
