#include <bits/stdc++.h>
using namespace std;

int shortestJobFirst(vector<int>&process){
	sort(process.begin(),process.end());
	int m = process.size();
	int waitTime = 0, time = 0;
	for(int i=0;i<m;i++){
		waitTime += time;
		time += process[i];
	}
	return waitTime/m;
	
}

int main() {
	// your code goes here
    int m;
    cin >> m;
    vector<int>process(m);
    for(int i=0;i<m;i++){
    	cin >> process[i];
    }
    int avgTime = shortestJobFirst(process);
    cout << avgTime;
	return 0;
}

// TC: O(nlogn + n)
// SC: O(1)