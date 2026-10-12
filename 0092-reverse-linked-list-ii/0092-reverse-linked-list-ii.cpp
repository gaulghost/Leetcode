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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        int lft = left, rgt = right;
        ListNode* prev = new ListNode(0);
        ListNode* fprev = prev;
        prev->next = head;
        while(lft > 1){
            prev = prev->next;
            lft--, rgt--;
        }
        ListNode* nprev = NULL;
        ListNode* cur = prev->next;
        ListNode* mhead = prev->next;
        while(rgt > 1){
            ListNode* fut = cur->next;
            cur->next = nprev;
            nprev = cur;
            cur = fut;
            rgt--;
        }
        ListNode* nfut = cur->next;
        cur->next = nprev;
        nprev = cur;
        cur = nfut;
        prev->next = nprev;
        mhead->next = cur;
        return fprev->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna