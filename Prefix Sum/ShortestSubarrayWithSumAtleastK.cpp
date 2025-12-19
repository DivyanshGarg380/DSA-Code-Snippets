#include <bits/stdc++.h>
using namespace std;

/*
    Good Question!!
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n+1,0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        deque<int>dq;
        int ans = n + 1;
        for(int i = 0; i <= n; i++){
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[dq.back()] >= prefix[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return (ans == n + 1) ? -1 : ans;
    }
};

/*
    Cleanup A (front):
    - If prefix[i] − prefix[j] ≥ K, then j gives a valid subarray and can be removed since any future subarray starting at j will be longer.
    
    Cleanup B (back):
    - If a later index has a smaller or equal prefix sum, it dominates earlier larger prefixes (shorter length + larger sum), so the earlier index is useless forever.

*/

// TC: O(N)
// SC: O(2N)