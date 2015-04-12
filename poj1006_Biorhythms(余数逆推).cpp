#include <stdio.h>



int main()
{
    int p,e,i,d,t=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF)
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)
            break;
        //逆推聚合点
        while(p!=e)
        {
            if(p>e)
                e+=28;
            else
                p+=23;
        }
        while(p!=i)
        {
            if(p>i)
            {
                i+=(p-i)/33*33;
                if(p>i)
                    i+=33;
            }
            else
                p+=644;
        }
        d=p-d;
        if(d>21252)
            d-=21252;
        else if(d<=0)
            d+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",t++,d);
    }
    return 0;
}
