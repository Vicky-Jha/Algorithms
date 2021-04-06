//dfs
#include<stdio.h>

void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
//int count = 0;
int main()
{
    int i,j;
    printf("Enter number of vertices:");
    
    scanf("%d",&n);
    
    printf("\nEnter adjecency matrix of the graph:");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    for(i=0;i<n;i++)
        visited[i]=0;
//    DFS(5);
    for(i = 5; i >= 0; --i)
    {
        if(!visited[i])
            DFS(i);
    }
    return 0;
}

void DFS(int i)
{
    int j;
//    printf("\n%d",i);
    visited[i]=1;
//    count++;
    
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
    printf("\n%d",i);
//    count--;
//    visited[i]= 0;
    
}
// input
// 6
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 1 0 0
// 0 1 0 0 0 0
// 1 1 0 0 0 0
// 1 0 1 0 0 0


// output

// 0
// 1
// 3
// 2
// 5
// 4

