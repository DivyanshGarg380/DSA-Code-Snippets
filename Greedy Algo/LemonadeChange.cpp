#include <bits/stdc++.h>
using namespace std;

bool assignChange(vector<int>&bills){
	int m = bills.size();
	int fivecounts = 0, tencounts = 0, twentycounts = 0;
	for(int i=0;i<m;i++){
		if(bills[i] == 5) fivecounts++;
		else if(bills[i] == 10){
			tencounts++;
			// Net payable is 5 only so we return 5 
			if(fivecounts >= 1) fivecounts--;
			else return false;
		}else if(bills[i] == 20){
			twentycounts++;
			// Net payable is 5 only so we return 15 = 5 + 5 + 5 , 10 + 5
			// case 1: 10 + 5 -> Greedy choice
			if(tencounts >= 1 && fivecounts >= 1) {
				fivecounts--; tencounts--;
			}
			// case 2: 5 + 5 + 5
			else if(fivecounts >= 3){
				fivecounts -= 3;
			}
			else return false;
		}
	}
	return true;
}

int main() {
	// your code goes here
    int m;
    cin >> m;
    vector<int>bills(m);
    for(int i=0;i<m;i++){
    	cin >> bills[i];
    }
    if(assignChange(bills)) cout << "true";
    else cout << "false";
	return 0;
}

// TC: O(N)
// SC: O(1)