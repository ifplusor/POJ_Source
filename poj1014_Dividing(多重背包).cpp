#include <stdio.h>
#include <memory.h>

int lst[7];

int F[60005],V;
void ZeroOnePack(int C,int W)
{
    for(int v=V;v>=C;--v)
        F[v]=F[v]>F[v-C]+W?F[v]:F[v-C]+W;
}
void CompletePack(int C,int W)
{
    for(int v=C;v<=V;++v)
        F[v]=F[v]>F[v-C]+W?F[v]:F[v-C]+W;
}
void MultiplePack(int C,int W,int M)
{
    if(C*M>=V)
        return CompletePack(C,W);
    int k=1;
    while(k<M)
    {
        ZeroOnePack(k*C,k*W);
        M=M-k;
        k=k+k;
    }
    if(M!=0)
        ZeroOnePack(M*C,M*W);
}

int main()
{
    int i,t;
    int sum;
    for(t=1;1;++t)
    {
        scanf("%d %d %d %d %d %d",lst+1,lst+2,lst+3,lst+4,lst+5,lst+6);
        sum=lst[1]+lst[2]*2+lst[3]*3+lst[4]*4+lst[5]*5+lst[6]*6;//价值和
        if(sum==0)
            break;
        printf("Collection #%d:\n",t);
        if(sum%2)//价值和为奇数，不可分
        {
            printf("Can't be divided.\n\n");
        }
        else
        {
            V=sum/2;//目标价值
            memset(F,0,(V+1)*sizeof(int));
            // 多重背包
            for(i=1;i<=6;++i)
            {
                if(lst[i]!=0)//有弹珠
                {
                    MultiplePack(i,i,lst[i]);//费用与价值合一，固V费用应该得到V的价值
                }
            }
            if(F[V]==V)//V的容量的目标价值为V
                printf("Can be divided.\n\n");
            else
                printf("Can't be divided.\n\n");
        }
    }
    return 0;
}
