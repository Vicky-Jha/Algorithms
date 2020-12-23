#include<iostream>
#include<vector>
#define R 3
#define C 3
using namespace std;

int min(int x, int y, int z)
{
    if (x < y)
        return (x < z)? x : z;
    else
        return (y < z)? y : z;
}

int minCost(vector<vector<int>> cost , int m , int n)
{
    
    if (n < 0 || m < 0)
        return INT_MAX;
    else if(m == 0 && n==0)
        return cost[0][0];
    else
        return min(minCost(cost, m-1, n-1),minCost(cost, m, n-1),minCost(cost, m-1, n))+cost[m][n];
}


int main()
{
    vector<vector<int>> cost = { {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3} };
    cout<< minCost(cost, 2, 2)<<endl;
    return 0;
}
