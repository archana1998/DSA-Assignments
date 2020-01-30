#include <stdio.h>

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
    {
       for (j = 0; j < n-i-1; j++)  
       {
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
       }
    }
} 

int main()
{
   int N,index;
   int count = 1;
   int max=0;
   scanf("%d",&N);
   int A[N+1];
   for(int i =0;i<N;i++)
    {
       scanf("%d",&A[i]);
    }
    bubbleSort(A,N);
    for(int i=0;i<N;i++)
    {
        if(A[i]==A[i+1])
            count++;
        else
        {
            if(count>max)
            {
                max=count;
                index = A[i];
            }
            count = 1;
        }
    }
    if(max%2 ==0 && max>=N/2)
        printf("%d",index);
    else
    {
        if(max>=(N+1)/2)
            printf("%d",index);
        else
            printf("NO MAJORITY ELEMENT");
    }
    return 0;
}
   
