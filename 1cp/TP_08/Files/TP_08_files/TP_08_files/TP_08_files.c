#include "TP_08_files.h"

Queue* initfile()
{
    Queue *file=malloc(sizeof(*file));
    file->tete=NULL;
    file->Q=NULL;
    return file;
}

//-------------------------------------------------------//

bool empty_file(Queue *file)
{
    if((file->tete)==NULL)
    {
        return true;
    }
    return false;
}

//-------------------------------------------------------//

void push(Queue **file, int N)
{
    element *f=malloc(sizeof(element));
    f->data=N;
    f->next=NULL;
    if(empty_file(*file))
    {
        (*file)->tete=f;
    }
    else
    {
        (*file)->Q->next=f;
    }
    (*file)->Q=f;
}

//-------------------------------------------------------//

void pop(Queue **file, int *N)
{
    element *f;
    if(empty_file(*file))
    {
        printf("QUEUE IS EMPTY !!");
        return 0;
    }
    else
    {
        f=(*file)->tete;
        *N=f->data;
        (*file)->tete=(*file)->tete->next;
        free(f);
    }
}

//-------------------------------------------------------//

int nbrelements(Queue *file)
{
    int i=0, N;
    Queue *f=initfile();
    while(!empty_file(file))
    {
        pop(&file,&N);
        push(&f,N);
        i++;
    }
    while(!empty_file(f))
    {
        pop(&f,&N);
        push(&file,N);
    }
    return i;
}

//-------------------------------------------------------//

void view(Queue *file)
{
    int N;
    Queue *f=initfile();
    while(!empty_file(file))
    {
        pop(&file,&N);
        printf("[%d]--", N);
        push(&f,N);
    }
    while(!empty_file(f))
    {
        pop(&f,&N);
        push(&file,N);
    }
}
