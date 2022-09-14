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
    int pseudoPalindromicPaths (TreeNode* root) {
        // a number is palindrom if it has at most one odd occarance or no odd occarance
        // for ex : 521125 - all number have even freq hence palindrom
        //          12321  - one once odd occarance i.e is rest all appears one time
        
        // create a freq arrary to keep track on freq - [1-9]
        vector<int>freq(10,0);
        // to store the tolad count of plain seq
        int count=0;
        preorder(root,freq,count);
        
        return count;
    }
    
    void preorder(TreeNode* root, vector<int>&freq, int& count)
    {
        // base case
        if(!root) return;
        
        // count the freq
        freq[root->val]++;
        
        // call the left and right chil
        preorder(root->left,freq,count);
        preorder(root->right,freq,count);
        
        // when we reach a leaf node
        if(!root->left && !root->right)
        {
            // to count the odd freq
            int flag = 0;
            for(int i=1; i<=9; i++)
            {
                // count the freqq of numbers which are 
                if(freq[i]%2 != 0) flag++;
            }
            
            // if freq is 1 or 0 its palindrom
            if(flag==0 || flag==1) count++;
        }
        
        // backtract and reduce the freq 
        freq[root->val]--;
    }
};