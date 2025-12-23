#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = { -1, 0, 1, 0};
        int delCol[] = { 0, 1, 0, -1};
        dfs(sr,sc,ans,image,color,delRow,delCol,initColor);
        return ans;
    }
    void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>>&image, int color, int delRow[], int delCol[], int initialColor){
        ans[sr][sc] = color;
        int n = image.size(), m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, color, delRow, delCol,initialColor);
            } 
        }
    }
};

// TC: O(N*M)
// SC: O(N*M) for recursion stack in worst case