https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
//     find the len of the ll
    int len(ListNode *l) {
        int s=0;
        while(l!=nullptr) {
            s++;
            l=l->next;
        }
        return s;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int back = len(curr)-k+1;
        
        ListNode *p1=head,*kt=nullptr,*bkt=nullptr;
        while(--k) {
            p1 = p1->next;
        }
        
        kt = p1;
        p1=head;
        
        while(--back) {
            p1 = p1->next;
        }
        bkt=p1;
        
        swap(kt->val,bkt->val);
        return head;
    }
};