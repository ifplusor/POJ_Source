#include <stdio.h>


struct node{
    int lv,rv;
    int maxh,minh;
}tree[200005];

void create(int root,int l,int r)
{
    tree[root].lv=l;
    tree[root].rv=r;

    if(l==r)
    {
        scanf("%d",&tree[root].maxh);
        tree[root].minh=tree[root].maxh;
        return;
    }

    int t=(l+r)/2;
    create(root*2,l,t);
    create(root*2+1,t+1,r);
    tree[root].maxh=tree[root*2].maxh>=tree[root*2+1].maxh?tree[root*2].maxh:tree[root*2+1].maxh;
    tree[root].minh=tree[root*2].minh<=tree[root*2+1].minh?tree[root*2].minh:tree[root*2+1].minh;
};

void query(int root,int l,int r,int &maxh,int &minh)
{
    if(l==tree[root].lv&&r==tree[root].rv)
    {
        if(tree[root].maxh>maxh)
            maxh=tree[root].maxh;
        if(tree[root].minh<minh)
            minh=tree[root].minh;
        return;
    }

    int t=(tree[root].lv+tree[root].rv)/2;
    if(t<l)
        query(root*2+1,l,r,maxh,minh);
    else if(t>=r)
        query(root*2,l,r,maxh,minh);
    else
    {
        query(root*2,l,t,maxh,minh);
        query(root*2+1,t+1,r,maxh,minh);
    }
}

int main()
{
    int N,Q,A,B;
    int i,maxh,minh;
    while(scanf("%d%d",&N,&Q)!=EOF)
    {
        create(1,1,N);
        for(i=0;i<Q;i++)
        {
            scanf("%d%d",&A,&B);
            maxh=1;
            minh=1000000;
            query(1,A,B,maxh,minh);
            printf("%d\n",maxh-minh);
        }
    }
    return 0;
}
