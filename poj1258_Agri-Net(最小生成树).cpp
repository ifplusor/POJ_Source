#include <iostream>

using namespace std;

#define INF 1000000

int graph[100][100];
bool flag[100];
int dist[100];

int prim(int n)
{
    int i,j,least,s,sum=0;
    flag[0]=false;
    for(i=1;i<n;i++)
    {
        flag[i]=true;
        if(graph[0][i]!=0)
        {
            dist[i]=graph[0][i];
        }
        else
        {
            dist[i]=INF;
        }
    }
    for(i=1;i<n;i++)//n-1次操作
    {
        least=INF;
        for(j=1;j<n;j++)//查找全局最小边
        {
            if(flag[j]&&dist[j]<least)
            {
                least=dist[j];
                s=j;
            }
        }
        flag[s]=false;
        sum+=least;
        for(j=1;j<n;j++)//更新最小边
        {
            if(flag[j]&&graph[s][j]!=0&&dist[j]>graph[s][j])//点i未被选出，从s到i有边连通，该边距离更小
                dist[j]=graph[s][j];
        }
    }
    return sum;
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
        cout<<prim(n)<<endl;
    }
    return 0;
}
