/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>>res;

    int getHeight(TreeNode * root) {
        if(root == nullptr) return -1;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int lvl = 1 + max(lh,rh);

        if(res.size() == lvl) res.push_back({});

        res[lvl].push_back(root->val);

        return lvl;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        getHeight(root);
        return res;
    }
};