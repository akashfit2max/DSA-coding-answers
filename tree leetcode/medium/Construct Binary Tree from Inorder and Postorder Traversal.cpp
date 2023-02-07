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
     TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        if(in.size()!=po.size())
        return NULL;
        int n=po.size();
        map<int,int> mp;
        for(int i=0;i<n;++i)
        mp[in[i]]=i;
        TreeNode* root=x(in,0,n-1,po,0,n-1,n,mp);
        return root;
    }
   TreeNode* x(vector<int>& in,int ins,int ine,vector<int>& po,int pos,int poe,int n,map<int,int> &mp)
    {
        if(ins>ine || pos>poe)
        return NULL;
        TreeNode* root=new TreeNode(po[poe]);
        int inroot=mp[root->val];
        int numsleft=inroot-ins;
        root->left=x(in,ins,inroot-1,po,pos,pos+numsleft-1,n,mp);
        root->right=x(in,inroot+1,ine,po,pos+numsleft,poe-1,n,mp);
        return root;
    }
};