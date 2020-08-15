
class Solution {
public:
    int res = 0;
    
    void dfs(TreeNode* node, int L, int R) {
        if (!node) return;
        
        if (node -> val <= R && node -> val >= L) res += node -> val;
        
        dfs(node -> left, L, R);
        dfs(node -> right, L, R);
        
        return;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        
        dfs(root, L, R);
        
        return res;
    }
};//dfs traversal of binary search tree
