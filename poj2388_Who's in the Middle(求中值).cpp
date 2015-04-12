#include <stdio.h>
#include <algorithm>

using namespace std;

int lst[10005];

bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
            scanf("%d",lst+i);
        sort(lst,lst+N,cmp);
        printf("%d\n",lst[(N-1)/2]);
    }
    return 0;
}
