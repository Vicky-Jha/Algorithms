class Solution
{
    public:
    bool visited[100001];
	void dfs(int v, vector<int>& topo, vector<int> adj[]) {
        visited[v] = 1;
        for(auto u : adj[v]) {
            if(!visited[u]) {
                dfs(u, topo, adj);
            }
        }
        topo.push_back(v);
    }
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<int> topo;
        
        for(int i = 0; i < V; ++i) {
            if(!visited[i])
                dfs(i, topo, adj);
        }
        
        unordered_map<int, int> umap;
        
        for(int i = 0, j = V - 1; i < V; ++i, j--) {
            umap[topo[i]] = j;
        }
        
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < adj[i].size(); ++j) {
                if(umap[i] >= umap[j]) {
                    return true;
                }
            }
        }
        
        return false;
	}
};
// need to remove error
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1# 
