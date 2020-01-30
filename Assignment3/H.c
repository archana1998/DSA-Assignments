#include<stdio.h>

int grayCode(int n)
{
	return n^(n>>1);
}
int inversegrayCode(int n) 
{ 
    int inv = 0;
    for (; n; n = n >> 1) 
        inv ^= n; 
  
    return inv; 
} 
void binary(int n)
{
	int binaryNum[32]; 
    int i = 0; 
    if(n ==0)
    	printf("%d\n", n);
    else
    {
    	while (n > 0) { 
        	binaryNum[i] = n % 2; 
        	n = n / 2; 
        	i++; 
    	} 
    	for (int j = i - 1; j >= 0; j--) 
        	{
        		printf("%d",binaryNum[j]);
        	}
        	printf("\n");
    }
}
int decimal(int n)
{
	int num = n; 
    int dec_value = 0; 
    int base = 1; 
    int temp = num; 
    int last_digit;
    while (temp>0) { 
        last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2;
    }
  
    return dec_value; 

}

int main()
{
	int N;
	scanf("%d",&N);
	char c[N];
	int A[N];
	for(int i=0;i<N;i++)
	{
		scanf(" %c %d", &c[i],&A[i]);
	}
	for(int i=0;i<N;i++)
	{
		if(c[i]=='G')
		{
			binary(grayCode(A[i]));
		}
		else
		{
			int x = inversegrayCode(decimal(A[i]));
			printf("%d\n",x);
		}
	}
	return 0;

}