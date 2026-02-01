#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> ds;
        findPalindromes(0, s, ans, ds, dp);
        return ans;
    }

    void findPalindromes(int index, string& s, vector<vector<string>>& ans, 
                         vector<string>& ds, vector<vector<bool>>& dp){
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            if(dp[index][i]){  
                ds.push_back(s.substr(index, i-index+1));
                findPalindromes(i+1, s, ans, ds, dp);
                ds.pop_back();
            }
        }
    }
};

// TC: O(n^2) for palindrome DP + O(2^n) for backtracking
// SC: O(n^2) for both