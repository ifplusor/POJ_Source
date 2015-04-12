#include <stdio.h>
#include <memory.h>

bool primef[1000001];
int prime[78500];

int main()
{
    int i,j,n;
    memset(primef,true,sizeof(primef));
    primef[0]=primef[1]=false;
    for(i=2;i<=1000;++i)
    {
        if(!primef[i])
            continue;
        for(j=i+i;j<=1000000;j+=i)
            primef[j]=false;
    }
    for(i=2,j=0;i<=1000000;++i)
    {
        if(primef[i])
        {
            prime[j++]=i;
        }
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<j;i++)
        {
            if(primef[n-prime[i]])
            {
                break;
            }
        }
        printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
    }
    return 0;
}
