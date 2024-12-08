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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        ListNode* curr =head;
        ListNode* Next =head;
        ListNode* tempt =head;
        while(Next){ //  loop wil conitinue till Next!=NULL
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            
        }
        return prev;
        
    }
};