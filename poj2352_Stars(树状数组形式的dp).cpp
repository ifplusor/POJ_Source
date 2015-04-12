#include <stdio.h>
#include <memory.h>

int level[15000];
int dp[32002];//数据的区间范围为[0,32000]，而树状数组的的范围是从1开始的

#define lowbit(t) (t&(-t))
#define N 32001

int sum(int *C,int e)
{
    int sum = 0;
    while(e > 0)
    {
        sum += C[e];
        e -= lowbit(e);
    }
    return sum;
}

void add(int *C,int pos, int num)
{
    while(pos <= N)
    {
        C[pos] += num;
        pos += lowbit(pos);
    }
}

int main()
{
    int n,i,temp;
    int x,y;
    memset(level,0,sizeof(level));
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d %d",&x,&y);
        x++;//故对x加1进行坐标调整
        temp=sum(dp,x);
        level[temp]++;
        add(dp,x,1);
    }
    for(i=0;i<n;++i)
        printf("%d\n",level[i]);
    return 0;
}
