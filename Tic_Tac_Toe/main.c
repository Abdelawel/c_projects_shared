#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

char T[9];

void Table()
{
    int i;
    printf("\n");
    printf("\t %c | %c | %c\n", T[0], T[1], T[2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n", T[3], T[4], T[5]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n", T[6], T[7], T[8]);

}
void player1(char name[99])
{
    char mark='X';
    int p;
    back:
    printf("%s...Your position is :", name);
    scanf(" %d", &p);
    if (p<=0 || p>9)
    {
        printf("THE POSITIONS ARE BETWEEN 1 AND 9 \n");
        goto back;
    }
    else
    {
            if(T[p-1]!=' ')
        {
            printf("THIS PLACE HAS BEEN TAKEN!!\n");
            goto back;
        }
        else
        {
            T[p-1]=mark;
        }
    }

}
void player2(char name[99])
{
    char mark='O';
    int p;
    back:
    printf("%s...Your position is :", name);
    scanf(" %d", &p);
    if (p<=0 || p>9)
    {
        printf("THE POSITIONS ARE BETWEEN 1 AND 9 \n");
        goto back;
    }
    else
    {
        if(T[p-1]!=' ')
        {
            printf("THIS PLACE HAS BEEN TAKEN!!\n");
            goto back;
        }
        else
        {
            T[p-1]=mark;
        }

    }

}
int space()
{
    int b=9;
    int i;
    for(i=0;i<9;i++)
    {
        if (T[i]!=' ')
        {
            b--;
        }
    }
    return b;
}
char win()
{
    int i;

    if((T[0]==T[1]) && (T[0]==T[2]))
    {
        return T[0];
    }
    if((T[3]==T[4]) && (T[3]==T[5]))
    {
        return T[3];
    }
    if((T[6]==T[7]) && (T[6]==T[8]))
    {
        return T[6];
    }
    if((T[0]==T[3]) && (T[0]==T[6]))
    {
        return T[0];
    }
    if((T[1]==T[4]) && (T[1]==T[7]))
    {
        return T[1];
    }
    if((T[2]==T[5]) && (T[2]==T[8]))
    {
        return T[2];
    }

    if((T[0]==T[4]) && (T[0]==T[8]))
    {
        return T[0];
    }
    if((T[2]==T[4]) && (T[2]==T[6]))
    {
        return T[2];
    }

    return ' ';

}
void freespace()
{
    int i;
    for(i=0;i<9;i++)
    {
        T[i]=' ';
    }
}
int main()
{
    char p1[99];
    char p2[99];
    char r;
    printf("PLAYER ONE'S NAME:");
    scanf("%s", &p1);
    printf("PLAYER TWO'S NAME:");
    scanf("%s", &p2);
    do
    {
    system("cls");
    char winner=' ';
    freespace();
    while((winner == ' ') && (space()!=0))


    {
        Table();
        player1(p1);
        winner=win();
        if(winner!= ' ' || space() == 0)
        {
            break;
        }
        system("cls");
        Table();
        player2(p2);
        winner=win();
        if(winner!= ' ' || space() == 0)
        {
            break;
        }
        system("cls");
    }
    system("cls");
    Table();
    if(winner == 'X')
    {
        printf("THE WINNER IS: %s", p1);
    }
    else
    {
        if(winner == 'O')
        {
            printf("THE WINNER IS: %s", p2);
        }
        else
        {
            printf("IT'S A DRAW!!");
        }
    }
    printf("\n\n TRY AGAIN (y/n) :)?");
    r=getche();
    }while((r=='y')||(r=='Y'));



    return 0;
}
