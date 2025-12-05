#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int left, int right){
	while(left < right){
		if(s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}
void solve(int start, string &s, vector<string>&path, vector<vector<string>> &ans){
	if(start == s.size()){
		ans.push_back(path);
		return;
	}
	for(int end = start; end < s.size(); end++){
		if(isPalindrome(s,start,end)){
			string substr = s.substr(start,end-start+1);
			path.push_back(substr);
			solve(start+1,s,path,ans);
			path.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;

    solve(0, s, path, ans);

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<vector<string>> result = partition(s);

    for(auto &vec : result) {
        for(auto &str : vec)
            cout << str << " ";
        cout << endl;
    }

    return 0;
}
//TC: O(N * 2^N)
//SC: O(N)