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
        unordered_map<Node*, Node*> oldToNew = {{nullptr, nullptr}};
        Node* ptr = head;
        while (ptr) {
            if (oldToNew.find(ptr) == oldToNew.end()) {
                oldToNew[ptr] = new Node(ptr->val);
            }

            if (oldToNew.find(ptr->next) == oldToNew.end()) {
                oldToNew[ptr->next] = new Node(ptr->next->val);
            }
            oldToNew[ptr]->next = oldToNew[ptr->next];

            if (oldToNew.find(ptr->random) == oldToNew.end()) {
                oldToNew[ptr->random] = new Node(ptr->random->val);
            }
            oldToNew[ptr]->random = oldToNew[ptr->random];

            ptr = ptr->next;
        }

        return oldToNew[head];
    }
};
