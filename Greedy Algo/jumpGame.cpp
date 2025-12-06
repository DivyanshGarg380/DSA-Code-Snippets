#include <bits/stdc++.h>
using namespace std;

bool jumpGame(vector<int>&jump){
	int m = jump.size();
	int maxIndex = 0;
	for(int i=0;i<m;i++){
		if(i>maxIndex) return false;
		maxIndex = max(maxIndex, i+jump[i]);
	}
	
	return true;
}


int main() {
	// your code goes here
    int m;
    cin >> m;
    vector<int>jump(m);
    for(int i=0;i<m;i++){
    	cin >> jump[i];
    }
    if(jumpGame(jump)) cout <<"true";
    else cout << "false";
	return 0;
}

// TC: O(n)
// SC: O(1)