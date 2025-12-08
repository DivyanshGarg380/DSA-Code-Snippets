#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        for(int i = 0; i < subsets ; i++){
            vector<int>list;
            for(int j=0; j<n; j++){
                if(i & ( 1 << j)){
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
}

int main(){
    // Input your example usage here to test the functions.
    return 0;
}

// TC: O(N * 2^N)
// SC: O(N * 2^N)