class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* before = beforeHead;

        ListNode* afterHead = new ListNode(0);
        ListNode* after = afterHead;

        while (head != NULL) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        // Important: end the after list
        after->next = NULL;

        // Connect both lists
        before->next = afterHead->next;

        return beforeHead->next;
    }
};
