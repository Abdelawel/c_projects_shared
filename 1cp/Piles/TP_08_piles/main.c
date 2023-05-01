#include "TP_08_piles.h"

int main()
{
    int N, occurence;
    char c;
    Stack *pile;
    pile=initpile();
    if(empty_stack(pile))
    {
        printf("EMPTY STACK !!");
    }
    else
    {
        printf("THE STACK IS NOT EMPTY !!");
    }
    do
    {
        printf("\nENTER THE VALUE:");
        scanf("%d", &N);
        push(&pile,N);
        printf("\nDO YOU WANT TO CONTINUE : (y/n)");
        c=getche();
    }while((c=='y') || (c=='Y'));
    /*push(&pile, 5);
    push(&pile, 4);
    push(&pile, 3);
    push(&pile, 6);*/
    occurence=nbrelements(pile);
    printf("\n%d\n", occurence);
    view(pile);
    printf("HERE'S THE STACK GET REVERSED:\n");
    viewreverse(pile);
   /*pop(&pile,&N);
    printf("\n%d", N);
    pop(&pile,&N);
    printf("\n%d", N);
    pop(&pile,&N);
    printf("\n%d", N);*/
    return 0;
}
