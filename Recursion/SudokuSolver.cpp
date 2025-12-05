#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>&board, int row, int col, char ch){
	// check row and cols first 
	for(int i=0;i<9;i++){
		if(board[row][i] == ch) return false;
		if(board[i][col] == ch) return false;
	}
	// check the 3x3 subgrid
	int startRow = (row/3)*3;
	int startCol = (col/3)*3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[startRow+i][startCol+j] == ch){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(vector<vector<char>>&board){
	for(int row = 0; row < 9; row ++){
		for(int col = 0; col < 9; col++){
			if(board[row][col] == '.'){
				for(char ch = '1'; ch <= '9'; ch++){
					if(isValid(board,row,col,ch)){
						board[row][col] = ch;
						if(solveSudoku(board)) return true;
						board[row][col] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	vector<vector<char>> board(9,vector<char>(9));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> board[i][j];
		}
	}
	if(solveSudoku(board)){
		cout << "\nSolved Sudoku:\n";
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
        	}
            cout << endl;
		}
	}else {
        cout << "No solution exists\n";
    }
    return 0;
}

// TC: O(9^81) 
// SC: O(1) as we are not using any extra space except for the input