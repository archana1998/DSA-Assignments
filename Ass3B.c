#include <stdio.h>
int main()
{
    long long int N;
    int max = 0;
    int count = 0;
    int p,index;
    scanf("%lld", &N);
    for(int i=2;i<=N;i++)
    {
        p = i;
        count = 1;
        while(p>1)
        {
            if(p%2==0)
            {
                p = p/2;
            }
            else
            {
                p = 3*p + 1;
            }
            count++;
        }
        if(count>max)
        {
            max = count;
            index = i;
        }    
    }
    printf("%d %d", index, max);
    return 0;
}
