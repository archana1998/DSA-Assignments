#include<stdio.h>
#include<stdlib.h>

int fact(int x)
{
    if(x==0 || x==1)
        return 1;
    else
        return x*fact(x-1);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    int maxi=-1;

    for(int i=0;i<n;i++)
        if((a[i]-a[0])<=k)
            maxi=i;
    
    if(maxi<2)
        printf("0");
    else
    {
        int ans=fact(maxi+1)/(6*fact(maxi-2));
        printf("%d",ans);
    }

    return 0;
}