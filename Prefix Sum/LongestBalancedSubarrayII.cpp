#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        // This array will store contribution of each index:
        // +1  -> if this index is FIRST occurrence (for current left boundary) and even
        // -1  -> if first occurrence and odd
        //  0  -> otherwise (duplicate occurrence inside window)
        vector<int> balance(n, 0);

        // Since nums[i] <= 1e5, we can use direct indexing.
        // first[x] = index of first occurrence of x
        // in current window [l ... n-1]
        // -1 means not yet present
        vector<int> first(100001, -1);

        int result = 0;

        // We iterate left boundary from right to left.
        // Why?
        // Because when we move l left,
        // that element becomes the new first occurrence
        // of that value in the new window.
        for (int l = n - 1; l >= 0; --l) {

            int x = nums[l];

            // If this value x already had a first occurrence
            // in the window to the right,
            // remove its previous contribution.
            //
            // Because now the FIRST occurrence shifts to index l.
            if (first[x] != -1) {
                balance[first[x]] = 0;  // old first occurrence no longer counts
            }

            // Now mark this index as the first occurrence
            first[x] = l;

            // Assign contribution:
            // +1 if even
            // -1 if odd
            if (x % 2 == 0)
                balance[l] = 1;
            else
                balance[l] = -1;

            // Now we find longest subarray starting at l
            // such that sum(balance[l..r]) == 0

            int sum = 0;

            for (int r = l; r < n; ++r) {
                sum += balance[r];

                // If sum == 0:
                // (#distinct_even) == (#distinct_odd)
                if (sum == 0) {
                    result = max(result, r - l + 1);
                }
            }
        }

        return result;
    }
};

// TC: O(N^2)
// SC: O(N)

// This passes 994/999 Test cases on Leetcode. Optimize with Segment Tree to reduce the inner scan