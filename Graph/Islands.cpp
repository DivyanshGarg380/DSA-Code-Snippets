#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>&grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delRow[] = {-1, 1, 0, 0};
            int delCol[] = {0, 0, -1, 1};

            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};

// TC: O(N*M)
// SC: O(N*M) + O(min(N,M)) for queue