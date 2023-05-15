#include "TP_08_files.h"

int main()
{
    int N, occurence;
    char c;
    Queue *file;
    file=initfile();
    if(empty_file(file))
    {
        printf("EMPTY QUEUE!!");
    }
    else
    {
        printf("THE QUEUE IS NOT EMPTY !!");
    }
    do
    {
        printf("\nENTER THE VALUE:");
        scanf("%d", &N);
        push(&file,N);
        printf("\nDO YOU WANT TO CONTINUE : (y/n)");
        c=getche();
    }while((c=='y') || (c=='Y'));
    occurence=nbrelements(file);
    printf("\n%d\n", occurence);
    view(file);
    return 0;
}
