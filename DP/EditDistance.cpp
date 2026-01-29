#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2);
    }

    int solve(int i, int j, string &word1, string &word2){
        if(i == n) return m - j;
        if(j == m) return n - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i+1, j+1, word1, word2);
        }

        int insert = 1 + solve(i, j + 1, word1, word2);
        int del = 1 + solve(i+1, j, word1, word2);
        int replace = 1 + solve(i+1, j + 1, word1, word2);

        return dp[i][j] = min({insert, del, replace});
    }
};

// TC: O(n*m)
// SC: O(n*m) + O(n+m) for recursion stack