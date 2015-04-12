#include <stdio.h>
#include <memory.h>

char str[50005];
int temp1[50005],temp2[50005];

int main()
{
    int n,i,j;
    int *now,*last,*t;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",str);
        last=temp1;
        now=temp2;
        memset(now,0,(n+1)*sizeof(int));
        last[0]=0;
        for(i=n-1;i>=0;--i)
        {
            t=last;
            last=now;
            now=t;
            for(j=0;j<n;++j)
            {
                if(str[i]==str[j])
                    now[j+1]=last[j]+1;
                else if(last[j+1]>=now[j])
                    now[j+1]=last[j+1];
                else
                    now[j+1]=now[j];
            }
        }
        printf("%d\n",n-now[n]);
    }
    return 0;
}
