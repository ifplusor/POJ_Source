#include<stdio.h>

//欧几里得扩展算法
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    __int64 g,t;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    t=a%b;
    g=exgcd(b,t,x,y);
    t=x;
    x=y;
    y=t-(a/b)*y;
    return g;
}

int main()
{
    __int64 x,y,m,n,L;
    __int64 a,b,g,u,v,k;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L)!=EOF)
    {
        // x+k*m=y+k*n (mod L) => (m-n)*k=y-x (mod L)  令a=m-n,b=y-x
        a=m-n;
        b=y-x;
        // mod L 调整数值范围
        while(a<0)a+=L;
        a=a%L;
        while(b<0)b+=L;
        b=b%L;
        g=exgcd(L,a,u,v);// L*u+a*v=g=gcd(L,a)  u=u0+t*a/g  v=v0-t*L/g  t=为整数
        if(b%g!=0)
            printf("Impossible\n");
        else
        {
            while(v<0)v+=L;
            k=v*(b/g);// a*k=b(mod L) , L*u+a*v=g => k=v*(b/g) k=k0+t*(L/g) t为整数
            // 求最小正整数解
            __int64 t=k*g/L;
            k=k-t*L/g;
            if(t<0)
                k+=L/g;
            printf("%I64d\n",k);
        }
    }
    return 0;
}
