#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>&board, string &word, int row, int col, int index){
	if(index == word.size()) return true;
	// Boundary checks
	if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col] != word[index])
		return false;
	char temp = board[row][col];
	board[row][col] = '#'; // visited ( just like in DFS in graphs)
	bool found = dfs(board,word,row+1,col,index+1) || 
				 dfs(board,word,row-1,col,index+1) ||
				 dfs(board,word,row,col+1,index+1) ||
				 dfs(board,word,row,col-1,index+1);
	board[row][col] = temp; // undo visit mark -> Backtrack
	return found;
}

bool exist(vector<vector<char>>&board, string &word){
	int m = board.size();
	int n = board[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(board[i][j] == word[0]){
				if(dfs(board,word,i,j,0)) return true;
			}
		}
	}
	return false;
}

int main() {
	// your code goes here
	int m,n;
	cin >> m >> n;
	vector<vector<char>> board(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> board[i][j];
		}
	}
	string word;
	cin >> word;
	if(exist(board,word)){
		cout << "Word Exists";
	}else{
		cout << "Word Not Found\n";
	}
	return 0;
}
// TC -> O(m × n × 4^L) where L is length of the word
// SC -> O(L) for recursion stack