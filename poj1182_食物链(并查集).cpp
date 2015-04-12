#include <stdio.h>

int animal[50001];
int eat[50001];
int deeat[50001];

int fid(int t)//查找本集
{
    if(animal[t]==t)
        return t;
    return animal[t]=fid(animal[t]);
}
int fideat(int t)//查找吃集
{
    int e=eat[fid(t)];
    if(e!=-1)
        return eat[t]=fid(e);
    return -1;
}
int fiddeeat(int t)//查找被吃集
{
    int de=deeat[fid(t)];
    if(de!=-1)
        return deeat[t]=fid(de);
    return -1;
}

void mrg(int a,int b)//a，b同类关系合并
{
    a=fid(a);
    b=fid(b);

    if(a==b)//同一集合
        return;

    int ae=fideat(a),be=fideat(b);//将a的吃集追加到b的吃集上
    if(ae!=-1)
    {
        if(be!=-1)
            animal[ae]=be;
        else
        {
            eat[b]=ae;
            be=ae;
        }
    }
    int ade=fiddeeat(a),bde=fiddeeat(b);//将b的吃集追加到a的吃集上
    if(ade!=-1)
    {
        if(bde!=-1)
            animal[ade]=bde;
        else
        {
            deeat[b]=ade;
            bde=ade;
        }
    }
    animal[a]=b;//将a的集合追加到b的集合上

    //保证集合关系一致性
    if(be!=-1)
    {
        int bee=fideat(be);
        if(bee==-1&&bde!=-1)
            eat[be]=bde;
    }
    if(bde!=-1)
    {
        int bdede=fiddeeat(bde);
        if(bdede==-1&&be!=-1)
            deeat[bde]=be;
    }
}
void mrgeat(int a,int b)//a吃b关系合并
{
    int ae=fideat(a);
    b=fid(b);

    if(ae==b)
        return;

    a=fid(a);
    int ade=fiddeeat(a);
    int be=fideat(b),bde=fiddeeat(b);
    if(bde!=-1)
        animal[a]=bde;
    else
    {
        deeat[b]=a;
        bde=a;
    }
    if(ae!=-1)
        animal[ae]=b;
    if(ade!=-1)
    {
        if(be!=-1)
            animal[ade]=be;
        else
        {
            eat[b]=ade;
            be=ade;
        }
    }

    //保证集合关系一致性
    int bdee=fideat(bde);
    if(bdee!=b)
        eat[bde]=b;
    if(be!=-1)
    {
        int bee=fideat(be);
        if(bee==-1&&bde!=-1)
            eat[be]=bde;
        int bede=fiddeeat(be);
        if(bede=-1)
            deeat[be]=b;
        int bdede=fiddeeat(bde);
        if(bdede==-1&&be!=-1)
            deeat[bde]=be;
    }
}

int main()
{
    int N,K,sum=0;
    int x,y,d;
    scanf("%d %d",&N,&K);
    for(int i=0;i<=N;i++)//初始化
    {
        animal[i]=i;
        eat[i]=-1;
        deeat[i]=-1;
    }
    for(int i=0;i<K;i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x>N||y>N)//超出范围，假话
        {
            sum++;
            continue;
        }
        x=fid(x);
        y=fid(y);
        if(d==1)//同类关系：不相吃
        {
            int xe=fideat(x),ye=fideat(y);
            if(xe!=-1)
            {
                if(xe==y)//x吃y，假话
                {
                    sum++;
                    continue;
                }
            }
            if(ye!=-1)
            {
                if(ye==x)//y吃x，假话
                {
                    sum++;
                    continue;
                }
            }
            int xde=fiddeeat(x),yde=fiddeeat(y);
            if(xde!=-1)
            {
                if(xde==y)//x被y吃，假话
                {
                    sum++;
                    continue;
                }
            }
            if(yde!=-1)
            {
                if(yde==x)//y被x吃，假话
                {
                    sum++;
                    continue;
                }
            }

            mrg(x,y);//同类合并
        }
        else//x吃y关系
        {
            if(x==y)//同类，假话
            {
                sum++;
                continue;
            }
            int ye=fideat(y);
            if(ye!=-1&&ye==x)//y吃x，假话
            {
                sum++;
                continue;
            }

            mrgeat(x,y);//吃关系合并
        }
    }
    printf("%d\n",sum);
    return 0;
}

//更简便的思路参考：http://blog.csdn.net/jxust_tj/article/details/43668901
