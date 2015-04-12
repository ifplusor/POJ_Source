#include<stdio.h>

#define lowbit(t) (t&(-t))

__int64 sum(__int64 *C,int e)
{
    __int64 sum = 0;
    while(e > 0)
    {
        sum += C[e];
        e -= lowbit(e);
    }
    return sum;
}

int N;
void add(__int64 *C,int pos, __int64 num)
{
    while(pos <= N)
    {
        C[pos] += num;
        pos += lowbit(pos);
    }
}

__int64 C[100005];//静态前缀和
__int64 D[100005];//动态增量
__int64 DI[100005];//D[i]*i

int main()
{
    int i,s,e;
    int Q;
    __int64 num1,k,ans;
    char O;
    while(scanf("%d%d",&N,&Q)!=EOF)
    {
        for(i=0;i<=N;i++)
            DI[i]=D[i]=0;
        C[0]=0;
        for(i=1;i<=N;i++)
        {
            scanf("%I64d",&num1);
            C[i]=C[i-1]+num1;
        }
        for(i=0;i<Q;i++)
        {
            getchar();
            scanf("%c %d %d",&O,&s,&e);
            {
                if(O=='Q')
                {
                    ans=C[e]+(e+1)*sum(D,e)-sum(DI,e);//sum[x]=segma(A,1..x)+(x*1)segma(D,1...x)-segma(DI,1...x) ,DI[i]=D[i]*i
                    ans=ans-(C[s-1]+s*sum(D,s-1)-sum(DI,s-1));
                    printf("%I64d\n",ans);
                }
                else
                {
                    scanf("%I64d",&k);
                    add(D,s,k);
                    add(D,e+1,-k);
                    add(DI,s,k*s);
                    add(DI,e+1,-(k*(e+1)));
                }
            }
        }
    }
    return 0;
}
