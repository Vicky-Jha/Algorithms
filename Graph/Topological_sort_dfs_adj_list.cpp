/*
in topological sorting if u -> v in graph then u should come before v
such order we have to make
*/


class Solution
{
public:
int n; 
vector<bool> visited;
vector<int> ans;

void dfs(int v, vector<int> adj[]) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj);
    }
    ans.push_back(v);
}

void topological_sort(vector<int> adj[]) {
    visited.assign(n, false);
    ans.clear();
    for (int i = n-1; i >= 0 ; --i) {
        if (!visited[i])
            dfs(i, adj);
    }
    reverse(ans.begin(), ans.end());
}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    n = V;
	    topological_sort(adj);
	    for(int i : ans){
	        cout<<i<<" ";
	    }
	    cout<<endl;
	    return ans;
	}
};



// Input
// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1


// output
// 4 5 0 2 3 1 
