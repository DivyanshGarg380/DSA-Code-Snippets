#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(vector<int>&arr, int target){
	int l = 0, sum = 0;
	int minLen = INT_MAX;
	for(int r = 0; r < arr.size(); r++){
		sum += arr[r];
		while(sum >= target){
			minLen = min(minLen, r - l + 1);
			sum -= arr[l++];
		}
	}
	return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
	// your code goes here
	vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(nums, target);
	return 0;
}

// TC: O(N)
// SC: O(1)