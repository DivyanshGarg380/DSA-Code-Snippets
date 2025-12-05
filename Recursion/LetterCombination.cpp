#include <bits/stdc++.h>
using namespace std;

vector<string>keypad = {
	"", // 0
	"", // 1
	"abc", // 2
	"def", // 3
	"ghi", // 4
	"jkl", // 5
	"mno", // 6
	"pqrs", // 7
	"tuv", // 8 
	"wxyz" // 9
};
void solve(int index, string &digits, string &path, vector<string> &ans){
	if(index == digits.size()){
		ans.push_back(path);
		return;
	}
	int digit = digits[index] - '0';
	string letters = keypad[digit];
	for(char ch: letters){
		path.push_back(ch);
		solve(index+1,digits,path,ans);
		path.pop_back(); // backtracking :)
	}
}
vector<string>letterCombinations(string digits){
	vector<string>ans;
	if(digits == "") return ans;
	string path = "";
	solve(0,digits,path,ans);
	return ans;
}
int main() {
	// your code goes here
	string digits;
	cin >> digits;
	vector<string>result = letterCombinations(digits);
	for(string s: result){
		cout << s << " ";
	}
	return 0;
}
// TC: O(4^n)
// SC: O(n+4^n);