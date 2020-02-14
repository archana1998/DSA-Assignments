#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int start, int end, int mid)
{
    int p=mid+1,q=start,k=0,aux[end-start+1];

    for(int i=start;i<=end;i++)
    {
        if(p>end)
            aux[k++]=arr[q++];
        else if (q>mid)
            aux[k++]=arr[p++];
        else if(arr[p]>arr[q])
            aux[k++]=arr[q++];
        else
            aux[k++]=arr[p++];
    }

    for(int i=0;i<k;i++)
        arr[start++]=aux[i];
}

void mergesort(int arr[],int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int min=1,total=0;
    mergesort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        while(a[i]==a[i+1] && i<n-1)
        {
            total+=min;
            i++;
        }
        total+=min;
        min++;
    }
    printf("%d",total);
    return 0;
}