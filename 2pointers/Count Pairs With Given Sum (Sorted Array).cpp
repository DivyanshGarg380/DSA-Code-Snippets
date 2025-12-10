#include <bits/stdc++.h>
using namespace std;

// Array is already sorted !

int pairsWithSum(vector<int>&arr, int target){
	set<vector<int>>st;
	int l = 0, r = arr.size()-1;
	while(l<r){
		int sum = arr[l] + arr[r];
		if(sum == target){ st.insert({arr[l],arr[r]});
			l++;
			r--;
		}
		else if(sum < target) l++;
		else r--;
	}
	return st.size();
}

int main() {
	// your code goes here
	vector<int> arr = {1, 2, 3, 5, 5, 7};
    int target = 8;

    cout << pairsWithSum(arr, target);
	return 0;
}
// THIS COUNTS UNIQUE PAIRS ONLY 
// This is approach 1 using a set -> TC: O(N + K*logN) where K -> No. of pairs , SC: O(K)... Ok but not ideal.
// Approach 2 

#include <bits/stdc++.h>
using namespace std;

int pairsWithSum(vector<int>&arr, int target){
	int l=0, r = arr.size() - 1;
	int count = 0;
	while(l<r){
		int sum = arr[l] + arr[r];
		if(sum < target) l++;
		else if(sum > target) r--;
		else{
			if(arr[l] == arr[r]) // all nums between these 2 are same
			{
				int n = l - r + 1;
				count += n*(n-1)/2;
				break;
			}else{
				int leftVal = arr[l];
				int rightVal = arr[r];
				int leftCount = 0;
				int rightCount = 0;
				while(l < r && arr[l] == leftVal){
					leftCount++;
					l++;
				}
				while(r >= l && arr[r] == rightVal){
					rightCount++;
					r--;
				}
				count += leftCount*rightCount;
			}
		}
	}
	return count;
}

int main() {
	// your code goes here
	vector<int> arr = {1, 2, 3, 5, 5, 7};
    int target = 8;

    cout << pairsWithSum(arr, target);
	return 0;
}

// TC: O(n) and SC: O(1);