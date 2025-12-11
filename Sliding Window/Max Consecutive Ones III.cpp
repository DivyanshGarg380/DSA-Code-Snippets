#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
   int l =0, zeroes = 0, maxLen = 0;
   for(int r = 0; r < nums.size(); r++){
   	if(nums[r] == 0) zeroes++;
   	while(zeroes > k){
   		if(nums[l] == 0){
   			zeroes--;
   		}
   		l++;
   	}
	maxLen = max(maxLen, r - l + 1);
   }
   return maxLen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << longestOnes(nums, k);
}

// TC: O(N)
// SC: O(1)