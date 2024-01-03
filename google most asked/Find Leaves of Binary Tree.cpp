class Solution {
    vector<vector<int>> ans;  // ans[i] stores all nodes with a level of i
   public:
    int dfs(TreeNode* u) {    // dfs function returns the level of current node
        if (u == nullptr) {
            return -1;
        }
        int leftLevel = dfs(u->left);
        int rightLevel = dfs(u->right);
        int currentLevel =
            max(leftLevel, rightLevel) + 1;  // calculate level of current node
        while (ans.size() <=
               currentLevel) {  // create more space in ans if necessary
            ans.push_back({});
        }
        ans[currentLevel].push_back(u->val);
        return currentLevel;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};