#include <bits/stdc++.h>
using namespace std;

bool solve(int start, string &s, unordered_set<string>&dict){
	if(start == s.size()) return true;
	for(int end = start; end < s.size(); end++){
		string part = s.substr(start,end-start+1);
		if(dict.count(part)){
			if(solve(end+1,s,dict)) return true;
		}
	}
	return false;
}

bool wordBreak(string &s, vector<string>&wordDict){
	unordered_set<string>dict(wordDict.begin(),wordDict.end());
	return solve(0,s,dict);
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string>dict(n);
	for(int i=0;i<n;i++){
		cin >> dict[i];
	}
	if(wordBreak(s,dict)) cout << "True\n";
	else cout << "False\n";
	return 0;
}
// TC: O(2ⁿ)
// SC: o(n) for recursion stack