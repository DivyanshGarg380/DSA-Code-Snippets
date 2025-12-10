#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>&arr){
	int n = arr.size();
	if(n == 0) return 0;
	int k = 0;
	for(int j=1;j<arr.size();j++){
		if(arr[j] != arr[k]){
			k++;
			arr[k] = arr[j];
		}
	}
	return k + 1;
}

int main() {
	// your code goes here
	vector<int> arr = {1, 2, 3, 5, 5, 7};
    cout << removeDuplicates(arr);
	return 0;
}

// TC: O(N)
// SC: O(1)