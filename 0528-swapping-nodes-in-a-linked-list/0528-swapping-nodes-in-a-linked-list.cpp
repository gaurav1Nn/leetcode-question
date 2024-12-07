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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b = head;
        int size=0;
        while(a!=NULL){
            a = a->next;
            size++;
        }
        a = head;
        for(int i=1;i<k;i++){
            a= a->next;
        }
        int m = size-k+1;
        for(int i=1;i<m;i++){
            b= b->next;
        }
        ListNode* temp = head;
        swap(a->val,b->val);
        return head;

    }
};