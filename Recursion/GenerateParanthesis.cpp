#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, int n, string &path, vector<string>&ans){
	if(path.size() == 2*n){
		ans.push_back(path);
		return;
	}
	if(open < n){ // adding '(' if possible
		path.push_back('(');
		solve(open+1,close,n,path,ans);
		path.pop_back(); // backtrack
	}
	if(close < open){ // we dont do < n here because we want only valid parentheses. by doing < n we get all combinations :)
		path.push_back(')'); // adding ')' is possible
		solve(open,close+1,n,path,ans);
		path.pop_back(); // backtrack
	}
}

vector<string>generateParenthesis(int n){
	vector<string>ans;
	string path = "";
	solve(0,0,n,path,ans);
	return ans;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<string>result = generateParenthesis(n);
	for(string s: result){
		cout << s << endl;
	}
	return 0;
}

// TC: C_n ≈ 4^n / (n^(3/2))
// SC: O(n) for recursion stack
// where C_n is the nth Catalan number