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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        int length = 0;
        ListNode* curr = head; 
        while (curr) {
            curr = curr->next;
            length++;
        }

        length -= n; 

        curr = head;
        ListNode* prev = &dummy;
        for (; length > 0; length--) {
            prev = curr;
            curr = curr->next;
        }

        // remove curr node 
        prev->next = curr->next; 

        return dummy.next;
    }
};
