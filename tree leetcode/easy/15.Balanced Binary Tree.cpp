/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // find the lh , rh and if abs(lh-rh) > 1 return -1;
        return dfs(root) != -1;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        // find left height
        int lh = dfs(root->left);
        if(lh==-1) return -1;
        
        //find right height
        int rh = dfs(root->right);
        if(rh==-1) return -1;
        
        if(abs(lh-rh) > 1) return -1;
        
        
        return max(lh,rh)+1;
    }
};