#include <iostream> // Adj Matrix
#include <vector>
#include <queue>

using namespace std;

void BFS(int n , vector<vector<int>> G , int v)
{
    int visited[n],i;
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(v);
    cout<<"\nVisit\t"<<v;
    visited[v]=1;
    while(!q.empty())
    {
        v = q.front();
        for(i=0 ; i<n;i++)
        {
            if(!visited[i] && G[v][i] != 0)
            {
                q.push(i);
                visited[i]=1;
                cout<<"\nVisit\t"<<i;
            }
        }
        q.pop();
    }
    cout<<endl;
}

int main()
{
    int n;
    int startNode;
    cout<<"Enter number of vertices"<<endl;
    cin>>n;
    vector<vector<int>> G( n , vector<int>(n));
    for(int i=0 ; i<n; i++)
        for(int j=0 ; j<n ; j++)
            cin>>G[i][j];
    cout<<"Enter Starting Node"<<endl;
    cin>>startNode;
    BFS(n , G , startNode);
    
    return 0;
}



