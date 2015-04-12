#include <stdio.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}

//两只蚂蚁相遇后，当他们保持原样交错而过继续前进对结果无影响
int main()
{
    int N,len,n,d,t;
    int maxT,minT;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&len,&n);
        maxT=0;
        minT=0;
        while(n--)
        {
            scanf("%d",&d);
            t=len-d;
            minT=max(minT,min(d,t));
            maxT=max(maxT,max(d,t));
        }
        printf("%d %d\n",minT,maxT);
    }
    return 0;
}
