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
    
    TreeNode* inorder(TreeNode* root, int l, int r, vector<int>&nums)
    {
        if(l<=r)
        {
            int m = (l+r)/2;
            root = new TreeNode(nums[m]);
            root->left = inorder(root,l,m-1,nums);
            root->right = inorder(root,m+1,r,nums);
            return root;
        }
        
        return nullptr;
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        return inorder(root,0,nums.size()-1,nums);
    }
};