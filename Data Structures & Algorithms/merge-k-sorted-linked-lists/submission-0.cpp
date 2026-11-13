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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        deque<ListNode*> dq(lists.begin(), lists.end());

        while (dq.size() > 1) {
            auto l1 = dq.front();
            dq.pop_front();
            auto l2 = dq.front();
            dq.pop_front();
            dq.push_back(merge2Lists(l1, l2));
        }

        return dq.front();
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        else if (!l1) {
            return l2;
        }
        else if (!l2) {
            return l1;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val <= l2->val) {
                    ptr->next = l1;
                    l1 = l1->next;
                }
                else {
                    ptr->next = l2;
                    l2 = l2->next;
                }
            }
            else if (l1) {
                ptr->next = l1;
                break;
            }
            else {
                ptr->next = l2;
                break;
            }

            ptr = ptr->next;
        }

        ptr = dummy->next;
        delete dummy;
        return ptr;
    }
};
