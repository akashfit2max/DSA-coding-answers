https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/



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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==nullptr) {
            return nullptr;
        }
        unordered_map<int,ListNode*>mp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        int presum=0;
        while(head!=nullptr) {
            presum+=head->val;
            if(mp.find(presum)!=mp.end()) {
                int sum=presum;
                ListNode *start = mp[sum];
                while(start!=nullptr && start!=head) {
                    start = start->next;
                    sum+=start->val;
                    if(start!=head) {
                        mp.erase(sum);
                    }
                }
                mp[presum]->next = head->next;
            }
            else {
                mp[presum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};