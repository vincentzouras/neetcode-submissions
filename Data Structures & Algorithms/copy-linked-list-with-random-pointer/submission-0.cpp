/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node *copy = &dummy;
        unordered_map<Node*, Node*> nodes; // old -> new

        Node* curr = head;
        while (curr != nullptr) {
            Node* node = new Node(curr->val);
            nodes[curr] = node;
            copy->next = node;

            copy = copy->next;
            curr = curr->next;
        }

        while (head != nullptr) {
            nodes[head]->random = nodes[head->random];
            head = head->next;
        }

        return dummy.next;
    }
};
