class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        
        // Continue while either list has elements OR there's a carry
        while(temp1 || temp2 || carry) {
            int sum = carry;
            
            // Add values if nodes exist
            if(temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            current->next = newNode;
            current = current->next;
        }
        
        return dummy->next;
    }
};