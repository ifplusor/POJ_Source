#include <stdio.h>

const int MAXN = 105;

int triangle[MAXN][MAXN];
int num[MAXN][MAXN];

//递推求解每个终点的最大值，深搜枚举路径也可以求解，但会超时
int deal(int n)
{
    int i,j,biggest=0;
    num[1][1]=triangle[1][1];
    for(i=2;i<=n;i++)
    {
        num[i][1]=num[i-1][1]+triangle[i][1];
        for(j=2;j<=i;j++)
        {
            num[i][j]=num[i-1][j-1];
            if(num[i-1][j]>num[i][j])
                num[i][j]=num[i-1][j];
            num[i][j]+=triangle[i][j];
        }
    }
    for(i=1;i<=n;i++)//从全部终点最大值中选出最优解
    {
        if(num[n][i]>biggest)
            biggest=num[n][i];
    }
    return biggest;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&triangle[i][j]);
            }
        }
        printf("%d\n",deal(n));
    }
    return 0;
}
