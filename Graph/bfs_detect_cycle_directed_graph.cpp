bool isCyclic(int V, vector<int> adj[]) 
	{
	    int N = V;
        vector<int> indegree(N);
        for(int i = 0; i < V; ++i) {
            for(auto a : adj[i]) {
                indegree[a]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return cnt != N; 
	}
