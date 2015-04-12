#include <stdio.h>


double temp[300]={0};

int main()
{
    int i;
    double t;
    //递推造表
    temp[0]=0;
    for(i=1;i<280;i++)
    {
        temp[i]=temp[i-1]+1.0/(i+1);
    }
    while(1)
    {
        scanf("%lf",&t);
        if(t==0)
            break;
        for(i=1;t>temp[i];i++);//查表
        printf("%d card(s)\n",i);
    }
    return 0;
}
