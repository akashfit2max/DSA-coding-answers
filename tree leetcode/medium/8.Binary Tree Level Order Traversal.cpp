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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr) {
            return res;
        }
        
        queue<TreeNode*>q;
        q.push(root);   //push the root node
        
        while(!q.empty()) {
            vector<int>l;
            int len = q.size();
            for(int i=0;i<len;i++) { // iterate throught each level and push in  a vector
                TreeNode * curr = q.front();
                l.push_back(curr->val);
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
                q.pop();
            }
            res.push_back(l);
        }
        return res;
    }
};