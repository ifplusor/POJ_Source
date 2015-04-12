#include<stdio.h>
#include<algorithm>

using namespace std;

struct DNA
{
    char strings[60];
    int value;
};

bool cmp(struct DNA a,struct DNA b)
{
    return a.value<b.value;
}

struct DNA test[105];
int v[26];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%s",test[i].strings);
            test[i].value=0;
            v['A'-'A']=v['C'-'A']=v['G'-'A']=v['T'-'A']=0;
            for(j=n-1;j>=0;j--)
            {
                v[test[i].strings[j]-'A']++;//字符计数
                switch(test[i].strings[j])//累加
                {
                case 'T':
                    test[i].value+=v['G'-'A'];
                case 'G':
                    test[i].value+=v['C'-'A'];
                case 'C':
                    test[i].value+=v['A'-'A'];
                case 'A':
                    break;                
                }
            }
        }
        sort(test,test+m,cmp);
        for(i=0;i<m;i++)
            printf("%s\n",test[i].strings);
    }
    return 0;
}
