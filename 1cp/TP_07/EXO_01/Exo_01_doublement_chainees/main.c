#include "Exo_01.h"
int main()
{
    int N, v, n, p=1;
    liste *tete=malloc(sizeof(liste));

    create(tete, &N);
    affiche(tete);
    getch();

    tete=add_first(tete);
    affiche(tete);
    getch();

    tete=add_last(tete);
    affiche(tete);
    getch();

    N=count(tete);
    tete=add_in_pos(tete,N);
    affiche(tete);
    getch();

    printf("\n\n--------HERE IS THE LIST ORDERED :--------\n\n");
    order_liste(tete);
    affiche(tete);
    getch();

    tete=add_with_tri(tete);
    affiche(tete);
    getch();

    tete=delete_front(tete);
    printf("\n\n------HERE IS THE FIRST ELEMENTS GETS DELETED ------\n");
    affiche(tete);
    getch();

    tete=delete_last(tete);
    printf("\n\n------HERE IS THE LAST ELEMENTS GETS DELETED ------\n");
    affiche(tete);
    getch();

    printf("\nENTER THE VALUE THAT YOU WANT TO DELETE IT :");
    scanf("%d", &v);
    tete=delete_numbers(tete, v);
    affiche(tete);
    getch();

    N=count(tete);
    do
    {
        if(p<=0 || p>N)
        {
            printf("INCORRECT PLACE, TRY CHOOSE BITWEEN 1 AND %d" , N);
        }
        printf("\nENTER VALUE'S POSITION THAT YOU WANT TO DELETE IT :");
        scanf("%d", &p);
    }while(p<=0 || p>N);
    tete=delete_position(tete, p);
    affiche(tete);
    getch();


    n=count(tete);
    printf("\n\nTHERE'S %d ELEMENTS\n", n);

    research(tete);

    tete=clear_list(tete);
    affiche(tete);
    getch();
    return 0;
}
