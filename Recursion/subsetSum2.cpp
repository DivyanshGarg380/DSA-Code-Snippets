#include <bits/stdc++.h>
using namespace std;
vector<int>ans;;

vector<int> arr = {1,1,2};

void subsetSumII(int index,int sum){
	if(index == arr.size()){
		ans.push_back(sum);
		return;
	}
	subsetSumII(index+1,sum + arr[index]); // Pick element
	subsetSumII(index+1,sum); // Dont pick element
}
int main() {
	// your code goes here
	sort(arr.begin(), arr.end()); // Important to skip duplicates
	int sum = 0;
    subsetSumII(0,sum);
    for (int x : ans) cout << x << " ";
    cout << endl;
	return 0;
}
// TC: O(2ⁿ) 
// SC: O(2ⁿ) (output) + O(n) recursion stack.