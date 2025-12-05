#include <bits/stdc++.h>
using namespace std;
vector<int> arr = {3,1,2};
void print(vector<int>&toPrint){
	cout << "[";
    for (int x : toPrint) {
        cout << x << " ";
    }
    cout << "]\n";
}
void subsequence(vector<int>&newArr,int index){
	if(index >= arr.size()){
		print(newArr);
		return;
	}
	newArr.push_back(arr[index]);
	subsequence(newArr,index+1);
	newArr.pop_back();
	subsequence(newArr,index+1);
}
int main() {
	// your code goes here
	vector<int>temp;
	subsequence(temp,0);
	return 0;
}
// TC: o(N*2^N) SC: o(N)