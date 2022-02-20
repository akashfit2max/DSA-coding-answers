https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans;
        ListNode* slow = head;   //t1
        ListNode* fast = head;    //t2
    
        for(int i=0;i<n;++i)
        {
            fast = fast->next;
        }

        if(fast == NULL) 
        {
            ans = head->next;
            delete head;
            return ans;
        }

        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next;
       
        // ListNode* temp = slow->next;
        // slow->next = temp->next;
        // delete temp;
        
        return head;
        }
};