#include <bits/stdc++.h>
using namespace std;

/*
    GOOD LEVEL QUESTION!! 
*/

// Approach 1: Using Buckets
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(valueDiff < 0) return false;
        unordered_map<long long, long long>bucket;
        long long w = (long long)valueDiff + 1;
        for(int i=0; i<nums.size(); i++){
            long long x = nums[i];
            long long id = x >= 0 ? x / w : (x+1)/w-1;
            if(bucket.count(id)) return true;
            if(bucket.count(id-1) && abs(x - bucket[id-1]) <= valueDiff) return true;
            if (bucket.count(id + 1) && abs(x - bucket[id + 1]) <= valueDiff) return true;
            bucket[id] = x;
            if(i >= indexDiff){
                long long old = nums[i-indexDiff];
                long long oldId = old >= 0 ? old / w : (old + 1)/ w - 1;
                bucket.erase(oldId);
            }

        }
        return false;
    }
};

// TC: O(N)
// SC: O(K) 


// Approach 2: Sets
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> s;

    for (int i = 0; i < nums.size(); i++) {
        auto it = s.lower_bound((long long)nums[i] - t);
        if (it != s.end() && *it <= (long long)nums[i] + t)
            return true;

        s.insert(nums[i]);

        if (i >= k)
            s.erase(nums[i - k]);
    }
    return false;
}

// TC: O(NlogK)
// SC: O(K)