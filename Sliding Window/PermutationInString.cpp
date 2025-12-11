#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
	if(s1.size() > s2.size()) return false;
	vector<int> freq1(26,0), freq2(26,0);
	for(char c : s1) freq1[c-'a']++;
	int k = s1.size();
	for(int i=0; i<k; i++) freq2[s2[i]-'a']++;
	if(freq1 == freq2) return true;
	// slide window else
	for(int i=k; i< s2.size(); i++){
		freq2[s2[i]-'a']++; // Include new char
		freq2[s2[i-k]-'a']--; // remove outgoing char
		if(freq1 == freq2) return true;
	}
	return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaaoo";

    cout << (checkInclusion(s1, s2) ? "true" : "false");
}

// TC: O(N)
// SC: O(26)