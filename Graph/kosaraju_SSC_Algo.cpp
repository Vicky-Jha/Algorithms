/*
Kosaraju's algo is used to find all the strongly connected components(SSC) in a directed graph
In any SSC from any vertice all other vertice can be visited
step1 : to find the increasing order of outdegree of all vertices using dfs1
step2 : to find transpose of adj list or matrix
step3 : to iterate over outDegree's one by one and if not visited then dfs to find SSC
*/



#include<bits/stdc++.h>
using namespace std;
class Solution{	
public:
//   to find the increasing order of outdegree of all vertices using dfs1
    void dfs1(int V, int u, vector<int> adj[], vector<bool>& visited, stack<int>& outDegree){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                dfs1(V, v, adj, visited, outDegree);
            }
        }
        outDegree.push(u);
    }
    void transpose(vector<int> transpose_adj[], vector<int> adj[], int V){
        for(int i = 0; i < V; ++i){
            for(int v : adj[i]){
                transpose_adj[v].push_back(i);
            }
        }
    }
//   to iterate over outDegree's one by one and if not visited then dfs2 to find SSC
    void dfs2(int V, int u, vector<int> transpose_adj[], vector<bool>& visited){
        visited[u] = true;
        cout<<u<<" ";
        for(int v : transpose_adj[u]){
            if(!visited[v]){
                dfs2(V, v, transpose_adj, visited);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> transpose_adj[V];
        stack<int> outDegree;
        for(int i = 0; i < V; ++i){
            if(!visited[i])
            dfs1(V, i, adj, visited, outDegree);
        }
        for(int i = 0; i < V; ++i){
            visited[i] = false;
        }
        transpose(transpose_adj, adj, V);
        int p = 1;
        while(!outDegree.empty()){
            int ssc = outDegree.top();
            outDegree.pop();
            if(!visited[ssc]){
                cout<<"SCC #"<<p++<<endl;
                dfs2(V, ssc, transpose_adj, visited);
                cout<<endl;
            }
        }
        return p - 1;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << "Total Connected components = "obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}



// For Input:
// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4
// your output is: 
// SCC #1
// 0 1 2 
// SCC #2
// 3 
// SCC #3
// 4 
// Total Connected components = 3
