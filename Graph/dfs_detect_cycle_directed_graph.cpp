class Solution
{
    public:
    vector<int> state;
    bool cycle = false;
    bool dfs(int v, vector<int> adj[]) {
        if(cycle == true) {
            return true;
        }
        if(state[v] != -1) {
            return state[v];
        }
        state[v] = 0;//visiting state
        for(auto u : adj[v]) {
            if(!dfs(u, adj)) {
                cycle = true;
                return false; // here can return any bool(true, false)
            }
        }
        return state[v] = 1;//visited state
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	state.resize(V, - 1);//unvisited state
	   	
	   	for(int i = 0; i < V; ++i) {
	   	    dfs(i, adj);
	   	    if(cycle) {
	   	        return true;
	   	    }
	   	}
	   	return false;
	}
};
