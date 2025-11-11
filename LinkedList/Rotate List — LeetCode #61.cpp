
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode* curr = head;
        int len = 1;
        while (curr->next) {
            curr = curr->next;
            len++;
        }
        curr->next = head; // Make it circular
        k %= len;
        int steps = len - k;
        while (steps--) curr = curr->next;
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }
};
