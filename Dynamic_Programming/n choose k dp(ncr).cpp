#include <iostream>
#include <vector>
using namespace std;
vector < vector< int >> dp;
int bexp(int n , int k)
{
    if(dp[n][k] != -1)
        return dp[n][k];
    if( n == k)
        return 1;
    else if(n < k)
        return 0;
    else if(k == 0)
        return 1;
    else  return dp[n][k] = bexp(n-1,k) + bexp(n-1,k-1);
}
int main() {
    int n , k;
    cin>>n>>k;
    dp.resize(n+1 , vector<int> (k+1,-1));
    cout<<bexp(n,k)<<"\n";
    return 0;
}
