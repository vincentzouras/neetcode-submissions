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
private: 
    struct Comparator {
        bool operator()(ListNode* a, ListNode* b) { 
            return a->val > b->val; // lower priority if true, so a is lower, therefore min
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> min_heap; 

        // Add head of each list to min heap
        for (auto head : lists) {
            if (head) min_heap.push(head);
        }

        ListNode dummy;
        ListNode* result = &dummy;

        while (!min_heap.empty()) {
            ListNode* smallest = min_heap.top();
            min_heap.pop();

            result->next = smallest;
            result = result->next;

            // If that list had more elements, push next onto heap
            if (smallest->next) {
                min_heap.push(smallest->next);
            }
        }

        return dummy.next;

        /*
        We have k sorted linked lists with N total nodes

        Each node ends up being inserted once, so we perform N heap pushes
        where each heap push costs us log k, since we can only have 
        at most k (one element from each list) in the heap at a time

        O(N log k)
        */
    }
};
