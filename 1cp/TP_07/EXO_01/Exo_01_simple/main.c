#include "EXO_01.h"


int main()
{
    int N=0, n, v;

    liste *tete=malloc(sizeof(liste));
    //tete=NULL;
    //create(tete,&N);
    create_2(tete, &N);
    //tete=clear_list(tete);
    affiche(tete);
    //printf("\n%d", N);
    getch();
    //tete=add_with_tri(tete);
    //add_in_pos(&tete,N);
    tete=add_last(tete);
    //tete=clear_list(tete);
    affiche(tete);
    getch();
    //tete=add_first(tete);
    /*affiche(tete);
    getch();
    n=count(tete);
    printf("\nTHERE IS %d ELEMENTS", n);
    research(tete);
    getch();
    tete=delete_front(tete);
    affiche(tete);
    getch();
    tete=deldete_back (tete);
    affiche(tete);
    //printf("\nENTER THE VALUE THAT YOU WANT TO DELETE IT :");
    //scanf("%d", &v);
    //tete=delete_number(tete,v);
    affiche(tete);*/
    return 0;
}
