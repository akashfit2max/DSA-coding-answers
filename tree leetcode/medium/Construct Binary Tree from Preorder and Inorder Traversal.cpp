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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, 
                        map<int,int>& mp) 
                        {
                            if(inStart > inEnd || preStart > preEnd) return nullptr;

                            TreeNode* root = new TreeNode(preorder[preStart]);

                            int inRoot = mp[root->val];
                            int numLeft = inRoot-inStart;

                            root->left = buildTree(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,mp);
                            root->right = buildTree(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);

                             return root;
                        }
                       
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

};