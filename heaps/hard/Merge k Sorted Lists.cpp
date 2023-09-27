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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto list : lists) {
            auto head = list;
            while(head) {
                int val = head->val;
                pq.push(val);
                head = head->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()) {
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            curr->next = temp;
            curr = curr->next;
        }

        return dummy->next;
    }
};