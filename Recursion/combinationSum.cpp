#include <bits/stdc++.h>
using namespace std;
vector<int> arr = {2,3,6,7};
void print(vector<int>&toPrint){
    for (int x : toPrint) {
        cout << x << " ";
    }
    cout << endl;
}
void combinationSum(vector<int>&newArr,int index,int target){
	if(index == arr.size()){
		if(target == 0){
			print(newArr);
		}
		return;
	}
	if(arr[index] <= target){ // Include the element
		newArr.push_back(arr[index]);
		combinationSum(newArr,index,target-arr[index]);
		newArr.pop_back();
	}
	combinationSum(newArr,index+1,target); // Skip/Exclude the element
}
int main() {
	// your code goes here
	vector<int>temp;
	int target = 7;
    combinationSum(temp,0,target);
	return 0;
}
// TC: O(2^(T / min(arr))) SC: o(T)
// T -> Target value