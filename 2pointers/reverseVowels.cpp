#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
	string v = "aeiouAEIOU";
	return v.find(c) != string::npos;
}

string reverseVowels(string s){
	int l = 0, r = s.size()-1;
	while(l<r){
		while(l < r && !isVowel(s[l])) l++;
		while(l < r && !isVowel(s[r])) r--;
		swap(s[l], s[r]);
		l++;
		r--;
	}
	return s;
}

int main() {
	// your code goes here
	string s = "leetcode";
	cout << reverseVowels(s);
	return 0;
}

// TC: O(N)
// SC: O(1)