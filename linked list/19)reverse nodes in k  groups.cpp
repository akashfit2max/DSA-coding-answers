https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *curr = dummy, *nex = dummy;
        int c =0 ;
        while(curr->next!=nullptr) {
            curr = curr->next;
            c++;
        }
        
        while(c>=k) {
            curr = pre->next;
            nex = curr->next;
            for(int i=1;i<k;i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            pre = curr;
            c-=k;
        }
        
        return dummy->next;
    }
};