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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return dfs(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
    
    
    TreeNode* dfs(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd)
    {
        if(preStart > preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        
        if(preStart == preEnd) return root;
        
        int postIndex = postStart;
        
        while(post[postIndex] != pre[preStart+1]) postIndex++;
        
        int len = postIndex-postStart+1;
        
        root->left = dfs(pre,preStart+1, preStart+len, post, postStart, postEnd);
        root->right = dfs(pre,preStart+len+1,preEnd, post, postIndex+1, postEnd-1);
        
        return root;
        
    }
};
