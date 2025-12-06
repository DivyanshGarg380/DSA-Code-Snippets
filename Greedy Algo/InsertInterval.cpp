#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
	vector<vector<int>>res;
	int i=0, n = intervals.size();
	while(i<n && intervals[i][1] < newInterval[0]){
		res.push_back(intervals[i]);
		i++;
	}
	while(i<n && intervals[i][0] <= newInterval[1]){
		newInterval[0] = min(newInterval[0],intervals[i][0]);
		newInterval[1] = max(newInterval[1],intervals[i][1]);
		i++;
	}
	res.push_back(newInterval);
	while(i<n){
		res.push_back(intervals[i]);
		i++;
	}
	return res;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> result = insert(intervals, newInterval);
    for(auto interval : result){
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}

// Time Complexity: O(N), where N is the number of intervals.
// Space Complexity: O(N), for the output list of intervals.