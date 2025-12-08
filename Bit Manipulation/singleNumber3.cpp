#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums, int n) {
	long long xorr = 0;
    for (int num : nums) xorr ^= num;
    if (xorr == 0) return {}; 
    long long rightMost = xorr & (-xorr);
    int bucket1 = 0, bucket2 = 0;
    for (int num : nums) {
        if (num & rightMost) bucket1 ^= num;
        else bucket2 ^= num;
    }
    return {bucket1, bucket2};
}

int main() {
	// your code goes here
	int N;
	cin >> N;
	vector<int>arr;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	vector<int>res = singleNumber(arr,N);
	for(int x : res){
		cout << x << " ";
	}
	return 0;
}

// TC: O(2N)
// SC: O(1)