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
    void reorderList(ListNode* head) {

        // split list in half 
        ListNode* slow = head;
        ListNode* fast = head; 
        while (fast && fast->next) { 
            slow = slow->next;
            fast = fast->next->next; 
        } // slow now points to middle

        // reverse second half 
        ListNode* curr = slow->next; 
        slow->next = nullptr; // cut first list from second 
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        } // prev now points to head of reversed half 

        // stitch together 
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l2) { // l2 is always shorter or equal length
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
