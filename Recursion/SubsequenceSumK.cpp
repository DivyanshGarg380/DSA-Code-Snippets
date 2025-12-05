#include <bits/stdc++.h>
using namespace std;
vector<int> arr = {0,1,1,2,4,2};
void print(vector<int>&toPrint){
    for (int x : toPrint) {
        cout << x << " ";
    }
    cout << endl;
}
void subsequenceSumEqualK(vector<int>&newArr,int index,int sum,int buildingSum){
	if(index >= arr.size()){
		if(buildingSum == sum){
			print(newArr);
			return;
		}else{
			return;
		}
	}
	newArr.push_back(arr[index]);
	subsequenceSumEqualK(newArr,index+1,sum,buildingSum+arr[index]);
	newArr.pop_back();
	subsequenceSumEqualK(newArr,index+1,sum,buildingSum);
}
int main() {
	// your code goes here
	vector<int>temp;
	int sum = 2;
	subsequenceSumEqualK(temp,0,2,0);
	return 0;
}
// TC: o(N*2^N) SC: o(N)