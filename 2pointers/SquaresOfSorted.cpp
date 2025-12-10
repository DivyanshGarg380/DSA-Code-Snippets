#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>&arr){
	int n = arr.size();
	vector<int>res(n);
	int l = 0, r = n - 1, k = n - 1;
	while(l<=r){
		if(abs(arr[l]) > abs(arr[r])){
			res[k] = arr[l]*arr[l];
			l++;
		}else{
			res[k] = arr[r]*arr[r];
			r--;
		}
		k--;
	}
	return res;
}

int main() {
	// your code goes here
	vector<int> arr = {-1,-1,0,3,10};
    vector<int> result = sortedSquares(arr);
    for (int x : result) cout << x << " ";
	return 0;
}

// TC: O(N)
// SC: O(N)