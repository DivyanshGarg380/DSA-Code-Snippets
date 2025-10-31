#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases

    while (t > 0) {
        int n;
        cin >> n;  // Read input value n for each test case

        int ans = 0;  // Variable to store the answer

        // If n is 1 or 2, fixed answer is 200
        if (n <= 2) {
            ans = 200;
        }
        // Otherwise, answer is n multiplied by 100
        else {
            ans = n * 100;
        }

        cout << ans << endl;  // Print the result
        t--;  // Decrease test case count
    }
}
