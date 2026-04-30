class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                // remove duplicate node
                curr->next = curr->next->next;
            } else {
                // move forward
                curr = curr->next;
            }
        }

        return head;
    }
};
