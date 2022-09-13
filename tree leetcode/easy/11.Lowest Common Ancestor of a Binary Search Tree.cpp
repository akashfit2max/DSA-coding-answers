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
        // if root is null return null
        if(root==nullptr) return nullptr;
        
        // there are 3 case
        // case 1 : p & q both are > root  ---> go right
        if(p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        // case 2 : p & q both are < root ---> go left
        else if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        // case 3 if both the above case are false we found the LCA
        else
        {
            return root;
        }
    }
};