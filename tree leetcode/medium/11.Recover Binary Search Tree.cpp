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
private:
    TreeNode* first;
    TreeNode* middel;
    TreeNode* last;
    TreeNode* prev;
    
private:
    
    void inorder(TreeNode* root)
    {
        if(!root) return ;
        
        inorder(root->left);
        
        // if the prev is not null the curr root val is less than prev then it is the first violation
        if(prev != nullptr && (root->val < prev->val))
        {
            if(first==nullptr)
            {
                first = prev;
                middel = root;
            }
            else
            {
                last = root;
            }
        }
        
        
        prev = root;
        
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first=middel=last=nullptr;
        // we set this to INT_MIN as it is taken as leftmost node
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        if(first && last) swap(first->val,last->val);
        else if(first && middel) swap(first->val,middel->val);
    }
};