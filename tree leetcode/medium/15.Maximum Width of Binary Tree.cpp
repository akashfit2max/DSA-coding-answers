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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long int>>q;
        // initially at index 0
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int s = q.size();
            // the min index in the paticular lvl
            long long int currmin = q.front().second;
            // to get the first and lst element at a lvl
            int leftmost, rightmost;
            for(long long int i=0; i<s; i++)
            {
                // to prevent integer overflow
                long long int currid = q.front().second - currmin;
                TreeNode* curr = q.front().first;
                q.pop();
                
                if(i==0) leftmost = currid;
                if(i==s-1) rightmost = currid;
                
                if(curr->left)
                {
                    q.push({curr->left, 2*currid+1});
                }
                if(curr->right)
                {
                    q.push({curr->right, 2*currid+2});
                }
            }
            ans = max(ans, rightmost - leftmost + 1);
        }
        return ans;
    }
};