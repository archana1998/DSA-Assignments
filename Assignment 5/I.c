#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	int K;
	int index2, index1;
	int min = 100000;
	scanf("%d",&K);
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(A[i]+A[j]==K)
			{
				if(min>abs(A[i]-A[j]))
				{
					min = abs(A[i]-A[j]);
					index1 = i;
					index2 = j;
				}
			}
		}
	}
	if(min<10000)
	{
		printf("YES\n");
		if(A[index2]>A[index1])
		{
			printf("%d\n",A[index1]);
			printf("%d\n",A[index2]);
		}
		else
		{
			printf("%d\n",A[index2]);
			printf("%d\n",A[index1]);
		}
	}
	return 0;
}