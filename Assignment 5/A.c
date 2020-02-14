#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int n,max=INT_MIN,dest=-1,fdest=INT_MIN,fsrc=INT_MAX,maxprev=INT_MIN;
bool check;

void DFS(int src, bool vis[], bool graph[][n], int dis)
{
    vis[src]=true;
    dis++;

    if(dis>=max)
    {
        max=dis;
        check=true;
        dest=src;
    }

    for(int i=0;i<n;i++)
        if(graph[src][i]==true && vis[i]==false)
            DFS(i,vis,graph,dis);
}

int main()
{
    
    scanf("%d",&n);

    bool graph[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=false;

    for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);

            graph[v][u]=true;
            graph[u][v]=true;
        }

    bool maxbeg[n],maxend[n],vis[n];

    for(int i=0;i<n;i++)
    {    
        check=false;

        for(int j=0;j<n;j++)           
            vis[j]=false;

        maxprev=max;
        DFS(i,vis,graph,0);
        
        if(check==true)
        {
            if(max>maxprev)
            {
                fsrc=i;
                fdest=dest;
            }
            else if (i<fsrc)
            {
                fsrc=i;
                fdest=dest;
            }
            else if(dest>fdest)
            {
                fsrc=i;
                fdest=dest;
            }
        }
    }

    printf("%d\n%d %d",max-1,fsrc,fdest);
    return 0;
}