#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> arr = {10,1,2,7,6,1,5};

void combinationSumII(vector<int>&newArr,int index,int target){
	if(target == 0){
		ans.push_back(newArr);
		return;
	}
	for(int i=index; i< arr.size(); i++){
		if(i > index && arr[i] == arr[i-1]) continue;
		if(arr[i] > target) break;
		newArr.push_back(arr[i]);
		combinationSumII(newArr,i+1,target-arr[i]);
		newArr.pop_back();
	}
}
int main() {
	// your code goes here
	sort(arr.begin(), arr.end()); // Important to skip duplicates
	vector<int>temp;
	int target = 8;
    combinationSumII(temp,0,target);
    for (auto &v : ans) {
       for (int x : v) cout << x << " ";
       cout << endl;
    }
	return 0;
}
// TC: O(O(2^N) SC: o(N)
