#include <bits/stdc++.h>
using namespace std;

int candies(vector<int>&rating){
	int n = rating.size();
	vector<int>candies(n,1);
	// Pass 1: L -> R
	for(int i=1; i<n; i++){
		if(rating[i] > rating[i-1]){
			candies[i] = candies[i-1] + 1;
		}
	}
	// Pass 2: R -> L
	for(int i=n-2; i>=0; i--){
		if(rating[i] > rating[i+1]){
			candies[i] = max(candies[i],candies[i+1]+1);
		}
	}
	int total = 0;
	for(int x: candies) total += x;
	return total;
}

int main() {
	// your code goes here
	int m;
	cin >> m;
	vector<int>rating(m);
	for(int i=0;i<m;i++){
		cin >> rating[i];
	}
	int totalCandiesGiven = candies(rating);
	cout << totalCandiesGiven;
	return 0;
}

// TC: O(N)
// SC: O(N)