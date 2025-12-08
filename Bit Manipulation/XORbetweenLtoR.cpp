#include <bits/stdc++.h>
using namespace std;

int XORtillN(int n) {
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}

int XORfromLtoR(int L , int R) {
    // Find now XOR from 1-> L and 1->R then do XOR between these 2 :)
    return XORtillN(R) ^ XORtillN(L-1);
}

int main() {
	// your code goes here
	int L,R;
	cin >> L >> R;
	// We can use a Loop to do ^ of all elements from 1 to N -> O(n);
	// but Interviewer :( so use this Trick :)
	cout << XORfromLtoR(L,R);
	return 0;
}

// TC: O(1)
// SC: O(1)