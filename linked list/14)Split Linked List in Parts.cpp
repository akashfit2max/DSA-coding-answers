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
     int countNodes(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = countNodes(head);
        int psize = n/k;
        int l = n%k;
        
        ListNode *curr = head, *prev=nullptr;
        
        vector<ListNode*>ans(k);
        
        for(int i=0;i<k;i++) {
            ans[i] = head;
            
            for(int j=0;j< psize + (i<l) ; j++) {
                prev=head;
                head = head->next;
            }
            
            if(prev) {
                prev->next = nullptr;
            }
        }
        return ans;
    }
};








https://leetcode.com/problems/split-linked-list-in-parts/