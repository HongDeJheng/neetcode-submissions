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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        ListNode *ptr1 = list1, *ptr2 = list2;

        while (ptr1 || ptr2) {
            if (ptr1 && ptr2) {
                if (ptr1->val <= ptr2->val) {
                    head->next = new ListNode(ptr1->val);
                    ptr1 = ptr1->next;
                }
                else {
                    head->next = new ListNode(ptr2->val);
                    ptr2 = ptr2->next;
                }
            }
            else if (ptr1) {
                head->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;

            }
            else {
                head->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }

            head = head->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
