#include <bits/stdc++.h>
using namespace std;

int assignCookies(vector<int>&greed, vector<int>&size){
	int m = greed.size(), n = size.size();
	int l = 0, r = 0;
	sort(greed.begin(),greed.end());
	sort(size.begin(),size.end());
	while(l<m && r<n){
		if(greed[l] <= size[r]){
			l++;
		}
		r++;
	}
	return l;
}

int main() {
	// your code goes here
    int m,n;
    cin >> m >> n;
    vector<int>greed(m),size(n);
    for(int i=0;i<m;i++){
    	cin >> greed[i];
    }
    for(int i=0;i<n;i++){
    	cin >> size[i];
    }
    int totalKidsSatisfied = assignCookies(greed,size);
    cout << totalKidsSatisfied;
	return 0;
}

// TC: O(mlogm + nlogn)
// SC: O(1)
