#include <stdio.h>
#include <string.h>
#include <memory.h>

char str1[50005],str2[50005];
int temp1[50005],temp2[50005];

int main()
{
    int len1,len2,i,j;
    int *now,*last,*t;
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        last=temp1;
        now=temp2;
        memset(now,0,(len2+1)*sizeof(int));
        last[0]=0;
        for(i=0;i<len1;++i)
        {
            t=last;
            last=now;
            now=t;
            for(j=0;j<len2;++j)
            {
                if(str1[i]==str2[j])
                    now[j+1]=last[j]+1;
                else if(last[j+1]>=now[j])
                    now[j+1]=last[j+1];
                else
                    now[j+1]=now[j];
            }
        }
        printf("%d\n",now[len2]);
    }
    return 0;
}
