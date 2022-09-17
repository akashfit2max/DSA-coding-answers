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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        // base condition
        
        queue<TreeNode*>q;
        // to store the nodes in each lvl
        
        q.push(root);
        // push the root node
        
        vector<int>ans;
        // to store answer
        
        while(!q.empty())
        {
            int s = q.size();
            
            // loop for the size of the queue and take the last element
            for(int i=0; i<s; i++)
            {
                TreeNode* curr = q.front();
                // pick the current node from the queue if it is last node in the current lvl add it in ans vector;
                if(i==(s-1)) ans.push_back(curr->val);
                
                q.pop();
                // remove the element from the queue
                
                // add its left and right child if exist
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                
            }
        }
        
        return ans;
    }
};