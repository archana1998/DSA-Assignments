#include<stdio.h>
#include<stdlib.h>

int binsearch(int start, int end, int arr[], int key)
{
    if(start<=end)
    {
        int mid=(start+end)/2;

        if(arr[mid]==key)  
            return mid;
        else if (arr[mid]>key)
            return binsearch(start,mid-1,arr,key);
        else
            return binsearch(mid+1,end,arr,key);        
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int z;
    scanf("%d",&z);

    int start=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i+1]<a[i])
        {
            start=i+1;
            break;
        }
    }


    int ans=binsearch(start,n-1,a,z);

    if(ans==-1)
        ans=binsearch(0,start-1,a,z);

    if(ans!=-1)
        printf("YES\n%d",ans);
    else
        printf("NO");

    return 0;
}