#include <bits/stdc++.h>
using namespace std;

// Important!! LeetCode - 76 ( Hard )

string minWindow(string s, string t) {
	if(t.size() > s.size()) return "";
	vector<int> need(128, 0), have(128, 0);
	int required = 0;
	for(char c: t){
		if(need[c] == 0) required++;
		need[c]++;
	}
	int formed = 0;
	int l = 0, r = 0;
	int minLen = INT_MAX, start = 0;
	while(r < s.size()){
		char c = s[r];
		have[c]++;
		if(have[c] == need[c] && need[c] > 0) formed++;
		while(formed == required){
			if(r - l + 1 < minLen){
				minLen = r - l + 1;
				start = l;
			}
			// shrink window
			char leftChar = s[l];
			have[leftChar]--;
			
			// If removing break the condition
			if(have[leftChar] < need[leftChar] && need[leftChar] > 0) formed--;
			l++; // shrink from left
		}
		r++; // expand window
	}
	return (minLen == INT_MAX) ? "": s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);
}

// TC: O(N)
// SC: O(1)