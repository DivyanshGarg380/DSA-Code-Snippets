#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag (3 Pointers) !!

void sortColors(vector<int>&arr){
	int n = arr.size();
	int low = 0, mid = 0, high = n-1;
	while(mid <= high){
		if(arr[mid] == 0){
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		}else if(arr[mid] == 1){
			mid++;
		}else{ // its == 2
			swap(arr[mid], arr[high]);
			high--;
		}
	}
	
}

int main() {
	// your code goes here
	vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for (int x : nums) cout << x << " ";
	return 0;
}

// TC: O(N)
// SC: O(1)