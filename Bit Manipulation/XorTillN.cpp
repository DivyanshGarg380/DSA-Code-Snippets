#include <bits/stdc++.h>
using namespace std;

int XORtillN(int n) {
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}

int main() {
	// your code goes here
	int N;
	cin >> N;
	// We can use a Loop to do ^ of all elements from 1 to N -> O(n);
	// but Interviewer :( so use this Trick :)
	cout << XORtillN(N);
    // Now its o(1) Solution
	return 0;
}

// TC: O(1)
// SC: O(1)