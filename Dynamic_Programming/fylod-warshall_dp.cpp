
#include <iostream>
using namespace std;


#define V 8


#define INF 99999


void printSolution(int dist[][V]);

void floydWarshall (int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    
     for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

    printSolution(dist);
}

void printSolution(int dist[][V])
{
    cout<<"The following matrix shows the shortest distances"
    " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}


int main()
{

    int graph[V][V] = { {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2}    };
    
    floydWarshall(graph);
    return 0;
}


