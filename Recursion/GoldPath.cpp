#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>&grid, int r, int c, int n, int m){
	if(r<0 || c<0 || r >= n || c >= m || grid[r][c] == 0) return 0;
	int gold = grid[r][c];
	grid[r][c] = 0; // visited;
	int best = 0;
	best = max(best,dfs(grid,r+1,c,n,m));
	best = max(best,dfs(grid,r-1,c,n,m));
	best = max(best,dfs(grid,r,c+1,n,m));
	best = max(best,dfs(grid,r,c-1,n,m));
	grid[r][c] = gold; // backtrack
	return gold + best;
}

int getMaximumGold(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] > 0){
				ans = max(ans,dfs(grid,i,j,n,m));
			}
		}
	}
	return ans;
}

int main() {
	// your code goes here
	int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    cout << getMaximumGold(grid);
    return 0;
}