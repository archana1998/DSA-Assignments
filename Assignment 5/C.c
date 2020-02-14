#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    int a[n+1][n+1],ans[n],vis[n+1];

    for(int i=0;i<=n;i++)
    {
        vis[i]=0;
        for(int j=0;j<=n;j++)
            a[i][j]=0;
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u][v]=1;
    }
    bool final=true;
    int k=0;
    int l=1;
    for(;l<=n;l++)
    {
        bool check1=true;
        for(int i=1;i<=n;i++)
        {
            bool check=true;
            if(vis[i]==0)
            {
                for(int j=1;j<=n;j++)
                    if(a[i][j]==1)
                    {
                        check=false;
                        break;
                    }           
            
            
            if(check==true)
            {
                vis[i]=1;
                for(int j=0;j<=n;j++)
                    a[j][i]=0;

                ans[k++]=i;
                check1=false;
                break;
            }
            }
        }
        if(check1==true)
        {            
            printf("NOT POSSIBLE\n",l);
            final=false;
            break;
        }
    }

    if(final==true)
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]);
    
    return 0;
}