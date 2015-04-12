#include <stdio.h>
#include <memory.h>

int original[1005];
int sum[1005];

int main()
{
    int N,m;
    scanf("%d",&N);
    original[0]=-1;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=N;++i)
    {
        scanf("%d",original+i);
        for(int j=0;j<i;++j)
        {
            if(original[i]>original[j] && sum[i]<(sum[j]+1))
                sum[i]=sum[j]+1;
        }
    }
    m=0;
    for(int i=1;i<=N;i++)//从所有sum中选出最大值，略坑
    {
        if(m<sum[i])
            m=sum[i];
    }
    printf("%d\n",m);
    return 0;
}
