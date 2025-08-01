/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*  tempa = headA;
        ListNode* tempb = headB;
        int sizea = 0;
        int sizeb = 0;
        while(tempa!=NULL){
            tempa = tempa->next ;
            sizea++;
        }
        while(tempb!=NULL){
            tempb = tempb->next ;
            sizeb++;
        }        
        tempa = headA;
        tempb = headB;
        int diff = 0;
        if(sizea>sizeb){
            diff = sizea - sizeb;
            for(int i=1;i<=diff;i++){
                tempa = tempa->next;
            }
            while(tempa!=tempb){
                tempa = tempa->next;
                tempb = tempb->next;
            }
            return tempa;
        }
        if(sizea<=sizeb){
            diff = sizeb-sizea;
            for(int i=1;i<=diff;i++){
                tempb = tempb->next;;
            }
            while(tempa!=tempb){
                tempa = tempa->next;
                tempb = tempb->next;
            }
            return tempa;
        }
        return tempa;
    }
};