//Didn't understood the code

#include <iostream>
#include <vector>
using namespace std;

int memo[101][101];
int findMinPath(vector<vector<int> >& V, int r, int c) {
    int R = V.size();
    int C = V[0].size();
    if (r >= R || c >= C) return 100000000; // Infinity
    if (r == R - 1 && c == C - 1) return 0;
    if (memo[r][c] != -1) return memo[r][c];
    memo[r][c] =  V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
    return memo[r][c];
}

int main()
{
    
    vector<vector<int>> V = {
        {1,1,1},{1,1,1},{1,1,1}
    };
memset(memo, -1, sizeof(memo));
    cout<<findMinPath(V, 0, 0)<<endl;
    return 0;
}
