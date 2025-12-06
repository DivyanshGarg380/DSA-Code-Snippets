// Approach 1: Recursion
#include <bits/stdc++.h>
using namespace std;

int countJumps(int index, int jumps, vector<int>&jump){
	if(index >= jump.size()-1) return jumps;
	int mini = INT_MAX;
	for(int i=1;i<=jump[index];i++){
		mini = min(mini,countJumps(index+i,jumps+1,jump));
	}
	return mini;
}

int jumpGameII(vector<int>&jump){
	int m = jump.size();
	int index = 0;
	int jumps = 0;
	return countJumps(index,0,jump);
}

int main() {
	// your code goes here
    int m;
    cin >> m;
    vector<int>jump(m);
    for(int i=0;i<m;i++){
    	cin >> jump[i];
    }
    int jumpCounts = jumpGameII(jump);
    cout << jumpCounts;
	return 0;
}

// TC: O(n^n)
// SC: O(n)

// Approach 2: Greedy + sliding window
#include <bits/stdc++.h>
using namespace std;

int jumpGameII(vector<int>&jump){
	int jumps = 0, l = 0, r = 0;
	while(r < jump.size()-1){
		int farthest = 0;
		for(int i = l; i<=r ; i++){
			farthest = max(farthest, i + jump[i]);
		}
		l = r + 1;
		r = farthest;
		jumps++;
	}
	return jumps;
}

int main() {
	// your code goes here
    int m;
    cin >> m;
    vector<int>jump(m);
    for(int i=0;i<m;i++){
    	cin >> jump[i];
    }
    int jumpCounts = jumpGameII(jump);
    cout << jumpCounts;
	return 0;
}
// TC: O(n)
// SC: O(1)