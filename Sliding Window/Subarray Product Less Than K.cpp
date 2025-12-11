#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>&arr, int k) {
    if( k <= 1) return 0;
    int l = 0;
    long long prod = 1;
    int count = 0;
    for(int r = 0; r < arr.size(); r++){
    	prod *= arr[r];
    	while(prod >= k){
    		prod /= arr[l++];
    	}
    	count += (r-l+1);
    }
    return count;
}

int main() {
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;

    cout << numSubarrayProductLessThanK(arr, k);
}

// TC: O(N)
// SC: O(1)