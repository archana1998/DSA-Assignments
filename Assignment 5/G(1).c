#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void bin(int num, int n)
{
    int ans[n];
    for(int i=0;i<n;i++)
        ans[i]=0;


    int j=0;
    while(num>0)
    {
        ans[j++]=num%2;
        num/=2;
    }
    
    for(int i=n-1;i>=0;i--)
        printf("%d",ans[i]);
}

int main()
{
    int n,k;
    scanf("%d\n%d",&n,&k);

    int max=pow(2,n)-1;
    bool freq[max+1];

    for(int i=0;i<=max;i++)
        freq[i]=false;

    for(int i=0;i<=max;i++)
        freq[i|k]=true;

    for(int i=0;i<=max;i++)
        if(freq[i]==true)
            {
                bin(i,n);
                printf("\n");
            }

    return 0;
}