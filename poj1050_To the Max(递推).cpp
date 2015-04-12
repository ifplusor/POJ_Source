#include <stdio.h>
#include <memory.h>

int sumx[101][101][101];//x,y,dx
int sumy[101][101][101];//x,y,dy

int main()
{
    int n,x,y,dx,dy,lx,ly,large;
    while(scanf("%d",&n)!=EOF)
    {
        large=-200;
        memset(sumx,0,sizeof(sumx));
        memset(sumy,0,sizeof(sumy));
        for(y=1;y<=n;++y)
        {
            for(x=1;x<=n;++x)
            {
                scanf("%d",&sumx[x][y][1]);
                if(large<sumx[x][y][1])
                    large=sumx[x][y][1];
            }
        }
        //dy=1时推导sum[x,y,dx,1]的值，保存在sumx中  sum[x,y,dx,1]=sum[x,y,dx-1,1]+sum[x+dx-1,y,1,1]
        for(y=1;y<=n;++y)
        {
            for(x=1;x<=n;++x)
            {
                lx=n-x+1;
                for(dx=2;dx<=lx;++dx)
                {
                    sumx[x][y][dx]=sumx[x][y][dx-1]+sumx[x+dx-1][y][1];
                    if(large<sumx[x][y][dx])
                        large=sumx[x][y][dx];
                }
            }
        }
        //推导sum[x,y,dx,dy]的值  sum[x,y,dx,dy]=sum[x,y,dx,dy-1]+sum[x,y+dy-1,dx,1]
        for(y=1;y<=n;++y)
        {
            for(x=1;x<=n;++x)
            {
                lx=n-x+1;
                for(dx=1;dx<=lx;++dx)
                {
                    sumy[x][y][1]=sumx[x][y][dx];
                    ly=n-y+1;
                    for(dy=2;dy<=ly;++dy)
                    {
                        sumy[x][y][dy]=sumy[x][y][dy-1]+sumx[x][y+dy-1][dx];
                        if(large<sumy[x][y][dy])
                            large=sumy[x][y][dy];
                    }
                }
            }
        }
        printf("%d\n",large);
    }
    return 0;
}
