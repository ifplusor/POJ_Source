#include <stdio.h>

int poster[10001][2];//离线区间信息
int wall[10000001];//记录点所在位置向后下一处空白（链式），通过链式结构使全域内每一点只被处理一次

int main()
{
    int c,n,i,j,temp,sum;
    scanf("%d",&c);
    while(c--)
    {
        for(i=0;i<=10000000;++i)
            wall[i]=i;
        scanf("%d",&n);
        for(i=0;i<n;++i)
            scanf("%d %d",&poster[i][0],&poster[i][1]);
        sum=0;
        while(i--)//逆序处理
        {
            temp=poster[i][0];
            while(wall[temp]!=temp&&temp<=poster[i][1])//寻找区间内的下一个空点
                temp=wall[temp];
            if(temp<=poster[i][1])//可见
            {
                sum++;
                for(j=temp;j<=poster[i][1];++j)//标记区间内空白位置的值为区间后第一点的值
                {
                    if(wall[j]==j)
                        wall[j]=poster[i][1]+1;
                    else
                    {
                        j=wall[j]-1;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
