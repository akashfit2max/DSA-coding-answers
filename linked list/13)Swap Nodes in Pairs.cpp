https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) {
            return head;
        }
        
        ListNode *p = head, *newstart = p->next;
        while(1) {
            ListNode *q = p->next;
            ListNode *temp = q->next;
            q->next = p;
            if(temp==nullptr || temp->next==nullptr) {
                p->next = temp;
                break;
            }
            p->next = temp->next;
            p=temp;
        }
        return newstart;
    }
};