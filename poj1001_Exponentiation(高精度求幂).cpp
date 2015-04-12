#include <stdio.h>
#include <string.h>

#define MAX 500

//字符串大数相加
void add_c(char *a,char *b,char *c)
{
    int len_a=strlen(a),len_b=strlen(b),len_c;
    int dot_a,dot_b,dot_c,ta,tb;
    int i,cf;
    for(i=0;i<len_a;i++)
        if(a[i]=='.')
            break;
    dot_a=i;
    if(dot_a==len_a)
    {
        a[dot_a]='.';
        len_a++;
        a[len_a]='\0';
    }
    ta=len_a-dot_a;
    for(i=0;i<len_b;i++)
        if(b[i]=='.')
            break;
    dot_b=i;
    if(dot_b==len_b)
    {
        b[dot_b]='.';
        len_b++;
        b[len_b]='\0';
    }
    tb=len_b-dot_b;
    dot_c=1+(dot_a>dot_b?dot_a:dot_b);
    c[dot_c]='.';
    cf=0;
	//处理小数部分
    if(ta>=tb)
    {
        len_c=dot_c+ta;
        for(i=ta;i>=tb;i--)
            c[dot_c+i]=a[dot_a+i];
        for(;i>0;i--)
        {
            c[dot_c+i]=a[dot_a+i]+b[dot_b+i]-'0'+cf;
            if(c[dot_c+i]>'9')
            {
                cf=1;
                c[dot_c+i]-=10;
            }
            else
                cf=0;
        }
    }
    else
    {
        len_c=dot_c+tb;
        for(i=tb;i>=ta;i--)
            c[dot_c+i]=b[dot_b+i];
        for(;i>0;i--)
        {
            c[dot_c+i]=a[dot_a+i]+b[dot_b+i]-'0'+cf;
            if(c[dot_c+i]>'9')
            {
                cf=1;
                c[dot_c+i]-=10;
            }
            else
                cf=0;
        }
    }
	//处理整数部分
    if(dot_a>=dot_b)
    {
        for(i=0;i<dot_b;i++)
        {
            c[dot_c-1-i]=a[dot_a-1-i]+b[dot_b-1-i]-'0'+cf;
            if(c[dot_c-1-i]>'9')
            {
                cf=1;
                c[dot_c-1-i]-=10;
            }
            else
                cf=0;
        }
        for(;i<dot_a;i++)
        {
            c[dot_c-1-i]=a[dot_a-1-i]+cf;
            if(c[dot_c-1-i]>'9')
            {
                cf=1;
                c[dot_c-1-i]-=10;
            }
            else
                cf=0;
        }
    }
    else
    {
        for(i=0;i<dot_a;i++)
        {
            c[dot_c-1-i]=a[dot_a-1-i]+b[dot_b-1-i]-'0'+cf;
            if(c[dot_c-1-i]>'9')
            {
                cf=1;
                c[dot_c-1-i]-=10;
            }
            else
                cf=0;
        }
        for(;i<dot_b;i++)
        {
            c[dot_c-1-i]=b[dot_b-1-i]+cf;
            if(c[dot_c-1-i]>'9')
            {
                cf=1;
                c[dot_c-1-i]-=10;
            }
            else
                cf=0;
        }

    }
    c[0]=cf+'0';
    //消除前导0和结尾0
	for(cf=0;cf<len_c&&c[cf]=='0';cf++);
	for(i=cf;i<=len_c;i++)
		c[i-cf]=c[i];
	len_c-=cf;
	for(i=len_c-1;i>=0&&c[i]=='0';i--);
	if(c[i]=='.')
		c[i]='\0';
	else
		c[i+1]='\0';
}

//字符串大数乘一位数
void mutipl_i(char *a,int b,char *c)
{
    int len_a=strlen(a),dot_a,len_c,dot_c,cf;
    int i;
    for(i=0;i<len_a;i++)
        if(a[i]=='.')
            break;
    dot_a=i;
    len_c=len_a+1;
    dot_c=dot_a+1;
    c[dot_c]='.';
    if(len_c==dot_c)
        len_c++;
    c[len_c]='\0';
    cf=0;
    for(i=len_a-1;i>dot_a;i--)
    {
        c[i+1]=(a[i]-'0')*b+cf;
        cf=c[i+1]/10;
        c[i+1]=c[i+1]-cf*10+'0';
    }
    for(i=dot_a-1;i>=0;i--)
    {
        c[i+1]=(a[i]-'0')*b+cf;
        cf=c[i+1]/10;
        c[i+1]=c[i+1]-cf*10+'0';
    }
    c[0]=cf+'0';
    //消除前导0和结尾0
	for(cf=0;cf<len_c&&c[cf]=='0';cf++);
	for(i=cf;i<=len_c;i++)
		c[i-cf]=c[i];
	len_c-=cf;
	for(i=len_c-1;i>=0&&c[i]=='0';i--);
	if(c[i]=='.')
		c[i]='\0';
}

