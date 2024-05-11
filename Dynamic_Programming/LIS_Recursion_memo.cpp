// Recursive DFS solution
// Time complexity O(n.(n pow n))
class Solution {
public:
    int maxLen = 1;
    void helper(vector<int>& nums, int idx, int count) {
        maxLen = max(maxLen, count);
        for(int i = idx; i < nums.size() - 1; ++i) {
            if(nums[idx] < nums[i + 1]) {
                helper(nums, i + 1, count + 1);
            }
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            helper(nums, i, 1);
        }
        return maxLen;
    }
};


// Top down approach (recursive + memo)
// Time complexity: O(N*N)
// Space complexity: O(N)
class Solution {
public:
    vector<int> memo;  // Used for memoization

    int helper(vector<int>& nums, int idx) {
        // If the result from this index is already computed, return it
        if (memo[idx] != -1) return memo[idx];

        int maxLen = 1;  // At least the current element itself
        for (int i = idx + 1; i < nums.size(); ++i) {
            if (nums[idx] < nums[i]) {
                maxLen = max(maxLen, 1 + helper(nums, i));  // Extend the subsequence
            }
        }

        memo[idx] = maxLen;  // Store the computed result
        return maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        memo.resize(nums.size(), -1);
        int globalMax = 1;  // Minimum is 1 if the array is not empty

        // Compute LIS starting from each index and find the maximum
        for (int i = 0; i < nums.size(); ++i) {
            globalMax = max(globalMax, helper(nums, i));
        }

        return globalMax;
    }
};
