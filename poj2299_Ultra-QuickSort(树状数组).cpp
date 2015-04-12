#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define lowbit(t) (t&(-t))

struct type{
    int num,index;
}num[500005];

int N,C[500005];//保存可移动数据前缀次数的树状数组

bool cmp(struct type a,struct type b)
{
    return a.num<b.num;
}

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

//求升序冒泡排序的相邻数据交换次数，向低下标冒泡，按升序累加处理数据前向具有的未处理数据个数
int main()
{
    __int64 solve;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
            break;
        memset(C,0,(N+1)*sizeof(int));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&num[i-1].num);//获得数据
            num[i-1].index=i;//记录下标编号
            add(C,i,1);//初始化树状数组
        }
        add(C,1,-1);//树状数组数据处理
        sort(num,num+N,cmp);//排序
        solve=0;
        for(int i=0;i<N;i++)
        {
            solve+=sum(C,num[i].index);//累加移动次数
            add(C,num[i].index,-1);//取消已处理数据的标记
        }
        printf("%I64d\n",solve);
    }
    return 0;
}
