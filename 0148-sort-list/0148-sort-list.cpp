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
    // Merge two sorted lists
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0); // Dummy node to simplify logic
        ListNode* temp = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes from either `a` or `b`
        temp->next = (a != nullptr) ? a : b;

        return dummy.next;
    }

    // Sort the linked list
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has a single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; // Break the list into two halves

        // Recursively sort the two halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the two sorted halves
        return merge(left, right);
    }
};
