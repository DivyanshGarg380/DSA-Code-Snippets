#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right) return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    for(int i = 1; i < left; i++){
        prev = prev->next;
    }
    ListNode* curr = prev->next;
    for(int i = 0; i < right - left; i++){
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return dummy.next;
}

// Can also swap node values --> Clarify with interviewer first 

// TC: O(N)
// SC: O(1)