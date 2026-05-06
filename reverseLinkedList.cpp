class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Move prev to (left-1) position
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 3: Reverse the sublist
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};
