#define INFINITY 9999
#include <iostream>

#define MAX 10

using namespace std;

class graph
{
    int G[MAX][MAX];
    int n;
public:
    graph()
    {     int i , j;
        cout<<"\nEnter No of Vertices :";
        cin>>n;
        cout<<"\nEnter the adjacency matrix : ";
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
                cin>>G[i][j];
}
//    void readgraph();
    void printgraph();
    void topological();
};
//void graph ::  readgraph()
//{
//    int i , j;
//    cout<<"\nEnter No of Vertices :";
//    cin>>n;
//    cout<<"\nEnter the adjacency matrix : ";
//    for(i=0 ; i<n ; i++)
//        for(j=0 ; j<n ; j++)
//            cin>>G[i][j];
//}
void graph:: printgraph()
{
    int i,j;
    for(i=0 ; i<n ;i++)
    {
        cout<<"\n";
        for(j=0 ; j<n ; j++)
            cout<<" "<<G[i][j];
    }
}
void graph:: topological()
{
    int visited[MAX] , indegree[MAX];
    int i,j;
    //initialize
    for(i=0 ; i<n ; i++)
    {
        visited[i]=0;
        indegree[i]=0;
        for(j=0 ;j<n ; j++)
            if(G[j][i] != 0)
                indegree[i]++;
    }
    cout<<"\n Topological Ordering sequence : \n";
    for(i=0 ;i<n ; i++)
    {//locate a node with indegree =0
        j=0;
        while(j<n)
        {
            if(visited[j] == 0 && indegree[j] == 0)
            {
                cout<<" "<<j;
                //decrement the indegree of nodes adjae=cent to j
                visited[j]=1;
                for(int k=0;k<n;k++)
                if(G[j][k] != 0)
                    indegree[k]--;
                break;
            }
            j++;
        }
        if(j == n)
        {
            cout<<"\n Graph has a cycle : ";
            break;
        }
    }
}
int main()
{
    graph g;
//    g.readgraph();
    g.topological();
    return 0;
}
//
//0 0 1 1 0
//1 0 0 1 0
//0 0 0 0 0
//0 0 1 0 1
//0 0 0 0 0
