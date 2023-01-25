/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        queue<TreeNode*>q;
        q.push(root);
        string path = "";
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(curr == nullptr) {
                path.append("#,");
            }
            else {
                path.append(to_string(curr->val)+",");
            }
            if(curr != nullptr) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout<<path;
        return path;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        queue<TreeNode*>q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#") {
                curr->left = NULL;
            }
            else {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }

            getline(s,str,',');
            if(str == "#") {
                curr->right = NULL;
            }
            else {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));