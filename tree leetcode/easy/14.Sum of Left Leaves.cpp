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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        int sum=0;
        sumLeft(root,sum,false);
        return sum;
    }
    
    int sumLeft(TreeNode* root, int& sum, bool flag)
    {
        if(!root) return 0;
        
        if(!root->left && !root->right && flag)
        {
            sum+=(root->val);
            return sum;
        }
        sumLeft(root->left,sum,true);
        sumLeft(root->right,sum,false);
        
        return sum;
    }
};