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
    pair<int,int> solve(TreeNode* root) {
        if(root == nullptr) {
            //{pick,not_pick}
            return {0,0};
        }
        pair<int,int> a = solve(root->left);
        pair<int,int> b = solve(root->right);

        return {root->val + a.second + b.second, max(a.first,a.second)+max(b.first,b.second)};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};