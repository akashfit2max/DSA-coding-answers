https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *newhead = new ListNode(0);
        ListNode *curr = newhead;
        while(l1 || l2) {
            int vl1 = l1 ? l1->val : 0;
            int vl2 = l2 ? l2->val : 0;
            int sum = vl1+vl2+carry;
            carry = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            
            if(l1) {
                l1=l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        if(carry>0) {
            curr->next = new ListNode(carry);
        }
        return newhead->next;
    }
};