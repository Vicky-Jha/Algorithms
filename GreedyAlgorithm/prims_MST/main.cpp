#include <iostream>
#include <vector>
using namespace std;

#define infinity 9999


int prims(vector<vector<int>> G , int n);

int main()
{
    int i,j,total_cost,n;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    vector<vector<int>> G( n , vector<int> (n));
    printf("\nEnter the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    prims(G,n);
    
    return 0;
}

int prims(vector<vector<int>> G , int n)
{
    int cost[n][n];
    int spanning[n][n];
    int u,greenNode,min_distance,distance[n],pred[n];
    int visited[n],count,i,min_cost,j;
    
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
            spanning[i][j]=0;
        }
    
    
    for(i=0;i<n;i++)
    {
        distance[i]=cost[0][i];
        pred[i]=0;
        visited[i]=0;
    }
    
    distance[0]=0;
    visited[0]=1;

    
    min_cost=0;
    count=1;
    
    float f1, f2;
    
    if(fabs(f1 - f2) > __FLT_EPSILON__) cout<<"hi " <<__FLT_EPSILON__<<endl;
    
    
    while(count<n)
    {
        
        min_distance=infinity;
        for(i=0;i<n;i++)
            if(!visited[i]&&distance[i]<min_distance)
            {
                greenNode=i;
                min_distance=distance[i];
            }
        greenNode;
        u=pred[greenNode];
        
        spanning[u][greenNode]=min_distance;
        spanning[greenNode][u]=min_distance;
        visited[greenNode]=1;
        
        for(i=0;i<n;i++)
            if(!visited[i]&&cost[greenNode][i]<distance[i])
            {
                distance[i]=cost[greenNode][i];
                pred[i]=greenNode;
            }
        
        min_cost=min_cost+min_distance; // min_distance = cost[u][greenNode] || cost[greenNode][u];
        count++;
    }
    printf("\nspanning tree matrix:\n");
    
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d\t",spanning[i][j]);
    }
    
    printf("\n\nTotal cost of spanning tree=%d",min_cost);
    
    return(min_cost);
}
