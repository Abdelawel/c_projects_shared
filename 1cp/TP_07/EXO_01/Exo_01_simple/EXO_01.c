#include "EXO_01.h"




bool empty ( liste *tete)
{
    if (tete==NULL)
    {
        return true;
    }
    return false;
}

/*------------------------------------------------------------------*/

void create(liste *tete, int *n)
{
    *n=0;
    char c =' ';
    liste *p = malloc(sizeof(liste));
    p=tete;
    do
    {
        *n=*n+1;
        printf("\nENTER THE VALUE :");
        scanf("%d", &p->value);
        printf("DO YOU WANT MORE :");
        c=getche();
        if(c=='y' || c== 'Y')
        {
            p->next=malloc(sizeof(liste));
            p=p->next;
        }
        else
        {
            p->next=NULL;
        }
    }while(c=='y' || c=='Y');
}

/*------------------------------------------------------------------*/

void create_2(liste *tete ,int *n)
{
    liste *p=malloc(sizeof(liste));
    int nbr, i;
    p=tete;
    printf("HOW MUCH DO YOU WANT TO MAKE ELEMENTS :");
    scanf("%d", &nbr);
    *n=nbr;
    printf("ENTER THE 1ST VALUE :");
    scanf("%d", &p->value);
    if(nbr==1)
    {
        p->next=NULL;
    }
    else
    {
        for(i=1;i<nbr;i++)
        {
            p->next=malloc(sizeof(liste));
            p=p->next;
            printf("ENTER THE %dTH VALUE :", i+1);
            scanf("%d", &p->value);
        }
        p->next=NULL;
    }

}

/*------------------------------------------------------------------*/

void affiche (liste *tete)
{
    bool T=empty(tete);
    if (T==true)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    else
    {
        printf("\nTHE VALUES ARE :\n");                 //here it doesn't mean the real head... just a pointer
        while(tete!=NULL)                               //for(p=tete;p==NULL;p=p->next)
        {                                               //{
            printf("   %d", tete->value);               // printf("   %d", tete->value);
            tete=tete->next;                            //}
        }
    }

}

/*------------------------------------------------------------------*/

liste* add_first(liste *tete)
{
    liste *p=malloc(sizeof(liste));
    printf("\nENTER THE ADDED VALUE IN THE FIRST POSITION:");  //p->value=N;
    scanf("%d", &p->value);
    if(empty(tete))
    {
        p->next=NULL;
    }
    else
    {
        p->next=tete;
    }

    return p;
}

/*------------------------------------------------------------------*/

liste* add_last(liste *tete)
{
    liste *p=malloc(sizeof(liste)),
          *tmp;
    printf("\nENTER THE ADDED VALUE IN THE LAST POSITION:");
    scanf("%d", &p->value);
    p->next=NULL;
    if (tete==NULL)
    {
        return p;
    }
    else
    {
        tmp=tete;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=p;
        p->next=NULL;

    }
    return tete;
}

/*------------------------------------------------------------------*/

void add_in_pos(liste **tete, int n)
{
    int i=0, k=1;
    liste *p=malloc(sizeof(liste)),
          *tmp=malloc(sizeof(liste));
          tmp=(*tete);
    printf("\nENTER THE VALUE THAT YOU WANT TO ADD IT:");
    scanf("%d", &p->value);
    do
    {
        if(k>n+1 || k<1)
        {
            printf("INCORRECT PLACE, TRY CHOOSE BITWEEN 1 AND %d" , n);
        }
        printf("\nITS POSITIONS IS :");
        scanf(" %d", &k);
    }while (k>n+1 || k<1);

    if (k==1)
    {
        p->next=(*tete);
        (*tete)=p;
    }
    else
    {
        i=2;
        tmp=(*tete);
        while(tmp!=NULL)
        {
            if(i==k)
            {
                p->next=tmp->next;
                tmp->next=p;
                break;
            }
            else
            {
                tmp=tmp->next;
                i++;
            }
        }
    }
}

/*------------------------------------------------------------------*/

liste* add_with_tri(liste *tete)
{
    liste *p=malloc(sizeof(liste));
    liste *current=malloc(sizeof(liste));
    liste *previous=malloc(sizeof(liste));
    previous=tete;
    current=tete->next;
    printf("\nENTER THE VALUE THAT YOU WANT TO ADD IT:");
    scanf("%d", &p->value);
    if(p->value<=previous->value)
    {
        p->next=previous;
        tete=p;
        return tete;
    }
    while(current!=NULL)
    {
        if(p->value<=current->value)
        {
            p->next=current;
            previous->next=p;
            return tete;
        }
            previous=current;
            current=current->next;
    }
    if(p->value>previous->value)
    {
        p->next=NULL;
        previous->next=p;
    }

    return tete;
}

/*------------------------------------------------------------------*/

int count(liste *tete)
{
    int N;
    while(tete!=NULL)
    {
        tete=tete->next;
        N++;
    }
    return N;
}

/*------------------------------------------------------------------*/

void research(liste *tete)
{
    int V, i=1;
    liste *p=tete;
    printf("\nENTER THE VALUE THAT YOU'RE SEARCHING :");
    scanf("%d", &V);
    while(p!=NULL)
    {
        if(p->value==V)
        {
            printf("\n %d EXIST !! IN THE %d TH POSITION", V, i);
            return;
        }
        i++;
        p=p->next;
    }
    printf("\n %d DOESN'T EXIST !!", V);
}

/*------------------------------------------------------------------*/

liste* delete_front (liste *tete)
{
    if(tete!=NULL)
    {
    liste *p=tete;
    tete=p->next;
    free(p);
    }
    return tete;
}

/*------------------------------------------------------------------*/

liste* deldete_back (liste *tete)
{
    liste *previous=tete;
    liste *p=tete;
    if(p->next==NULL)
    {
        free(p);
        tete=NULL;
        return tete;
    }
    else
    {
            while(p->next!=NULL)
        {
            previous=p;
            p=p->next;
        }
    }

    previous->next=NULL;
    free(p);
    return tete;
}

/*------------------------------------------------------------------*/

liste* delete_number (liste *tete, int val)
{
    liste *p=tete;
    liste *previous;
    while(tete->value==val)
    {
        p=p->next;
        free(tete);
        tete=p;
        if(tete==NULL)
        {
            return tete;
        }
    }
        previous=p;
        while(p!=NULL)
        {
            if(p->value==val)
            {
                previous->next=p->next;
                free(p);
                p=previous;
            }
            previous=p;
            p=p->next;
        }


    return tete;
}

/*------------------------------------------------------------------*/

liste* clear_list(liste *tete)
{
    liste *p;
    while(tete!=NULL)
    {
        p=tete;
        tete=tete->next;
        free(p);
    }
    return NULL;
}




