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
class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(!root) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
public:
    vector<int>v;
    int i=0;
    BSTIterator(TreeNode* root) {
        inorder(root,v);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i != v.size();
    }
};

