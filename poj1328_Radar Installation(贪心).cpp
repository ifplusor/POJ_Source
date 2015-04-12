#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct interval
{
    double l,r;
};
struct interval key[1000];

bool cmp(struct interval a, struct interval b)
{
    return a.l < b.l;
}

int main()
{
    int n, d, sum, ledge, i, index = 0;
    double redge;
    bool in;
    while(1)
    {
        index++;
        scanf("%d %d", &n, &d);
        if(n == 0 && d == 0)
            break;
        if(d <= 0)
            in = false;
        else
            in = true;
        for(i = 0; i < n; ++i)
        {
            int x,y;
            double k;
            scanf("%d %d", &x, &y);
            if(in)
            {
                if(y > d)
                    in = false;
                k = sqrt((double)(d*d-y*y));
                key[i].l = x - k;
                key[i].r = x + k;
            }
        }
        if(!in)
            printf("Case %d: %d\n", index, -1);
        else
        {
            sort(key, key + n, cmp);
            sum = 0;
            ledge = 0;
            while(ledge < n)
            {
                redge = key[ledge].r;
                for(i = ledge; i < n; ++i)
                {
                    if(key[i].r < redge)//缩小重叠区间右边界
                        redge = key[i].r;
                    if(key[i].l > redge)//区间左边界超出右边界
                    {
                        sum++;
                        break;
                    }
                }
                ledge = i;
            }
            sum++;
            printf("Case %d: %d\n", index, sum);
        }
    }
    return 0;
}
