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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempa = a;
        ListNode* tempb = b;
        ListNode* c = new ListNode(100);
        ListNode* tempc = c;
        while(tempa!=NULL && tempb!=NULL){
            if(tempa->val<=tempb->val){
                ListNode* t = new ListNode(tempa->val);
                tempc->next= t;
                tempc = t;
                tempa=tempa->next;

            }
            else{
               ListNode* t = new ListNode(tempb->val);
                tempc->next= t;
                tempc = t;
                tempb=tempb->next;  
            }

        }
        if(tempa==NULL){
            tempc->next=tempb;
        }
        else{
            tempc->next = tempa;
        }
        return c->next;
    }
};