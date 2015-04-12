#include<stdio.h>

#define mnext(x,y,i) moun[x+direct[i][0]][y+direct[i][1]]

const int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct point
{
    int height,len;
    int k,next[4];
};

struct point moun[100][100];

//¼ÇÒä»¯ËÑË÷
int dfs(int x,int y)
{
    int i,l,longest=1;
    if(moun[x][y].len!=0)
        return moun[x][y].len;
    for(i=0;i<moun[x][y].k;i++)
    {
        l=dfs(x+direct[moun[x][y].next[i]][0],y+direct[moun[x][y].next[i]][1]);
        if(longest-l<1)
            longest=l+1;
    }
    moun[x][y].len=longest;
    return longest;
}

int main()
{
    int i,j,R,C,l,longest;
    while(scanf("%d%d",&R,&C)!=EOF)
    {
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                scanf("%d",&moun[i][j].height);
                moun[i][j].len=0;
                moun[i][j].k=0;
            }
        }
        //½¨Í¼
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(i==0)
                {
                    if(j==0)
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                    }
                    else if(j==C-1)
                    {
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                    }
                    else
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                    }
                }
                else if(i==R-1)
                {
                    if(j==0)
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                    else if(j==C-1)
                    {
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                    else
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                }
                else
                {
                    if(j==0)
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                    else if(j==C-1)
                    {
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                    else
                    {
                        if(mnext(i,j,0).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=0;
                        if(mnext(i,j,2).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=2;
                        if(mnext(i,j,1).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=1;
                        if(mnext(i,j,3).height<moun[i][j].height)
                            moun[i][j].next[moun[i][j].k++]=3;
                    }
                }
            }
        }
        longest=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                l=dfs(i,j);
                if(l>longest)
                    longest=l;
            }
        }
        printf("%d\n",longest);
    }
    return 0;
}
