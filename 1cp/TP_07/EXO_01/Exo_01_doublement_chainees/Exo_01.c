#include "Exo_01.h"

bool empty( liste *tete)
{
    if (tete==NULL)
    {
        return true;
    }
    return false;
}

/*------------------------------------------------------------------*/

void create (liste *tete, int *n)
{
    liste *p=malloc(sizeof(liste)),
        *tmp=malloc(sizeof(liste));
    p=tete;
    p->back=NULL;
    char c=' ';
    do
    {
        *n=*n+1;
        printf("\nENTER THE VALUE :");
        scanf("%d", &p->value);
        printf("DO YOU WANT MORE : (y/n)");
        c=getche();
        if(c=='y' || c== 'Y')
        {
            tmp=p;
            p->next=malloc(sizeof(liste));
            p=p->next;
            p->back=tmp;
        }
        else
        {
            p->next=NULL;
        }
    }while(c=='y' || c=='Y');
}

/*------------------------------------------------------------------*/

void affiche (liste *tete)
{
    bool T= empty(tete);
    liste *p=malloc(sizeof(liste));
    p=tete;
    if (T==true)
    {
        printf("\nLIST IS EMPTY !!");
        return;
    }
    else
    {
        printf("\nTHE VALUES ARE :\n");
        while(p!=NULL)
        {
            printf("   %d", p->value);
            p=p->next;
        }
    }
    printf("\n\nTAPE ANY KEY TO CONTINUE ...\n\n");
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
        p->back=NULL;
    }
    else
    {
        p->next=tete;
        tete->back=p;
        p->back=NULL;
    }
    return p;
}

/*------------------------------------------------------------------*/

liste* add_last(liste *tete)
{
    liste *p=malloc(sizeof(liste)),
          *tmp=malloc(sizeof(liste));
    printf("\nENTER THE ADDED VALUE IN THE LAST POSITION:");
    scanf("%d", &p->value);
    p->next=NULL;
    if(empty(tete))
    {
        return p;
    }
    else
    {
        tmp=tete;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=p;
        p->back=tmp;
    }
    return tete;
}

/*------------------------------------------------------------------*/

liste* add_in_pos(liste *tete, int n)
{
    int k=1, i;
    liste *p=malloc(sizeof(liste)),
        *tmp=malloc(sizeof(liste)),
        *current=malloc(sizeof(liste));
        tmp=tete;
    printf("\nENTER THE VALUE THAT YOU WANT TO ADD IT:");
    scanf("%d", &p->value);
    do
    {
        if(k>n+1 || k<1)
        {
            printf("INCORRECT PLACE, TRY CHOOSE BITWEEN 1 AND %d" , n+1);
        }
        printf("\nITS POSITIONS IS :");
        scanf(" %d", &k);
    }while (k>n+1 || k<1);
    if(k==1)
    {
        p->next=tmp;
        p->back=NULL;
        tete=p;
    }
    else
    {
        i=2;
        tmp=tete;
        while(tmp!=NULL)
        {
            if(i==k)
            {
                p->next=tmp->next;
                p->back=tmp;
                tmp->next=p;
                if(p->next!=NULL)
                {
                    tmp=p->next;
                    tmp->back=p;
                }
                break;
            }
            else
            {
                tmp=tmp->next;
                i++;
            }
        }
    }
    return tete;
}

/*------------------------------------------------------------------*/

liste* add_with_tri(liste *tete)
{
    liste *p=malloc(sizeof(liste));
    liste *current=malloc(sizeof(liste));
    liste *previous=malloc(sizeof(liste));
    previous=tete;
    current=tete->next;
    printf("\nNOW THE LIST IS ORDED !!...ENTER THE VALUE THAT YOU WANT TO ADD IT:");
    scanf("%d", &p->value);
    if(p->value<=previous->value)
    {
        p->next=previous;
        previous->back=p;
        p->back=NULL;
        tete=p;
        return tete;
    }
     while(current!=NULL)
    {
        if(p->value<=current->value)
        {
            p->next=current;
            current->back=p;
            previous->next=p;
            p->back=previous;
            return tete;
        }
            previous=current;
            current=current->next;
    }
    if(p->value>previous->value)
    {
        p->next=NULL;
        p->back=previous;
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
    bool N=false;
    liste *p=tete;
    printf("\nENTER THE VALUE THAT YOU'RE SEARCHING :");
    scanf("%d", &V);
    while(p!=NULL)
    {
        if(p->value==V)
        {
            if(N==false)
            {
                printf("\n %d EXIST !! THE POSITIONS ARE: %d TH", V, i);
                N=true;
            }
            else
            {
                printf("  %dTH", i);
            }
        }
        i++;
        p=p->next;
    }
    if(N==false)
    {
        printf("\n %d DOESN'T EXIST !!", V);
    }

}

/*------------------------------------------------------------------*/

liste* delete_front(liste *tete)
{
    liste *p=tete,
    *tmp;
    if(p->next==NULL)
    {
        free(p);
        return NULL;
    }
    tmp=p->next;
    tmp->back=NULL;
    tete=tmp;
    free(p);
    return tmp;
}

/*------------------------------------------------------------------*/

liste* delete_last(liste *tete)
{
    liste *p=tete, *tmp;
    if(p->next==NULL)
    {
        free(p);
        return NULL;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    tmp=p->back;
    tmp->next=NULL;
    free(p);
    return tete;
}

/*------------------------------------------------------------------*/

liste* delete_numbers(liste *tete, int val)
{
    liste *p=tete, *previous, *tmp;
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
        p->back=NULL;
        previous=p;
        while(p!=NULL)
        {
            if(p->value==val)
            {
                previous->next=p->next;
                if(previous->next!=NULL)
                {
                    tmp=p->next;
                    tmp->back=previous;
                }

                free(p);
                p=previous;
            }
            previous=p;
            p=p->next;
        }

    return tete;
}

/*------------------------------------------------------------------*/

liste* delete_position(liste *tete, int n)
{
    liste *p=tete->next, *previous=tete, *tmp;
    int i=2;
    if(n==1)
    {
        tete=delete_front(tete);
        return tete;
    }
    else
    {

        while(p!=NULL)
        {
            if(i==n)
            {
                previous->next=p->next;
                if(previous->next!=NULL)
                {
                    tmp=p->next;
                    tmp->back=previous;
                }
                free(p);
                break;
            }
            else
            {
                i++;
                previous=p;
                p=p->next;
            }

        }
    return tete;
    }

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

/*------------------------------------------------------------------*/

void order_liste (liste *tete)
{
    int tmp;
    liste *p=tete;
    liste *move=malloc(sizeof(liste));
    while(p!=NULL)
    {
        move=p->next;
        while(move!=NULL)
        {
            if(p->value>move->value)
            {
                tmp=p->value;
                p->value=move->value;
                move->value=tmp;
            }
            move=move->next;
        }
        p=p->next;

    }
}
