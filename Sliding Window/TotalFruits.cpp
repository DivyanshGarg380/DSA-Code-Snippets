#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>&fruits){
	unordered_map<int,int>mp; // fruit -> freq
	int l = 0, maxLen = 0;
	for(int r = 0; r < fruits.size(); r++){
		mp[fruits[r]]++;
		// shrink if more than 2 types
		while(mp.size() > 2){
			mp[fruits[l]]--;
			if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
			l++;
		}
		maxLen = max(maxLen, r - l + 1);
	}
	return maxLen;
}

int main() {
	// your code goes here
	vector<int> fruits = {1,2,3,2,2};
    cout << totalFruit(fruits);
	return 0;
}

// TC: O(N)
// SC: O(1) -> Map size < 3 always!