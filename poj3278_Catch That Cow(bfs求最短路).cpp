#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct node{
    int k,t;
};

bool flag[100001];

int bfs(int N,int K)
{
    queue<node> que;
    node temp,temp1;
    memset(flag,false,sizeof(flag));
    temp.k=N;
    temp.t=0;
    que.push(temp);
    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        temp1.t=temp.t+1;
        temp1.k=temp.k-1;
        if(temp1.k==K)
            return temp1.t;
        else if(temp1.k>=0&&flag[temp1.k]==false)
        {
            flag[temp1.k]=true;
            que.push(temp1);
        }
        temp1.k=temp.k+1;
        if(temp1.k==K)
            return temp1.t;
        else if(temp1.k<=100000&&flag[temp1.k]==false)
        {
            flag[temp1.k]=true;
            que.push(temp1);
        }
        temp1.k=temp.k*2;
        if(temp1.k==K)
            return temp1.t;
        else if(temp1.k<=100000&&flag[temp1.k]==false)
        {
            flag[temp1.k]=true;
            que.push(temp1);
        }
    }
    return -1;
}

int main()
{
    int N,K;
    while(cin>>N>>K)
    {
        if(N==K)
            cout<<0<<endl;
        else
            cout<<bfs(N,K)<<endl;
    }
    return 0;
}
