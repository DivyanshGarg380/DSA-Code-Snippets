#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1; // handles subarrays starting from the beginning
        for(int num: nums){
            prefixSum += num;
            int mod = prefixSum % k;
            if(mod < 0) mod += k; // incase of negative remainders
            if(mp.find(mod) != mp.end()){
                count += mp[mod];
                mp[mod] += 1;
            }else{
                mp[mod] = 1;
            }
        }
        return count;
    }
};

// TC: O(N)
// SC: O(K)