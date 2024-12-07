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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp =head;
        ListNode* value = head;
    
        int size = 0;
        while(temp!=NULL){
            temp = temp->next;
           
            size++;
        }
        if(size==0) return head;
        k = k%size;
        while(value->next!=NULL){
            value = value->next;
        }
        int x = size-k-1;
        temp = head;
        for(int i=1;i<=x;i++){
            temp = temp->next;
            
        }
        value->next=head;
        head = temp->next;
        temp->next =NULL;

        return head;
    }
};