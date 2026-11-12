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
        ListNode* left = &dummy;
        ListNode* right = head;

        // Make distance from left to right = n
        while (n-- > 0) {
            right = right->next;
        }

        // Now move right to the end, and we'll find the nth from the end at "left"
        while (right) {
            left = left->next;
            right = right->next;
        }

        ListNode* remove = left->next;
        left->next = left->next->next;
        head = dummy.next;
        delete remove;
        return head;
    }
};
