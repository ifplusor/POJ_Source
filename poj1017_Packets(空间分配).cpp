#include <stdio.h>

int s[7];

int main()
{
    int sum,t,t2;
    while(1)
    {
        scanf("%d %d %d %d %d %d",s+1,s+2,s+3,s+4,s+5,s+6);

        sum=s[6];//size_6*1封箱

        sum+=s[5];//size_5*1配size_1*11封箱
        s[1]-=s[5]*11;//剔除用来配size_5的size_1
        if(s[1]<0)
            s[1]=0;

        sum+=s[4];//size_4*1配size_2*5封箱，size_2不够则拿size_1*4替换
        s[2]-=s[4]*5;//剔除用来配size_4的size_2
        if(s[2]<0)
        {
            t=s[2];//size_2不够配，保存缺口
            s[2]=0;
        }
        else
            t=0;
        s[1]+=t*4;//剔除用来配size_4的size_1
        if(s[1]<0)
            s[1]=0;

        sum+=s[3]/4;//使用size_3*4封箱
        t=s[3]-(s[3]/4)*4;
        if(t==3)//size_3*3配size_2*1和size_1*5封箱，size_2不够则拿size_1*4替换
        {
            sum++;
            if(s[2]==0)
                s[1]-=9;
            else
            {
                s[2]--;
                s[1]-=5;
            }
            if(s[1]<0)
                s[1]=0;
        }
        else if(t==2)//size_3*2配size_2*3和size_1*6封箱，size_2不够则拿size_1*4替换
        {
            sum++;
            s[2]-=3;
            if(s[2]<0)
            {
                t2=s[2];//size_2不够配，保存缺口
                s[2]=0;
            }
            else
                t2=0;
            s[1]+=t2*4-6;//剔除用来配size_4的size_1
            if(s[1]<0)
                s[1]=0;
        }
        else if(t==1)//size_3*1配size_2*5和size_1*7封箱，size_2不够则拿size_1*4替换
        {
            sum++;
            s[2]-=5;
            if(s[2]<0)
            {
                t2=s[2];//size_2不够配，保存缺口
                s[2]=0;
            }
            else
                t2=0;
            s[1]+=t2*4-7;//剔除用来配size_4的size_1
            if(s[1]<0)
                s[1]=0;
        }

        s[2]+=s[1]/4;//将size_1合并到size_2上处理
        s[1]-=(s[1]/4)*4;
        if(s[1]>0)
            s[2]++;
        sum+=s[2]/9;
        s[2]=s[2]-(s[2]/9)*9;
        if(s[2]>0)
            sum++;

        if(sum==0)
            break;
        printf("%d\n",sum);
    }
    return 0;
}
