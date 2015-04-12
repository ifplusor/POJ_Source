#include <stdio.h>

int main()
{
    int n,X,Y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&X,&Y);
        if(X>=Y)
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    }
    return 0;
}
