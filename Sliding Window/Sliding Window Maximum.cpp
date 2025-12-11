#include <bits/stdc++.h>
using namespace std;

// Leetcode - 239 Hard !!

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> dq; // to store indices
	vector<int>ans;
	for(int i=0; i<nums.size(); i++){
		// remove indices out of Window
		if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
		// Maintian decreasing order in deque
		while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
		dq.push_back(i);
		// Start recording result once window reaches size == k
		if(i >= k - 1) ans.push_back(nums[dq.front()]);
	}
	return ans;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums, k);
    for (int x : res) cout << x << " ";
}

// TC: o(N)
// SC: O(K)