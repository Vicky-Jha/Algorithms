//Steps
//1 start node weight  = 0
//2 update all the weights of all the nodes connected to the start node
//3 Now check for the minimum weighted node of all availavble nodes
//4 update the weights of node connected to the node from step three
//5 repeat step 3 and 4


#include<iostream>
#include <vector>
#define INFINITY 99999
using namespace std;

void dijkstra(vector<vector<int>> G,int n,int startnode);

int main()
{
    int n;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int i,j,u;
    vector<vector<int>> G(n , vector<int> (n));
    printf("\nEnter the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    dijkstra(G,n,u);
    printf("\n");
    
    
    
    return 0;
}

void dijkstra(vector<vector<int>> G,int n,int startnode)
{
    int cost[n][n],distance[n],pred[n];
    int visited[n],count,mindistance,greenNode,i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
    
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<=n)
    {
        mindistance=INFINITY;
        
        
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                greenNode=i;//greenNode is the node checked and node of distance[i];
            }
        
        
        visited[greenNode]=1;
        for(i=0;i<n;i++)
            if(!visited[i]) // if you remove this then this  algo will also take -ve weights
                if(mindistance+cost[greenNode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[greenNode][i];
                    pred[i]=greenNode;
                }

        count++;
    }
//
//    for(i=0 ; i<n ; i++)
//        printf("%d \n",pred[i]);
    
    
    for(i=0;i<n;i++)
        
        {
            printf("\nDistance of node %d = %d ",i,distance[i]);
            printf("\nPath = %d ",i);
            
            j=i;
            do
            {
                j=pred[j];
                printf(" <- %d ",j);
            }while(j!=startnode);
        }
}


// 9
// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0
