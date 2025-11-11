
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeDummy(0), afterDummy(0);
        ListNode *before = &beforeDummy, *after = &afterDummy;
        while (head) {
            if (head->val < x) before->next = head, before = before->next;
            else after->next = head, after = after->next;
            head = head->next;
        }
        after->next = nullptr;
        before->next = afterDummy.next;
        return beforeDummy.next;
    }
};
