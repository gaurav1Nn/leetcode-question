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
 ListNode* reverselist(ListNode* head){
        ListNode *prev=NULL,*curr=head,*Next = head;
        while(curr){
            Next = curr->next;
            curr->next =prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    };
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b =  NULL;
        ListNode* c =  NULL;
        ListNode* d = NULL;
        int n = 1;

        while(temp){
            if(n==left-1) a =temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right +1) d= temp;
            temp = temp->next;
            n++;
        }
        if(a) a->next = NULL;
        if(c)c->next = NULL;
        c= reverselist(b);
        if(a)a->next = c;
        b->next = d;
        if(a) return head;
        else return c;
    };
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap =1;
        while(temp && temp->next){
            int remlen = 0;
            ListNode* t = temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remlen++;
            }
            if(remlen<gap+1)gap =remlen -1;
            if(gap%2!=0)reverseBetween(temp,2,2+gap);
        
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++){
                temp=temp->next;
            }
        }
        return head;
    }
};