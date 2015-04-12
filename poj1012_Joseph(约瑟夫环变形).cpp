#include <stdio.h>

int lst[14];
int main()
{
    int i,j;
    int s,m,t,k;
    // 打表
    for(k=1;k<14;k++)
    {
        for(m=k;1;++m)
        {
            s=0;
            for(t=k*2;t>k;--t)//环中人数递减，同时改变后缀人的编号
            {
                s=(s+m)%t;
                if(s<k)//出环人的编号必大于k，否则失败
                    break;
            }
            if(t==k)//成功
                break;
        }
        lst[k]=m+1;
    }
    while(1)
    {
        scanf("%d",&k);
        if(k==0)
            break;
        printf("%d\n",lst[k]);
    }
    return 0;
}
