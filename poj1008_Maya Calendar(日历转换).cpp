#include<stdio.h>


int main()
{
    int N,d,y,sum;
    char m[10];
    scanf("%d",&N);
    printf("%d\n",N);//输出用例数
    while(N--)
    {
        scanf("%d",&d);
        getchar();getchar();
        scanf("%s%d",m,&y);
        //计算日期序
        sum=y*365+d;
        if(m[0]=='p')
        {   //pop
            if(m[1]=='a')//pax
                sum+=15*20;
        }
        else if(m[0]=='n')//no
        {
            sum+=20;
        }
        else if(m[0]=='z')
        {
            if(m[1]=='i')//zip
                sum+=2*20;
            else if(m[1]=='o')//zotz
                sum+=3*20;
            else//zac
                sum+=10*20;
        }
        else if(m[0]=='t')//tzec
        {
            sum+=4*20;
        }
        else if(m[0]=='x')//xul
        {
            sum+=5*20;
        }
        else if(m[0]=='y')
        {
            if(m[1]=='o')//yoxkin
                sum+=6*20;
            else//yax
                sum+=9*20;
        }
        else if(m[0]=='m')
        {
            if(m[1]=='o')//mol
                sum+=7*20;
            else if(m[1]=='a')//mac
                sum+=12*20;
            else//muan
                sum+=14*20;
        }
        else if(m[0]=='c')
        {
            if(m[1]=='h')//chen
                sum+=8*20;
            else if(m[1]=='e')//ceb
                sum+=11*20;
            else//cumbu
                sum+=17*20;
        }
        else if(m[0]=='k')
        {
            if(m[1]=='a')//kankin
                sum+=13*20;
            else//koyab
                sum+=16*20;
        }
        else
            sum+=18*20;
        //日期转换
        printf("%d ",sum%13+1);
        switch(sum%20)
        {
        case 0:
            printf("imix ");
            break;
        case 1:
            printf("ik ");
            break;
        case 2:
            printf("akbal ");
            break;
        case 3:
            printf("kan ");
            break;
        case 4:
            printf("chicchan ");
            break;
        case 5:
            printf("cimi ");
            break;
        case 6:
            printf("manik ");
            break;
        case 7:
            printf("lamat ");
            break;
        case 8:
            printf("muluk ");
            break;
        case 9:
            printf("ok ");
            break;
        case 10:
            printf("chuen ");
            break;
        case 11:
            printf("eb ");
            break;
        case 12:
            printf("ben ");
            break;
        case 13:
            printf("ix ");
            break;
        case 14:
            printf("mem ");
            break;
        case 15:
            printf("cib ");
            break;
        case 16:
            printf("caban ");
            break;
        case 17:
            printf("eznab ");
            break;
        case 18:
            printf("canac ");
            break;
        case 19:
            printf("ahau ");
            break;
        }
        printf("%d\n",sum/260);
    }
    return 0;
}
