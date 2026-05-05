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
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* curr = &dummy; 

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = (list1 ? list1 : list2);

        return dummy.next; 
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];

        int mid = l + (r - l) / 2;

        ListNode* list1 = merge(lists, l, mid);
        ListNode* list2 = merge(lists, mid + 1, r);

        return mergeTwo(list1, list2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        return merge(lists, 0, lists.size() - 1);
    }
};
