#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int p[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&p[i][j]);

    int key,check=1;
    scanf("%d",&key);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(key==p[i][j])
            {
                printf("YES\n%d %d",i,j);
                check=0;
                break;
            }

        if(check==0)
            break;
    }

    if(check==1)
        printf("MISSING");
    return 0;
}