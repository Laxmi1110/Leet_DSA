class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != NULL) {
            // Check duplicates
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                
                // Skip all nodes with this value
                while (curr != NULL && curr->val == dupVal) {
                    curr = curr->next;
                }
                
                prev->next = curr; // remove duplicates
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};
