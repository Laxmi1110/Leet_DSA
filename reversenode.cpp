class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        int count = 0;
        
        // Check if at least k nodes exist
        while(curr && count < k){
            curr = curr->next;
            count++;
        }
        
        if(count == k){
            curr = reverseKGroup(curr, k); // reverse remaining list
            
            while(count--){
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        
        return head;
    }
};
