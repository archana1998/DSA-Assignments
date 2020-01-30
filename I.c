#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x=*y;
	*y=temp;
}

void sort(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
int checkSum(int a[],int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum = sum+a[i];
	}
	return sum;
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
int bucket(int a[],int m,int N)
{
	int min=1000,index;
	for(int i=0;i<N;i++)
	{
		if(a[i]%3==m && a[i]!=0)
		{
			if(min>a[i])
				{
					min = a[i];
					index = i;
				}
		}
	}
	return index;
}
void remove_ele(int A[],int i,int N)
{
	for(int j=i;j<N-1;j++)
	{
		A[j]=A[j+1];
	}
}
int main()
{
	int N,p,mod;
	int flag=0;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]==0)
			flag=1;
	}
	if(flag == 0)
	{
		printf("NO NUMBER");
		return 0;
	}
	sort(A,N);
	mod = checkSum(A,N)%3;
	if(mod==0)
	{
		print(A,N);
		return 0;
	}
	else
	{
		p = bucket(A,mod,N);
		remove_ele(A,p,N);
		print(A,N-1);
		return 0;
	}
	
}
	


