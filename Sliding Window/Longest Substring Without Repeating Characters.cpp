#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
	vector<int> last(256,-1); // to store last seen index
	int l = 0, maxLen = 0;
	for(int r = 0; r < s.size(); r++){
		char c = s[r];
		// if char is inside the current window
		if(last[c] >= l){
			l = last[c] + 1;
		}
		last[c] = r; 
		maxLen = max(maxLen,r-l+1);
	}
	return maxLen;
}

int main() {
	// your code goes here
	string s = "abcabcbb";
	cout << lengthOfLongestSubstring(s);
	return 0;
}

// TC: O(N)
// SC: O(1) -> cause vector size is defined constant