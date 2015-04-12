#include <stdio.h>
#include <memory.h>

int lst[10005];
/*
int deal(int k)
{
    if(lst[k]==0)
    {
        if(k&1)
            lst[k]=1+deal(k*3+1);
        else
            lst[k]=1+deal(k>>1);
    }
    return lst[k];
}*/
int deal1(int k)
{
    if(k<=10000&&lst[k]!=0)
        return lst[k];
    if(k&1)//ÆæÊý
        return 1+deal1(k*3+1);
    else//Å¼Êý
        return 1+deal1(k>>1);
}
int main()
{
    int i,j,t;
    memset(lst,0,sizeof(lst));
    lst[1]=1;
    for(i=2;i<=10000;++i)
        if(lst[i]==0)
            lst[i]=deal1(i);
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        printf("%d %d ",i,j);
        if(j<i)
        {
            t=j;j=i;i=t;
        }
        t=lst[i];
        for(++i;i<=j;++i)
            if(t<lst[i])
                t=lst[i];
        printf("%d\n",t);
    }
    return 0;
}
