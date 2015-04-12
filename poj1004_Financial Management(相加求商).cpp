#include <stdio.h>


double dollar[12]={0};

int main()
{
    int i;
    double sum=0;
    for(i=0;i<12;i++)
    {
        scanf("%lf",dollar+i);
        sum+=dollar[i];

    }
    printf("$%.2lf\n",sum/12);

    return 0;
}
