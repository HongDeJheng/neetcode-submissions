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
        // Find the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;

        //                 slow
        //                   |
        //    0 -> 1 -> 2 -> 3 -> 4 -> 5
        // => 0 -> 1 -> 2 -> 3 -> 5 -> 4
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //                 slow prev
        //                   |    |
        //    0 -> 1 -> 2 -> 3 -> 5 -> 4
        // => 0 -> 5 -> 1 -> 4 -> 2 -> 3
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};
