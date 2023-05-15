#include "Recursivite.h"

int main()
{
    int p, v, n, l;
    int T[]={1,2,3,4,5};
    char c[22];
    scanf("%d", &p);
    v=sum(p);
    printf("THe SUM IS:%d\n", v);
    scanf("%d", &n);
    v=puissance(p,n);
    printf("PUISSNACE IS:%d\n", v);

    v=pgcd(p,n);
    printf("PGCD: %d\n", v);

    printf("ENTER A VALUE :");
    scanf("%d", &p);
    croissant(p);
    printf("\n");
    decroissant(p);
    printf("\n");
    v=decimaltobinaire(p);
    printf("binary:%d\n", v);
    printf("\n");
    view(T,5);
    v=sum1(T, 5);
    printf("\n%d\n", v);
    printf("enter the string:");
    scanf("%s", &c);
    l=strlen(c)-1;
    if(palindrome(c,0,l))
    {
        printf("\nthe string is palindrome\n");
    }
    else
    {
        printf("the string is not palindrome");
    }
    return 0;
}
