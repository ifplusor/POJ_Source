#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    int N,i,t;
    double x,y;
    int r;

    while(scanf("%d",&N)!=EOF)
    {
        t=1;
        while(N--)
        {
            scanf("%lf%lf",&x,&y);
            r=(int)(PI*(x*x+y*y)/100);//计算圆的面积
            printf("Property %d: This property will begin eroding in year %d.\n",t++,r+1);
        }
        printf("END OF OUTPUT.\n");
    }
    return 0;
}
