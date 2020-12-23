// CPP program to find shortest distance
// in a multistage graph.
#include<iostream>
using namespace std;

#define N 12
#define INF INT_MAX

// Returns shortest distance from 0 to
// N-1.
int shortestDist(int graph[N][N]) {
    
    // dist[i] is going to store shortest
    // distance from node i to node N-1.
    int dist[N];
    
    dist[N-1] = 0;
    
    // Calculating shortest path for
    // rest of the nodes
    for (int i = N-2 ; i >= 0 ; i--)
    {
        
        // Initialize distance from i to
        // destination (N-1)
        dist[i] = INF;
        
        // Check all nodes of next stages
        // to find shortest distance from
        // i to N-1.
        for (int j = i ; j < N ; j++)
        {
            // Reject if no edge exists
            if (graph[i][j] == INF)
                continue;
            
            // We apply recursive equation to
            // distance to target through j.
            // and compare with minimum distance
            // so far.
            dist[i] = min(dist[i], graph[i][j] +
                          dist[j]);
        }
    }
    
    for(int i=0 ; i<N;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    
    return dist[0];
}

// Driver code
int main()
{
    // Graph stored in the form of an
    // adjacency Matrix
    int graph[N][N] =
    {   {INF, 9 ,7, 3, 2, INF, INF ,INF, INF, INF, INF, INF},
        {INF ,INF ,INF ,INF ,INF ,4 ,2 ,1 ,INF, INF, INF ,INF},
        {INF, INF, INF, INF ,INF, 2 ,7, INF, INF, INF, INF, INF},
        {INF ,INF, INF, INF ,INF ,INF ,INF ,11 ,INF ,INF ,INF ,INF},
        {INF ,INF, INF, INF, INF, INF, 11, 8, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 6, 5, INF, INF},
        {INF ,INF, INF, INF ,INF, INF ,INF, INF, 4 ,3, INF ,INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 5 ,6, INF},
        {INF ,INF, INF, INF ,INF, INF, INF, INF, INF, INF, INF, 4},
        {INF, INF, INF, INF ,INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5},
        {INF ,INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}
  };
    
    cout << shortestDist(graph);
    return 0;
}

