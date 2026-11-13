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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prevTail = nullptr;
        int count{};

        while (end) {
            end = end->next;
            ++count;

            if (count == k) {
                count = 0;
                
                ListNode* currTail = start;
                ListNode* newHead = reverse(start, end);

                if (prevTail) {
                    prevTail->next = newHead;
                }
                else {
                    head = newHead;
                }

                prevTail = currTail;
                start = end;
            }
        }

        return head;
    }

private:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        start->next = end;
        return prev;
    }
};
