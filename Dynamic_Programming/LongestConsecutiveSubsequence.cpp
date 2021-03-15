#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
int longestConsecutive(vector< int >& nums) {
         int res = 0 ;
        unordered_set < int > s(nums.begin(), nums.end());
         for ( int val: nums) {
             if (!s.count(val)) continue;
            s.erase(val);
            int pre = val- 1 , next = val + 1 ;
             while (s.count(pre)) s.erase(pre-- );
             while (s.count(next)) s.erase(next++ );
            res = max(res, next-pre- 1 );
        }
        return res;
    }
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  vector<int> v = {0,3,7,2,5,8,4,6,0,1};
  cout<<longestConsecutive(v)<<endl;
  return 0;
}
