#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>&intervals){
	sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
		return a[1] < b[1];	
	});
	int count = 0;
	int end = intervals[0][1];
	for(int i = 1; i<intervals.size();i++){
		if(intervals[i][0] < end){
			count++; // overlapping found
		}else{
			end = intervals[i][1];
		}
	}
	return count;
}

int main() {
	// your code goes here
	vector<vector<int>> intervals = {{1,2},{2,3}};
	int count = eraseOverlapIntervals(intervals);
	cout << count;
	return 0;
}

// Time Complexity: O(N log N + N)
// Space Complexity: O(1)