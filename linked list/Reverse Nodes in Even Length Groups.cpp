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
    // function to reverse nodes
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        // iterate to get the groups
        for(int len = 1; len <= 1e5 && head ; len++) {
            // to keep track of end node in a grp
            ListNode* tail = head;
            ListNode* next_head;

            // making grps
            int curr_len = 1;
            while(curr_len < len && tail && tail->next) {
                tail = tail->next;
                curr_len++;
            }

            next_head = tail->next;

            if(curr_len % 2 == 0) {
                tail->next = nullptr;
                prev->next = reverseList(head);
                head->next = next_head;
                prev = head;
                head = next_head;
            }
            else {
                //odd len grp - go to next grp
                prev = tail;
                head = next_head;
            }
        }
        return dummy->next;
    }
};