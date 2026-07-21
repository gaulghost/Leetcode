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
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* start1 = l1;
        ListNode* start2 = l2;
        int carry = 0;
        while(start1 != NULL || start2 != NULL){
            int add =0;
            if(start1 == NULL) add = start2->val + carry;
            if(start2 == NULL) add = start1->val + carry;
            if(start2 != NULL && start1 != NULL) add = start2->val + start1->val + carry;
            carry = 0;
            if(add>9) carry = 1;
            ListNode* temp = new ListNode(add%10);
            cur->next = temp;
            cur = cur->next;
            if(start1 != NULL)start1 = start1->next;
            if(start2 != NULL)start2 = start2->next;
        }
        if(carry == 1){
            ListNode* last = new ListNode(1);
            cur->next = last;
            cur->next->next = NULL;
        }
        else cur->next = NULL;
        return head->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna