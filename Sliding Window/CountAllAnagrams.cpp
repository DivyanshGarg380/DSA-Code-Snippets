#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	int n = s.size(), m = p.size();
	if(m>n) return {};
	vector<int> freqP(26,0), freqS(26,0);
	vector<int> ans;
	for(char c: p) freqP[c-'a']++;
	// First Window now
	for(int i=0;i<m;i++){
		freqS[s[i]-'a']++;
	}
	if(freqS == freqP) ans.push_back(0);
	// Slide the window else
	for(int i=m;i<n;i++){
		freqS[s[i]-'a']++;
		freqS[s[i-m]-'a']--;
		if(freqS == freqP) ans.push_back(i-m+1);
	}
	return ans;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s, p);
    for (int x : ans) cout << x << " ";
}

// TC: O(N)
// SC: O(1)