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

    TreeNode* findParent(TreeNode* root, int start, map<TreeNode*,TreeNode*>&mp) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start) res = curr;
            if(curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return res;
    }

    int findMaxDist(map<TreeNode*,TreeNode*>&parent, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int>vis;
        vis[target] = 1;
        int maxi = 0;
        while(!q.empty()) {
            int size = q.size();
            int f = 0;
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]) {
                    f=1;
                    vis[curr->left] = 1;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]) {
                    f=1;
                    vis[curr->right] = 1;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]]) {
                    f=1;
                    vis[parent[curr]] = 1;
                    q.push(parent[curr]);
                }
            }
            if(f) maxi++;
        }
        return maxi;
    }
 
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode* target = findParent(root,start,mp);
        int maxi = findMaxDist(mp,target);
        return maxi;
    }
};
