#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>&arr){
	int n = arr.size();
	int k = 0;
	for(int j = 0; j < n ; j++){
		if(arr[j] != 0){
			swap(arr[k],arr[j]);
			k++;
		}
	}
}

int main() {
	// your code goes here
	vector<int> nums = {0, 0, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums) cout << x << " ";
	return 0;
}

// TC: O(N)
// SC: O(1)