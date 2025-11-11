class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for (auto l : lists)
            if (l) pq.push({l->val, l});
        ListNode dummy, *tail = &dummy;
        while (!pq.empty()) {
            auto [val, node] = pq.top(); pq.pop();
            tail->next = node; tail = node;
            if (node->next) pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};
