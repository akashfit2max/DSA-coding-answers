/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        // to store the parent of each node using dfs traversal
        
        mark_parent(root,parent); // <(5,3) (1,3) (6,5) (2,5)...>
        
        
        unordered_map<TreeNode*,bool>visited;
        // to check if we have already visited the node
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int lvl = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            if(lvl++ == k) break;
            
            for(int i=0; i<s; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
                
            }
        }
        
        
        vector<int>ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        
        return ans;
    }
    
    
    void mark_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent)
    {
        // dfs traversal and store parent
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
};