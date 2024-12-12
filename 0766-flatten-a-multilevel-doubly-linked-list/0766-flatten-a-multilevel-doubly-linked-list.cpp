/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *head1 = head, *ptr = head, *last;
        if (head == NULL) {
            return NULL;
        }
        vector<Node*> v;
        while (ptr != NULL) {
            if (ptr->child != NULL) {
                v.push_back(ptr->next);

                ptr->next = ptr->child;
                ptr->child->prev = ptr;
                ptr->child = NULL;
            }
            last = ptr;
            ptr = ptr->next;
        }
        int i = v.size() - 1;
        while (i >= 0) {
            if (v[i] != NULL) {
                last->next = v[i];
                v[i]->prev = last;

                while (v[i] != NULL) {
                    // cout<<v[i]->val<<" ";
                    ptr = v[i];
                    ptr->next = v[i]->next;
                    last = ptr;
                    v[i] = v[i]->next;
                }
                // cout<<endl;
            }
            i--;
        }

        return head1;
    }
};