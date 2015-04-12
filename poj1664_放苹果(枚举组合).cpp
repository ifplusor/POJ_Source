#include <stdio.h>

int solve(int m,int n,int k)
{
    int i,num=0;
    if(m<k)
        return 0;
    if(n==1)
        return 1;
    for(i=k;i<=m;i++)
        num+=solve(m-i,n-1,i);
    return num;
}

int main()
{
    int i,n,M,N;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&M,&N);
        printf("%d\n",solve(M,N,0));
    }
    return 0;
}
