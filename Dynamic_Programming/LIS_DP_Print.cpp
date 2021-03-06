#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
int LengthOfLIS(int arr[], int n){
  vector<int> LIS[n];
  pair<int, int> maxSP = {1,0};
  LIS[0].push_back(arr[0]);
  for(int i = 1; i < n; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
        LIS[i] = LIS[j];
    }
    LIS[i].push_back(arr[i]);
    maxSP = max(maxSP, {LIS[i].size(), i});
  }
  for(int x : LIS[maxSP.second]) cout<<x<<" ";
  cout<<endl;
  return maxSP.first;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int arr[] = {3, 5, 2, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<LengthOfLIS(arr, n)<<endl;
  return 0;
}
