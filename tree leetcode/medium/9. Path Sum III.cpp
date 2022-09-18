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
    int count = 0;
    int pathSum(TreeNode* root, int ts) {
        if(root==nullptr) return 0;
        unordered_map<long long int,long long int>mp;
        //map to store ther curr_sum and its frequency
        mp.insert({0,1});
        helper(root,0,ts,mp);
        return count;
    }
    
    void helper(TreeNode* root, long long int sum, int ts, unordered_map<long long int,long long int>& mp)
    {
        if(!root) return;
        
        sum += root->val;
        
        if(mp.count(sum-ts))
        {
            count += mp[sum-ts];
        }
        mp[sum]++;
        
        helper(root->left,sum,ts,mp);
        helper(root->right,sum,ts,mp);
        
        mp[sum]--;
        //backtrack
        return;
    }
};