//字符串大数乘10的b次幂
void muti10(char *a,int b)
{
    int len_a=strlen(a),dot_a;
    int i,j;
    if(b==0)
        return;
    for(i=0;i<len_a;i++)
        if(a[i]=='.')
            break;
    dot_a=i;
    if(dot_a==len_a)
    {
        a[dot_a]='.';
        len_a++;
        a[len_a]='\0';
    }
    if(b>0)
    {
        if(b<len_a-dot_a)
        {
            for(i=0;i<b;i++)
                a[dot_a+i]=a[dot_a+i+1];
            a[dot_a+b]='.';
            if(a[len_a-1]=='.')
                a[len_a-1]='\0';
        }
        else
        {
            for(i=dot_a;i<len_a-1;i++)
                a[i]=a[i+1];
            for(j=len_a-dot_a;j<=b;j++,i++)
                a[i]='0';
            a[i]='\0';
        }
    }
    else
    {
        b=-b;
        if(b<=dot_a)
        {
            for(i=0;i<b;i++)
                a[dot_a-i]=a[dot_a-i-1];
            a[dot_a-b]='.';
        }
        else
        {
            for(i=len_a;i>dot_a;i--)
                a[i+b-dot_a]=a[i];
            for(i=dot_a-1;i>=0;i--)
                a[i+b-dot_a+1]=a[i];
            for(i=1;i<=b-dot_a;i++)
                a[i]='0';
            a[0]='.';
        }
    }
}

//字符串大数平方
void square(char *a,char *b)
{
    char temp[MAX],temp1[MAX];
    int len_a=strlen(a),dot_a;
    int i;
    for(i=0;i<len_a;i++)
        if(a[i]=='.')
            break;
    dot_a=i;
    if(dot_a==len_a)
    {
        a[dot_a]='.';
        len_a++;
        a[len_a]='\0';
    }
    b[0]='\0';
    for(i=0;i<dot_a;i++)
    {
        mutipl_i(a,a[i]-'0',temp);
        muti10(temp,dot_a-i-1);
        add_c(b,temp,temp1);
        strcpy(b,temp1);
    }
    for(i=dot_a+1;i<len_a;i++)
    {
        mutipl_i(a,a[i]-'0',temp);
        muti10(temp,dot_a-i);
        add_c(b,temp,temp1);
        strcpy(b,temp1);
    }
}

//字符串大数相乘
void mutipl_c(char *a,char *b,char *c)
{
    char temp[MAX],temp1[MAX];
    int len_a=strlen(a),dot_a;
    int len_b=strlen(b),dot_b;
    int i;
    for(i=0;i<len_a;i++)
        if(a[i]=='.')
            break;
    dot_a=i;
    if(dot_a==len_a)
    {
        a[dot_a]='.';
        len_a++;
        a[len_a]='\0';
    }
    for(i=0;i<len_b;i++)
        if(b[i]=='.')
            break;
    dot_b=i;
    if(dot_b==len_b)
    {
        b[dot_b]='.';
        len_b++;
        b[len_b]='\0';
    }
    c[0]='\0';
    for(i=0;i<dot_a;i++)
    {
        mutipl_i(b,a[i]-'0',temp);
        muti10(temp,dot_a-i-1);
        add_c(c,temp,temp1);
        strcpy(c,temp1);
    }
    for(i=dot_a+1;i<len_a;i++)
    {
        mutipl_i(b,a[i]-'0',temp);
        muti10(temp,dot_a-i);
        add_c(c,temp,temp1);
        strcpy(c,temp1);
    }
}

//a的b次幂，二分
void calculate(char *a,int b,char *c)
{
    char value[MAX],temp[MAX];
    c[0]='1';
    c[1]='\0';
    strcpy(value,a);
    while(b)
    {
        if(b&1)
        {
            mutipl_c(c,value,temp);
            strcpy(c,temp);
        }
        b=b>>1;
        if(b)
        {
            square(value,temp);
            strcpy(value,temp);
        }
    }
}

int main()
{
    int n;
    char r[MAX],temp[MAX];
    while(scanf("%s%d",r,&n)!=EOF)
    {
        if(n==0)
            printf("1\n");
        else
        {
            calculate(r,n,temp);
            if(temp[0]=='\0')
                printf("0\n");
            else
                printf("%s\n",temp);
        }
    }
    return 0;
}
