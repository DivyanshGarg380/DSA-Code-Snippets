#include <bits/stdc++.h>
using namespace std;
bool isSafe(int row, int col, vector<string>&board, int n){
	// col check
	for(int i=0;i<row;i++){
		if(board[i][col] == 'Q') return false;
	}
	// Left Diagonal
	int i = row - 1 , j = col - 1;
	while(i >= 0 && j >= 0){
		if(board[i][j] == 'Q') return false;
		i--;j--;
	}
	// Right Diagonal
	i = row - 1; j = col + 1;
	while(i>=0 && j < n){
		if(board[i][j] == 'Q') return false;
		i--; j++;
	}
	return true;
}
void solve(int row, vector<string>&board, int n, vector<vector<string>>&ans){
	if(row == n){
		ans.push_back(board);
		return;
	}
	for(int col=0;col<n;col++){
		if(isSafe(row,col,board,n)){
			board[row][col] = 'Q';
			solve(row+1,board,n,ans);
			board[row][col] = '.'; // backtrack
		}
	}
}
vector<vector<string>> solveNQueens(int n){
	vector<vector<string>> ans;
	vector<string>board(n,string(n,'.'));
	solve(0,board,n,ans);
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<vector<string>> ans = solveNQueens(N);
	for(auto &sol : ans){
		for(auto &row : sol){
			cout << row << endl;
		}
		cout << endl;
	}
	return 0;
}

// TC: O(N!*N)
// SC: O(N^2)

/*
Short Note: Optimizing N-Queen Using Hashing (O(1) Safety Check)

In the basic N-Queen solution, checking whether a queen can be placed at position (row, col) requires scanning the entire column and both diagonals, which takes O(N) time.
This makes the overall time complexity O(N! × N).

To optimize this, we use three helper arrays to keep track of which columns and diagonals are already occupied by queens. This allows us to check safety in O(1) time without scanning:

Column array: col[c]

col[c] = 1 means column c already has a queen.

Left-to-right diagonal array: diag1[row + col]

All cells on the same ↘ diagonal have the same value of (row + col).

Right-to-left diagonal array: diag2[row - col + (n-1)]

All cells on the same ↙ diagonal have the same value of (row - col)
(offset by n-1 to avoid negative indices).

Using these arrays, we can check if a position (row, col) is safe by:

if column free AND diag1 free AND diag2 free → safe


No loops are required, so each safety check becomes O(1).

This reduces the overall time complexity to O(N!), which is the best possible for backtracking in N-Queens. The space complexity stays O(N) because we only store 3 arrays of size O(N) and the chessboard.
*/