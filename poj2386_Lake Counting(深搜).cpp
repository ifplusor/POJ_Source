#include <stdio.h>

char map[102][102];
void dfs(int i,int j)
{
    map[i][j]='.';
    if(map[i-1][j-1]=='W')
        dfs(i-1,j-1);
    if(map[i-1][j]=='W')
        dfs(i-1,j);
    if(map[i-1][j+1]=='W')
        dfs(i-1,j+1);
    if(map[i][j-1]=='W')
        dfs(i,j-1);
    if(map[i][j+1]=='W')
        dfs(i,j+1);
    if(map[i+1][j-1]=='W')
        dfs(i+1,j-1);
    if(map[i+1][j]=='W')
        dfs(i+1,j);
    if(map[i+1][j+1]=='W')
        dfs(i+1,j+1);
}

int main()
{
    int N,M,i,j,n;
    scanf("%d%d",&N,&M);
    for(i=0;i<=M+1;++i)
        map[0][i]=map[N+1][i]='.';
    for(i=1;i<=N;++i)
    {
        scanf("%s",&map[i][1]);
        map[i][0]=map[i][M+1]='.';
    }
    n=0;
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            if(map[i][j]=='W')
            {
                n++;
                dfs(i,j);
            }
    printf("%d\n",n);
    return 0;
}
