Copy List with Random Pointer



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
//         inserting new node in between
        Node *curr = head;
        while(curr) {
            Node * temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr=temp;
        }
        
        curr = head;
        // setting random pointer
        while(curr!=nullptr) {
            if(curr->next!=nullptr) {
                curr->next->random = (curr->random!=nullptr) ? curr->random->next : nullptr;
            }
            curr = curr->next->next;
        }
        
//         removing the links
        Node * ans = new Node(0);
        Node *helper = ans;
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; // Since first node is a dummy node
    }
    
};