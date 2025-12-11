#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int>& nums, int goal){
	if(goal < 0) return 0;
	int  l = 0, sum = 0, count = 0;
	for(int r = 0; r < nums.size(); r++){
		sum += nums[r];
		while(sum > goal){
			sum -= nums[l++];
		}
		count += (r-l+1);
	}
	return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal);
}

// TC: O(N)
// SC: O(1)