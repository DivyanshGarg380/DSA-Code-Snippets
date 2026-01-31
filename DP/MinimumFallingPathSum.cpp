#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.assign(n, vector<int>(n, -1));
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            ans = min(ans, solve(0, i, matrix));
        }
        return ans;
    }

    int solve(int i, int j, vector<vector<int>> &matrix){
        if(j < 0 || j >= n) return 1e9;
        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i+1, j, matrix);
        int left = solve(i+1, j-1, matrix);
        int right = solve(i+1, j+1, matrix);

        return dp[i][j] = matrix[i][j] + min({down, left, right});
    }
};

// TC: O(n^2)
// SC: O(n^2) + O(n) for recursion stack

/* Appraoch 2 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int down = dp[i+1][j];
                int left = (j>0) ? dp[i+1][j-1] : 1e9;
                int right = (j<n-1) ? dp[i+1][j+1] : 1e9;

                dp[i][j] = matrix[i][j] + min({down, left, right});
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

// TC: O(n^2)
// SC: O(n^2)

/* Appraoch 3 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> front = matrix[n-1];
        vector<int> cur(n);

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int down = front[j];
                int left = (j > 0) ? front[j-1] : 1e9;
                int right = (j < n - 1) ? front[j+1] : 1e9;

                cur[j] = matrix[i][j] + min({down, left, right});
            }
            front = cur;
        }
        return *min_element(front.begin(), front.end());
    }
};

// TC: O(n^2)
// SC: O(n)