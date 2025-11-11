
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes and insert between originals
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextNode;
            curr = nextNode;
        }

        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate both lists
        curr = head;
        Node* newHead = head->next;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next) copy->next = copy->next->next;
            curr = curr->next;
        }

        return newHead;
    }
};
