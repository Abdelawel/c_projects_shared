#ifndef TP_08_FILES_H_INCLUDED
#define TP_08_FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct element
{
    int data;
    struct element *next;
}element;

typedef struct
{
    element *tete;
    element *Q;
}Queue;

Queue* initfile();
bool empty_file(Queue *file);
void push(Queue **file, int N);
void pop(Queue **file, int *N);
int nbrelements(Queue *file);
void view(Queue *file);
#endif // TP_08_FILES_H_INCLUDED
