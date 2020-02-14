#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void merge(int arr[], int start, int end, int mid)
{
    int aux[end-start+1],p=mid+1,q=start,k=0;

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

void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int binsearch(int key, int arr[],int start, int end)
{
    if(start<=end)
    {
        int mid=(start+end)/2;

        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            return binsearch(key,arr,start,mid-1);
        else 
            return binsearch(key,arr,mid+1,end);
    }

    return -1; 
}

int main()
{
    int n,m,l;
    scanf("%d %d %d",&n,&m,&l);

    int u,v,a,b,k;
    scanf("%d %d %d %d %d",&u,&v,&a,&b,&k);

    int gas[m];

    for(int i=0;i<m;i++)
        scanf("%d",&gas[i]);

    int container[l];

    for(int i=0;i<l;i++)
        scanf("%d",&container[i]);

    mergesort(gas,0,m-1);
    mergesort(container,0,l-1);

    int curr=binsearch(u,gas,0,m);
    int dest=binsearch(v,gas,0,m);
    int cost=0;

    while(curr!=dest)
    {
        int x=gas[curr+1]-gas[curr];
        bool check=true;

        for(int i=0;i<l;i++)
            if(a*container[i]+b>=x)
            {
                check=false;
                curr++;
                cost+=container[i];
                break;
            }

        if(check==true)
        {
            printf("NOT POSSIBLE");
            break;
        }
    }

    printf("%d",k*cost);
    return 0;
}