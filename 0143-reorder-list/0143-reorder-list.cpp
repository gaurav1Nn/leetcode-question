// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
// ListNode* reverselist(ListNode* head){
//         ListNode *prev=NULL,*curr=head,*Next = head;
//         while(curr){
//             Next = curr->next;
//             curr->next =prev;
//             prev = curr;
//             curr = Next;
//         }
//         return prev;
//     };
//     void reorderList(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         // finding left middle
//         while(fast->next!=NULL && fast->next->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         ListNode* b = reverselist(slow->next);
//         ListNode* a = head;
//         ListNode* c = new ListNode(100);
//         ListNode* tempc = c;
//         ListNode* tempa = a;
//         ListNode* tempb =b ;

//         while(tempa && tempb){
//             tempc->next = tempa;
//             tempa = tempa->next;
//             tempc = tempc->next;

//             tempc->next = tempb;
//             tempb= tempb->next;
//             tempc=tempc->next;
//         }
//         tempc->next =tempa;
//         head = c->next;

//     }
// };
class Solution {
public:
    ListNode* reverselist(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *Next = head;
        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverselist(slow->next);
        slow->next = NULL; // Terminate the first half of the list

        // Step 3: Merge the two halves
        ListNode* firstHalf = head;
        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
