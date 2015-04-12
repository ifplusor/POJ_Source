#include<stdio.h>
#include<algorithm>

using namespace std;

int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};

struct stick
{
    int len;//木棒长
    int num;//剩余木棒个数
};
bool cmpn(struct stick a,struct stick b)
{
    return a.num>b.num;
}
bool cmpl(struct stick a,struct stick b)
{
    return a.len>b.len;
}

struct stick sticks1[51],sticks[51];

bool dfs(int limit,int value,int leave,int num,int start)
{
    int i;
    if(leave==0)//匹配完一个木棒
    {
        if(num<=2)//全部木棒匹配，最后一个木棒自动匹配
            return true;
        else
            return dfs(limit,value,value,num-1,0);
    }
    if(sticks[limit-1].len>leave)
        return false;
    for(i=start;i<limit;i++)//从大到小进行选择
    {
        if(sticks[i].num>0)
        {
            if(sticks[i].len<=leave)
            {
                sticks[i].num--;
                if(dfs(limit,value,leave-sticks[i].len,num,i))
                    return true;
                sticks[i].num++;
                if(sticks[i].len==leave)//存在恰好匹配木棒则必选，否则才考虑更小的木棒
                    return false;
            }
            if(leave==value)//第一个木棒必选最长的
                return false;
        }
    }
    return false;
}

int main()
{
    int i,j,k,limit,t;
    int sum,num1;
    while(1)
    {
        scanf("%d",&num1);
        if(num1==0)
            break;
        sum=0;
        for(i=0;i<=50;i++)
        {
            sticks1[i].len=i;
            sticks1[i].num=0;
        }
        for(i=0;i<num1;i++)
        {
            scanf("%d",&j);
            sticks1[j].num++;
            sum+=j;
        }
        sort(sticks1,sticks1+51,cmpn);//按数量排序
        for(i=0;i<=51;i++)
            if(sticks1[i].num==0)
                break;
        limit=i;//木棒的种类
        sort(sticks1,sticks1+limit,cmpl);//按长度排序
        for(i=num1;i>1;i--)//原有i个木棍
        {
            if(sum%i!=0)//小棍长度不为整数
                continue;
            if(sum/i<sticks1[0].len)//长度无法容纳最长小棍
                continue;
            t=i;
            for(j=0;j<limit;j++)//提取木棒数据
                sticks[j]=sticks1[j];
            for(k=1;prime[k]<=t;k++)
            {
                if(t%prime[k]!=0)
                    continue;
                for(j=0;j<limit;j++)
                    if(sticks[j].num%prime[k]!=0)
                        break;
                if(j==limit)//以公因子寻找同等类
                {
                    for(j=0;j<limit;j++)
                        sticks[j].num/=prime[k];
                    t/=prime[k];
                    k--;
                }
            }
            if(t==1)
                break;
            if(dfs(limit,sum/i,sum/i,t,0))//匹配成功
                break;
        }
        printf("%d\n",sum/i);
    }
    return 0;
}
