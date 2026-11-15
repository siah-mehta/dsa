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
        if (!head) return nullptr;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                Node* tail = childHead;

                while (tail->next) {
                    tail = tail->next;
                }

                if (nextNode) {
                    tail->next = nextNode;
                    nextNode->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
