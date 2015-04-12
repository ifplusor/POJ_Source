#include <queue>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int MAXN = 201;
const int MAX_INT = 10000005;

int graph[MAXN][MAXN],pre[MAXN],n;

//BFS找增广路
bool EK_BFS(int s,int t)
{
    queue<int> que;
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    memset(pre,-1,sizeof(pre));
    que.push(s);
    flag[s]=true;
    while(!que.empty())
    {
        int e=que.front();
        if(e==t)
            return true;
        que.pop();
        for(int i=1;i<=n;++i)
        {
            if(graph[e][i]&&!flag[i])
            {
                flag[i]=true;
                pre[i]=e;
                que.push(i);
            }
        }
    }
    return false;
}

//EK求最大流
int EK_MAX_FLOW(int s,int t)
{
    int u,flow_ans=0,mn;
    while(EK_BFS(s,t))
    {
        mn=MAX_INT;
        u=t;
        while(pre[u]!=-1)
        {
            mn=min(mn,graph[pre[u]][u]);
            u=pre[u];
        }
        flow_ans+=mn;
        u=t;
        while(pre[u]!=-1)
        {
            graph[pre[u]][u]-=mn;
            graph[u][pre[u]]+=mn;
            u=pre[u];
        }
    }
    return flow_ans;
}

int main()
{
    int m,s,e,c;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        while(m--)
        {
            scanf("%d%d%d",&s,&e,&c);
            graph[s][e]+=c;//包含重边！！！
        }
        printf("%d\n",EK_MAX_FLOW(1,n));
    }
    return 0;
}
