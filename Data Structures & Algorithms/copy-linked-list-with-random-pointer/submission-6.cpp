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
        return onePassNoExtraSpace(head);
    }

private:
    Node* onePassNoExtraSpace(Node* head) {
        if (!head) {
            return nullptr;
        }

        // Create interleaving list
        // A -> A' -> B -> B' -> ...
        Node* ptr = head;
        while (ptr) {
            Node* next = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = next;
            ptr = next;
        }

        // Link random
        Node* headCopy = head->next;
        ptr = head;
        while (ptr) {
            if (ptr->random) {
                // ptr->next is the copy
                ptr->next->random = ptr->random->next;
            }

            ptr = ptr->next->next;
        }

        // Separate 2 lists
        // A -> A' -> B -> B' -> ...
        ptr = head;
        while (ptr) {
            Node* copy = ptr->next;
            ptr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }

            ptr = ptr->next;
        }

        return headCopy;
    }

    Node* onePassHashmap(Node* head) {
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
