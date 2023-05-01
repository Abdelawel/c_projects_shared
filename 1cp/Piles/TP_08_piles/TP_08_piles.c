#include "TP_08_piles.h"

Stack* initpile()
{
    Stack *pile=malloc(sizeof(*pile));
    pile->top=NULL;
    return pile;
}

//---------------------------------------------------------------//


bool empty_stack(Stack *top)
{
    if (top->top==NULL)
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------//

void push(Stack **pile, int v)
{
    element *p=malloc(sizeof(element));
    p->data=v;
    p->next=(*pile)->top;
    (*pile)->top=p;

}

//---------------------------------------------------------------//

void pop (Stack **pile, int *v)
{
    if(empty_stack(*pile))
    {
        printf(" EMPTY STACK");

    }
    else
    {
        element *p=(*pile)->top;
        *v=p->data;
        (*pile)->top=(*pile)->top->next;
        free(p);
    }

}

//---------------------------------------------------------------//

void view(Stack *pile)
{
    int N;
    Stack *P=initpile();
    while(!empty_stack(pile))
    {
        pop(&pile,&N);
        printf("[%d]\n", N);
        push(&P,N);
    }
    while(!empty_stack(P))
    {
        pop(&P,&N);
        push(&pile,N);
    }
}

//---------------------------------------------------------------//

int nbrelements(Stack *pile)
{
    int i=0, N;
    Stack *P=initpile();
    while(!empty_stack(pile))
    {
        pop(&pile,&N);
        push(&P,N);
        i++;
    }
    while(!empty_stack(P))
    {
        pop(&P,&N);
        push(&pile,N);
    }
    return i;
}

//---------------------------------------------------------------//

void viewreverse(Stack *pile)
{
    int N;
    Stack *P=initpile();
    while(!empty_stack(pile))
    {
        pop(&pile,&N);
        push(&P,N);
    }
    while(!empty_stack(P))
    {
        pop(&P,&N);
        printf("[%d]\n", N);
        push(&pile,N);
    }
}
