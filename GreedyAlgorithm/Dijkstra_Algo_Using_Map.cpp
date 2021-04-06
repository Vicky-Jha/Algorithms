#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<"Enter number of Vertices\n";
    int V;
    cin>>V;
    
    vector<vector<int>> G(V , vector<int> (V,0));
    vector<int> verticesCost(V,0);
    vector<bool> visited(V,0);
    cout<<"Enter adjacent matrix\n";
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            cin>>G[i][j];
        }
    }
    
    map<int, int> mp;
    mp.insert({0,0});
    while(!mp.empty()){
        pair<int, int> p = *mp.begin();
        mp.erase(mp.begin());
        visited[p.second] = 1;
        for(int i = 0; i < V; ++i){
            if(G[p.second][i] && !visited[i]){
               if(verticesCost[i] == 0){
                   verticesCost[i] = verticesCost[p.second] + G[p.second][i];
               }else{
                   verticesCost[i] = min(verticesCost[i],
                   verticesCost[p.second] + G[p.second][i]);
               }
               mp.insert({verticesCost[i],i});
            }
        }
    }
    for(int i = 0; i < V; ++i){
        cout<<verticesCost[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}

// input
// 9
// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0


// output
// 0 4 12 19 21 11 9 8 14 
