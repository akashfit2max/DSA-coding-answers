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
    vector<string>res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        helper(res,root,"");
        return res;
    }
    
    void helper(vector<string>&res, TreeNode* root, string path)
    {
        if(!root) return;
        
        if(!root->left && !root->right)
        {
            path += to_string(root->val);
            res.push_back(path);
            path.clear();
            return;
        }
        
        path += to_string(root->val) + "->";
        
        helper(res,root->left,path);
        helper(res,root->right,path);
    }
};