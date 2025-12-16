#include<bits/stdc++.h>
using namespace std;

vector<string>ans;
vector<string> restoreIpAddresses(string s) {
    solve(0,0, "",s);
    return ans;
}
void solve(int index, int parts, string curr, string &s){
    // if 4 parts used
    if(parts == 4){
        if(index == s.size()){
            ans.push_back(curr.substr(0,curr.size()-1));
        }
        return;
    }
    // take 1-3 digits
    for(int len = 1; len <= 3; len++){
        if(index + len > s.size()) return;
        string part = s.substr(index, len);
        if(part.size() > 1 && part[0] == '0') return;
        int val = stoi(part);
        if(val > 255) return;
        solve(index+len, parts+1,curr+part+".",s);
    }
}

// TC: O(3^4)
// SC: O(1)