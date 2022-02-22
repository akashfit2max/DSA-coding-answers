https://leetcode.com/problems/insertion-sort-list/


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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(1000);
        
        while(head) {
            ListNode* temp = dummy;
//          to store the address of net pointer to head;
            ListNode* nextp = head->next;
            
            while(temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head=nextp;
        }
        
        return dummy->next;
    }
};