#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define modulo 1000000007

long long int bitdiffsum(long long int a[], int n)
{
    long long int ans=0;

    for(int i=0;i<32;i++)
    {
        int count =0;
        for(int j=0;j<n;j++)
            if(a[j] & 1<<i)
                count++;

        ans= ans%modulo + (((2*count)%modulo)*((n-count)%modulo))%modulo;
    }

    return ans%modulo;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];

    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);

    printf("%lld",bitdiffsum(a,n));
    return 0;
}
