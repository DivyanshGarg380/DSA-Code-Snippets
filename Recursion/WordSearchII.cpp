#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>&board, string &word, int i, int j, int index){
	if(index == word.size()) return true;
	if(i<0 || j <0 || i >= board.size() || j >= board.size()) return false;
	if(board[i][j] != word[index]) return false;
	
	char temp = board[i][j];
	board[i][j] = '#'; // visited;
	bool found = dfs(board,word,i+1,j,index+1)||
				 dfs(board,word,i-1,j,index+1)||
				 dfs(board,word,i,j+1,index+1)||
				 dfs(board,word,i,j-1,index+1);
	board[i][j] = temp; // backtrack
	return found;	
}

bool exist(vector<vector<char>>&board, string &word){
	int m = board.size(), n = board[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(board[i][j] == word[0]){
				if(dfs(board,word,i,j,0)) return true;
			}
		}
	}
	return false;
}

vector<string>findWords(vector<vector<char>>&board,vector<string>&words){
	vector<string>result;
	for(string &w : words){
		if(exist(board,w)){
			result.push_back(w);
		}
	}
	return result;
}

int main() {
	// your code goes here
	int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int k;
    cin >> k;
    vector<string> words(k);
    for(int i = 0; i < k; i++) {
        cin >> words[i];
    }
    vector<string> ans = findWords(board, words);
    for(string &w : ans) {
        cout << w << " ";
    }
    return 0;
}
// TC: O(K × m × n × 4^L) where K is number of words and L is length of longest word
// SC: O(L) for recursion stack

// Can be optimized using TRIE -> To solve later when I learn it :)