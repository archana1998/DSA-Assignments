#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000], word[1000];
	scanf("%s", str);
	scanf(" %s",word);
	int slen = strlen(str);
	int wlen = strlen(word);
	int flag =0;
	int count =0;
	for(int i=0;i<slen;i++)
	{
		flag = 0;
		for(int j=0;j<wlen && i+j<slen;j++)
		{
			if(flag==1 &&str[i+j]!=word[j])
			{
				flag =2;
				break;
			}
			if(flag==0 && str[i+j]!=word[j])
			{
				flag = 1;
			}
		}
		if(flag==1)
			count++;
	}
	printf("%d\n", count);
}