/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        
        //store to root to return 
        Node* curr = root;
        
        // while the left pointer is not null traversein lvl order
        while(curr->left != nullptr)
        {
            // store the curr node as we have to move the curr to curr->left at the end
            Node* temp = curr;
            while(curr != nullptr)
            {
                // 1->2-> = 3
                curr->left->next = curr->right;
                curr->right->next = curr->next == nullptr ? nullptr : curr->next->left;
                curr = curr->next;
            }
            curr = temp->left;
        }
        
        return root;
    }
};