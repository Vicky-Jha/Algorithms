// if there is an edge: eg 2 - 0, if 0 is already visited and parent of 2 is not 0, then this graph contains cycle


class Solution 
{
    public:
	bool isCycleUtil(int u, int par, vector<int>adj[], vector<bool>&vis)
	{
		vis[u] = true;
		
		for(auto v: adj[u])
		{
			if(v == par)
				continue;
			
			if(vis[v])
				return true;
			if(isCycleUtil(v, u, adj, vis))
				return true;
		}
		return false;
	}
	bool isCycle(int V, vector<int>adj[])
	{
		vector<bool>vis(V, false);
		
		for(int i = 0; i < V; i++)
		{
			if(!vis[i])
			{
				bool f = isCycleUtil(i, -1, adj, vis);
				if(f)
				    return true;
			}
		}
		return false;
	}
};

// input
// V = 3
// 0-1
// 0-2
// 1-0
// 1-2
// 2-0
// 2-1
