/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if we find the node or we reach the end return the node
        if(root==nullptr || root==p || root==q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // we didn't found in right
        if(right==nullptr) return left;
        
        else if(left==nullptr) return right;
        // we found the node in the right
        
        else return root;
        // both left and right we found do we return the root
    }
};