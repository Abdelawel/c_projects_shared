#include "Recursivite.h"
int sum (int N)
{

    if (N<=1)
    {
        return 1;
    }
    else
    {
        return N+sum(N-1);
    }
}

//--------------------------------------------------//

int puissance (int x, int N)
{
    if (N==0)
        return 1;
    return x*puissance(x, N-1);
}

//--------------------------------------------------//

int pgcd (int a, int b)
{
    int tmp;
    if (b==0)
    {
        return a;
    }


    if((a==0) || (a%b==0))
    {
        return b;
    }
    else
    {
        return pgcd(b, a%b);
    }
}

//--------------------------------------------------//

void croissant (int N)
{
    if (N==1)
    {
        printf("%d  ",N);
        return ;
    }
    else
    {
        croissant(N-1);
        printf("%d  ", N);
    }
}

//--------------------------------------------------//

void decroissant (int N)
{
    if (N==1)
    {
        printf("%d  ",N);
        return ;
    }
    else
    {
        printf("%d  ", N);
        decroissant(N-1);

    }
}

//--------------------------------------------------//

int decimaltobinaire (int N)
{
    if(N/2==0)
    {
        return 1;
    }
    else
    {
        return decimaltobinaire(N/2)*10 + N%2;
    }
    /*
    if(n!=0)
        return(decimaltobinare(n/2));
        printf("%d", N%2);
    */
}

//--------------------------------------------------//

void view (int T[5], int n)
{
    if(n!=0)
    {
        view(T,n-1);
        printf("%d", T[n-1]);
    }
}

//--------------------------------------------------//

int sum1(int T[5], int n)
{
    int s=0;
    if (n==0)
    {
        s=0;
    }
    else
    {
        s=T[n-1];
        return s+sum1(T, n-1);
    }
    return s;
}

//--------------------------------------------------//

bool palindrome (char c[], int i, int l)
{
    if (i<=l)
    {
        if (c[i]==c[l])
        {
            return palindrome(c, i+1, l-1);
        }
        else
        {
            return false;
        }
    }
    return true;
}
