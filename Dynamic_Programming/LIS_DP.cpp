#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
int LengthOfLIS(int arr[], int n){
  vector<int> LIS(n, 0);
  int maxLen = 1;
  LIS[0] = 1;
  for(int i = 1; i < n; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[j] < arr[i] && LIS[j] > LIS[i])
        LIS[i] = LIS[j];
    }
    LIS[i]++;
    maxLen = max(maxLen, LIS[i]);
  }
  return maxLen;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int arr[] = {3, 5, 2, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<LengthOfLIS(arr, n)<<endl;
  return 0;
}
