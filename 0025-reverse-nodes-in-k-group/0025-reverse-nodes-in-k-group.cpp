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
    ListNode* reverseList(ListNode* head){
        if(head == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* fut = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fut;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head == NULL || head->next == NULL) return head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* nprev = prev, *cur = head;
        while(cur){
            int kt = k;
            ListNode* start = cur, *end = cur;
            while(end && kt>1){
                end = end->next;
                kt--;
            }
            if(end == NULL) break;
            ListNode* fut = end->next;
            end->next = NULL;
            nprev->next = reverseList(start);
            start->next = fut;
            nprev = start;
            cur = fut;
        }
        return prev->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna