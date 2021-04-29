#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    vector<int> arr;
    
    struct MST{
        int u, v, weight;
        MST(int U, int V, int W){
            u = U;
            v = V;
            weight = W;
        }
        bool operator<(MST mst)const{
          return weight < mst.weight;  
        }
    };
    
    int findParent(int x)
    {
        if(arr[x] < 0)
            return x;
        else
        {
            int y= x;
            while(arr[x] > 0)
                x=arr[x];
            arr[y] = x;
        }
        return x;
    }
    void Union(int p1 , int p2)
    {
        if(arr[p1] <= arr[p2])
        {
            arr[p2] = p1;
            arr[p1] = arr[p1] -2;
        }
        else
        {
            arr[p1] = p2;
            arr[p2] = arr[p2] -2;
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        arr.resize(V+1, -1);
        arr[0] = 0;
        vector<MST> edges;
        edges.reserve((V*(V-1))/2);
        set<pair<int, int>> uset;
        for(int i = 0; i < V; ++i){
            for(auto x : adj[i]){
                for(int j = 1; j < x.size(); ++j){
                    if(uset.find({min(i, x[0]), max(i, x[0])}) == uset.end()){
                        uset.insert({min(i, x[0]), max(i, x[0])});
                        // cout<<min(i, x[0])<<" "<<max(i, x[0])<<" "<<x[1]<<endl;
                        edges.push_back(MST(min(i, x[0]), max(i, x[0]), x[1]));
                    }
                }
            }
        }
        
        int cost = 0;
        vector<int> tree_id(V);
        vector<MST> result;
        for (int i = 0; i < V; i++)
            tree_id[i] = i;
        
        sort(edges.begin(), edges.end());
            
        for(int i = 0; i < edges.size(); ++i){
            // cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].weight<<endl;
            int p1 = findParent(edges[i].u);
            int p2 = findParent(edges[i].v);
            
            if(p1 != p2){
                cost += edges[i].weight;
                result.push_back(edges[i]);
                Union(p1, p2);
            }
        }
                
        return cost;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}



// Sample Input
// 3 3
// 0 1 5
// 0 2 1
// 1 0 5
// 1 2 3
// 2 1 3
// 2 0 1

// Output
// 4
  
