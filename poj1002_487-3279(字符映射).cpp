#include <stdio.h>
#include <algorithm>

using namespace std;

int tel[100003];

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    int n,i,j,num;
    bool t;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        //将电话号码恢复为数字格式，并映射到十进制数
        for(i=0;i<n;i++)
        {
            num=0;
            while(1)
            {
                switch(getchar())
                {
                case '0':
                    num=num*10;
                    break;
                case '1':
                    num=num*10+1;
                    break;
                case '2':
                case 'A':
                case 'B':
                case 'C':
                    num=num*10+2;
                    break;
                case '3':
                case 'D':
                case 'E':
                case 'F':
                    num=num*10+3;
                    break;
                case '4':
                case 'G':
                case 'H':
                case 'I':
                    num=num*10+4;
                    break;
                case '5':
                case 'J':
                case 'K':
                case 'L':
                    num=num*10+5;
                    break;
                case '6':
                case 'M':
                case 'N':
                case 'O':
                    num=num*10+6;
                    break;
                case '7':
                case 'P':
                case 'R':
                case 'S':
                    num=num*10+7;
                    break;
                case '8':
                case 'T':
                case 'U':
                case 'V':
                    num=num*10+8;
                    break;
                case '9':
                case 'W':
                case 'X':
                case 'Y':
                    num=num*10+9;
                    break;
                case '\n':
                    goto loop;
                    break;
                }
            }
loop:
            tel[i]=num;
        }
        sort(tel,tel+n,cmp);
        num=tel[0];
        j=1;
        t=false;
        for(i=1;i<n;i++)
        {
            if(num==tel[i])
            {
                j++;//重复计数
            }
            else
            {
                //输出重复号码
                if(j>1)
                {
                    printf("%03d-%04d %d\n",num/10000,num%10000,j);
                    j=1;
                    t=true;
                }
                num=tel[i];
            }
        }
        if(j>1)
        {
            printf("%03d-%04d %d\n",num/10000,num%10000,j);
            t=true;
        }
        if(!t)
            printf("No duplicates.\n");
    }
    return 0;
}
