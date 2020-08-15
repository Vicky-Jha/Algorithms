// CPP program to implement traveling salesman
// problem using naive approach.
#include <iostream>
#include <vector>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    vector<int> path(V+1);
    path[0] = 0;
    path[V] = 0;
    for (int i = 0; i < V; i++)
        if (i != s)//removed then also will work with more time 
            vertex.push_back(i);
    
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
        
        // store current Path weight(cost)
        int current_pathweight = 0;
        
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        
        // update minimum
        if(min_path > current_pathweight)
        {
            min_path = current_pathweight;
            for(int i=1,j=0 ; i<V ; i++,j++)
                path[i] = vertex[j];
        }
//        min_path = min(min_path, current_pathweight);
        
    } while (next_permutation(vertex.begin(), vertex.end()));
    
    cout<<"Path is ";
    for(int i=0; i<V ; i++)
        cout<<path[i]<<" -> ";
    cout<<path[V]<<endl;
    
    cout<<"Min cost path is ";
    return min_path;
}

// driver program to test above function
int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 } };
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}

