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
    int count=0;
    
    void helper(TreeNode* root, int gr)
    {
        if(!root) return;
        
        if(gr <= root->val)
        {
            gr = max(gr,root->val);
            count++;
        }
        
        helper(root->left,gr);
        helper(root->right,gr);
    }
    int goodNodes(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        int gr = root->val;
        helper(root,gr);
        return count;
    }
};