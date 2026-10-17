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
    ListNode* mergeSortedLists(ListNode* head1c, ListNode* head2c){
        ListNode* start = new ListNode(0);
        ListNode* cur = start;
        ListNode *head1 = head1c, *head2 = head2c;
        while(head1 && head2){
            if(head1->val <= head2->val){
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if(head1) cur->next = head1;
        if(head2) cur->next = head2;
        return start->next;
    }

    ListNode* recur(int i, int j, vector<ListNode*>& lists){
        if(i == j) return lists[i];
        int mid = (i+j)/2;
        ListNode* left = recur(i, mid, lists);
        ListNode* right = recur(mid+1, j, lists);
        return mergeSortedLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int i=0, j=lists.size()-1;
        ListNode* ans = recur(i,j,lists);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna